#include "string.h"
#include "exti.h"
#include "nvic.h"
typedef struct 
{
    volatile unsigned int EVCR;
    volatile unsigned int MAPR;
    volatile unsigned int EXTICR[4];
    volatile unsigned int RESERVED0;
    volatile unsigned int MAPR2;
} AFIO_TypeDef;

/**
 * @brief 初始化KEY1
 *
 * 设置GPIOA0为输入，
 * 设置Key1为输入，
 * 设置PA0为EXTI0的中断源
 *
 * @note
 * 1. 在使用key_init之前，需要先调用cpu_init_enable()来使能CPU
 * 2. 在使用key_init之前，需要先调用AFIO_init()来使能AFIO
 * 3. 在使用key_init之前，需要先调用GPIOA_init()来使能GPIOA
 */
void key_init(void)
{
    AFIO_TypeDef *afio = (AFIO_TypeDef *)0x40010000;
    unsigned int *pRegA;
    /* 使能 GPIO A 的时钟 */
	pRegA = (unsigned int *)(0x40021000 + 0x18);
	*pRegA |= (1 << 2);
 
	/* 设置 Key1 为 输入*/
	pRegA = (unsigned int *)(0x40010800 + 0x00);
	*pRegA = *pRegA & ~(0xF);
	*pRegA |= (1 << 2);

    /* 设置PA0为EXTI0的中断源*/
    afio->EXTICR[0] &= ~0xF;    /* 清空EXTI0的值, 选择 PA0 作为EXTI0*/

}

void EXTI0_IRQHandler(void)
{
    /* 设置GPIOA input data register */
    unsigned int *pRegA = (unsigned int *)(0x40010800 + 0x08);

    if( (*pRegA & (1<<0)) == 0) /* key1 is pressed*/
    {
        puts("key1 is pressed\r\n");
    }
    else
    {
        puts("key1 is not pressed\r\n");
    }

    /* 清除中断挂起 */
    exti_clear_int(0);
    nvic_clear_int(6);
}

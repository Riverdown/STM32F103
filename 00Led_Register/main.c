
#if 0

#include <rge52.h>

sbit LED  = P0^0

void main(void)
{
	P0 = 0XFE;     // 总线操作
	
	LED = 0;       // 位操作
}

#endif



#include "stm32f10x.h"

int main (void)
{
	// 打开 GPIOB 端口的时钟
	RCC_APB2ENR |= 0x01<<3;

	//清空控制PB0的端口位
	GPIOB_CRL &= ~( 0x0F<< (4*0));	
	// 配置PB0为通用推挽输出，速度为10M
	GPIOB_CRL |= (1<<4*0);



	// PB0 输出 低电平
	GPIOB_ODR &= ~(1<<0) ;
}


// 置位   |=   ，清0 &=~
//



// 1、点亮其他的两个LED灯

// 2、写一个简单的延时函数，让灯闪烁


// 72M，HSI = 8M；

void SystemInit(void)
{
	// 函数体为空，目的是为了骗过编译器不报错
}


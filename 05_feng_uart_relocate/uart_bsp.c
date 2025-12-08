#include "uart_bsp.h"

void uart_bsp_init(void)
{
    UART1_TypeDef *uart1 = (UART1_TypeDef *)UART1_BASE_ADDR;
    volatile uint32_t *pReg = (uint32_t *)RCC_APB2ENR_ADDR;
    /* 1. enable uart1 and  port B clock */
    *pReg |= RCC_APB2ENR_UART1EN_Msk | RCC_APB2ENR_IOPAEN_Msk;

    /* 2 set tx/rx pin to alternate function */
    pReg = (uint32_t *)GPIOA_CRH_ADDR;

    /* 2.1 PA9(USART1_TX) */
    *pReg = *pReg & ~(0xF << 4); //clear bits 4-7
    *pReg |= (0x1<<4) | (2<<6);  /* Output mode, max speed 10 MHz; Alternate function output Push-pull */

    /* 2.2 PA10(USART1_RX) */
    *pReg = *pReg & ~(0xF << 8); //clear bits 8-11
    *pReg |= (0x0<<8) | (1<<10); /* Input mode (reset state); Floating input (reset state) */


    /* 3 set uart1 parameters :
     * baudrate = 115200 = 8000000/16/USARTDIV
     * USARTDIV = 4.34
     * DIV_Mantissa = 4
	 * DIV_Fraction / 16 = 0.34
	 * DIV_Fraction = 16*0.34 = 5
     * 真实波特率:
	 * DIV_Fraction / 16 = 5/16=0.3125
	 * USARTDIV = DIV_Mantissa + DIV_Fraction / 16 = 4.3125
	 * baudrate = 8000000/16/4.3125 = 115942
     * 8 data bits, 1 stop bit, no parity
     */

    uart1->CR1 |= (1<<13) | (1<<3) | (1<<2); /* enable uart1, transmitter, receiver */
    uart1->CR1 &= ~(1<<12) & ~(1<<10);      /* 8 data bits, n stop bit, no parity */
    uart1->CR2 &= ~(3<<12);      /* 1 stop bit */

#define DIV_Mantissa 4
#define DIV_Fraction 5
	uart1->BRR = (DIV_Mantissa<<4) | (DIV_Fraction);
}

uint8_t uart_getchar(void)
{
    UART1_TypeDef *uart1 = (UART1_TypeDef *)UART1_BASE_ADDR;
    while((uart1->SR & (1<<5)) == 0); /* wait for rxne */
    return (uint8_t)uart1->DR & 0xFF;
}

uint8_t uart_putchar(uint8_t ch)
{
    UART1_TypeDef *uart1 = (UART1_TypeDef *)UART1_BASE_ADDR;
    while((uart1->SR & (1<<7)) == 0); /* wait for txe */
    uart1->DR = ch;
	
	return ch;
}




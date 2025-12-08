#ifndef __UART_BSP_H__
#define __UART_BSP_H__

#include <stdint.h>

/* macro define */
#define RCC_APB2ENR_ADDR         0x40021018
#define RCC_APB2ENR_UART1EN_Pos  14
#define RCC_APB2ENR_UART1EN_Msk  (1 << RCC_APB2ENR_UART1EN_Pos)
#define RCC_APB2ENR_IOPAEN_Msk   (1 << 2)

#define GPIOA_BASE_ADDR          0x40010800
#define GPIOA_CRH_ADDR           (GPIOA_BASE_ADDR + 0x04)

#define UART1_BASE_ADDR          0x40013800

/* define uart1 register address */
typedef struct 
{
    volatile uint32_t SR;       // status register
    volatile uint32_t DR;       // data register
    volatile uint32_t BRR;      // baud rate register
    volatile uint32_t CR1;      // control register
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;     // guard time and prescaler register
} UART1_TypeDef;

/* function declare */
void uart_bsp_init(void);
uint8_t uart_getchar(void);
uint8_t uart_putchar(uint8_t ch);

#endif

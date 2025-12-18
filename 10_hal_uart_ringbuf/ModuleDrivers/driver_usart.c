#include <string.h>
#include <stdio.h>
#include "driver_usart.h"
#include "ring_buffer.h"

static volatile uint8_t txcmlt_flag = 0;
static volatile uint8_t rxcmlt_flag = 0;


extern UART_HandleTypeDef huart1;
extern ring_buffer_t ring_buffer;
void debugPrint(const char *string) 
{
    uint16_t len = strlen(string);
    
    HAL_UART_Transmit(&huart1, (uint8_t*)string, len, 300);
}

void debugGet(char *string, uint8_t len) 
{
    while(HAL_UART_Receive(&huart1, (uint8_t*)string, len, 300) != HAL_OK);
}

// int fputc(int ch, FILE *f)
// {
//     while(HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, 300) != HAL_OK);
// }

// int fgetc(FILE *f)
// {
//     volatile char ch = 0;
//     while(HAL_UART_Receive(&huart1, (uint8_t*)&ch, 1, 300) != HAL_OK);
//     return ch;
// }

int fputc(int ch, FILE *f)
{
    txcmlt_flag = 0;
    HAL_UART_Transmit_IT(&huart1, (uint8_t*)&ch, 1);
    while(!txcmlt_flag);
	return 0;
}

/*
 *  函数名：fgetc
 *  功能描述：scanf/getchar 标准输出函数的底层输出函数
 *  输入参数：
 *  输出参数：无
 *  返回值：接收到的数据
*/
int fgetc(FILE *f)
{
    // rxcmlt_flag = 0;
    volatile uint8_t c = 0;
    // HAL_UART_Receive_IT(&huart1, (uint8_t*)&c, 1);
    // while(!rxcmlt_flag);
    while (ring_buffer_read(&ring_buffer, (uint8_t *)&c) != 0);
    return c;
}

void USART1_EnableIRQ(void)
{
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 1);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

    __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE | UART_IT_TC);
}

void USART1_DisableIRQ(void)
{
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE | UART_IT_TC);
    HAL_NVIC_DisableIRQ(USART1_IRQn);
}

void USART1_IRQHandler(void)
{
    if ((USART1->SR &(1<<5)) != 0)
    {
        ring_buffer_write(&ring_buffer, USART1->DR);
    }
    
    HAL_UART_IRQHandler(&huart1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        rxcmlt_flag = 1;
    }
    
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        txcmlt_flag = 1;
    }
}


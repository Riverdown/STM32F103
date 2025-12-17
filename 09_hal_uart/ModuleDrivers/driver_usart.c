#include "driver_usart.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;

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
    while(HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, 3000) != HAL_OK);
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
    volatile char c = 0;
    while(HAL_UART_Receive(&huart1, (uint8_t*)&c, 1, 3000) != HAL_OK );
    
    return c;
}


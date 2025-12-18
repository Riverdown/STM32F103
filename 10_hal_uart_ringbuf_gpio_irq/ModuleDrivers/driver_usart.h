#ifndef __DRIVER_USART_H__
#define __DRIVER_USART_H__

#include "stm32f1xx_hal.h"

extern void debugPrint(const char *string);
extern void debugGet(char *string, uint8_t len);
extern void USART1_EnableIRQ(void);
extern void USART1_DisableIRQ(void);
#endif

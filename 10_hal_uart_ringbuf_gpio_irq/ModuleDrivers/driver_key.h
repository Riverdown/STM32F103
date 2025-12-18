#ifndef __DRIVER_KEY_H__
#define __DRIVER_KEY_H__

#include "stm32f1xx_hal.h"

#define KEY_PRESSED                     (0)
#define KEY_REPRESSED                   (1)

#define KEY1_PIN                        GPIO_PIN_14
#define KEY2_PIN                        GPIO_PIN_15

#define KEY1_GPIO_Port                  GPIOE
#define KEY2_GPIO_Port                  GPIOE

#define KEY1_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOE_CLK_ENABLE()
#define KEY2_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOE_CLK_ENABLE()

#define KEY1_PIN_READ()                 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_PIN)
#define KEY2_PIN_READ()                 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_PIN)

extern void KEY_GPIO_ReInit(void);
extern uint8_t KEY1_Val_Get(void);
extern uint8_t KEY2_Val_Get(void);

#endif /* __DRIVER_KEY_H__ */


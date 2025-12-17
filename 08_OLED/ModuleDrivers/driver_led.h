#ifndef __DRIVER_LED_H__
#define __DRIVER_LED_H__

#define BLUE_ON()         HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, GPIO_PIN_RESET)
#define BLUE_OFF()        HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, GPIO_PIN_SET)

void WhiteOn(void);
void WhiteOff(void);
void GreenOn(void);
void GreenOff(void);
void BlueOn(void);
void BlueOff(void);
void BlueShine(void);
void BlueBlink(void);
#endif


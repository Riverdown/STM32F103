#include "driver_led.h"
#include "main.h"

void BlueOn(void)
{
    HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, GPIO_PIN_RESET);
}

void BlueOff(void)
{
    HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, GPIO_PIN_SET);
}

void BlueShine(void)
{
    BlueOn();
    HAL_Delay(500);
    BlueOff();
    HAL_Delay(500);
}

void BlueBlink(void)
{
    HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
    HAL_Delay(100);
}

void GreenOn(void)
{
    HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);
}

void GreenOff(void)
{
    HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
}

void WhiteOn(void)
{
    HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
}

void WhiteOff(void)
{
    HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_SET);
}

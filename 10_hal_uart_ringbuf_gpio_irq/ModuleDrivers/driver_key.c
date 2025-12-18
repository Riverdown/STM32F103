#include "driver_key.h"

volatile static uint8_t key1_val = KEY_REPRESSED;
volatile static uint8_t key2_val = KEY_REPRESSED;

void KEY_GPIO_ReInit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    KEY1_GPIO_CLK_ENABLE();
    KEY2_GPIO_CLK_ENABLE();

    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Pin = KEY1_PIN ;
    HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = KEY2_PIN ;
    HAL_GPIO_Init(KEY2_GPIO_Port, &GPIO_InitStruct);
    
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 2);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_PIN );
    HAL_GPIO_EXTI_IRQHandler(KEY2_PIN);
}

 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
 {
     if(GPIO_Pin == KEY1_PIN )
     {
        key1_val = KEY1_PIN_READ();
     }
     else if(GPIO_Pin == KEY2_PIN)
     {
        key2_val = KEY2_PIN_READ();
     }
 }

 uint8_t KEY1_Val_Get(void)
 {
     return key1_val;
 }

 uint8_t KEY2_Val_Get(void)
 {
     return key2_val;
 }
 
 

 
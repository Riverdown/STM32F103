#include "uart.h"
#include "exception.h"
#include "systick.h"
#include "led.h"
#include <stdbool.h>

void Systick_Init(void)
{
    SysTick_Type *SysTick = (SysTick_Type *)SysTick_BASE;
    /* 1. set period : 1s*/
    SysTick->VAL = SYSTICK_FRE;

    /* 2. set reload value */
    SysTick->LOAD = SYSTICK_FRE;

    /* 3. select clock source, enable systick, enable systick interrupt
     * bit2 : clock source, process clock
     * bit1 : enable systick interrupt
     * bit0 : enable systick
     */

    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk;
}

void SysTick_Handler(void)
{
    SCB_Type *SCB = (SCB_Type *)SCB_BASE_ADDR;
    /* led operation */
    static bool led_state = 0;
    LedCtrl(led_state);
    led_state = !led_state;

    /* clear systick interrupt */
    SCB->ICSR |= SCB_ICSR_PENDSTCLR_Pos;
}
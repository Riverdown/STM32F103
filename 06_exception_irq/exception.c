#include "uart.h"
#include "exception.h"

void HardFault_Handler(void)
{
	puts("HardFault_Handler\n\r");
	while(1);
}

void UsageFaultInit(void)
{
	SCB_Type *SCB = (SCB_Type *)SCB_BASE_ADDR;
	SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;

}


void UsageFault_Handler(unsigned int *sp)
{
	SCB_Type *SCB = (SCB_Type *)SCB_BASE_ADDR;

	puts("UsageFault_Handler\n\r");
	put_s_hex("r0 = ", sp[0]);
	put_s_hex("r1 = ", sp[1]);
	put_s_hex("r2 = ", sp[2]);
	put_s_hex("r3 = ", sp[3]);
	put_s_hex("r12 = ", sp[4]);
	put_s_hex("lr = ", sp[5]);
	put_s_hex("pc = ", sp[6]);
	put_s_hex("psr = ", sp[7]);
	//clear usage fault
	SCB->CFSR = SCB->CFSR;

	//set return address in sp,point to next instruction
	sp[6] = sp[6] + 4;

}

void SVC_Handler(void)
{
	puts("SVCall Handler\n\r");
}


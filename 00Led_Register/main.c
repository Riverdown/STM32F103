
#if 0

#include <rge52.h>

sbit LED  = P0^0

void main(void)
{
	P0 = 0XFE;     // ���߲���
	
	LED = 0;       // λ����
}

#endif



#include "stm32f10x.h"

int main (void)
{
	// �� GPIOB �˿ڵ�ʱ��
	RCC_APB2ENR |= 0x01<<3;

	//��տ���PB0�Ķ˿�λ
	GPIOB_CRL &= ~( 0x0F<< (4*0));	
	// ����PB0Ϊͨ������������ٶ�Ϊ10M
	GPIOB_CRL |= (1<<4*0);



	// PB0 ��� �͵�ƽ
	GPIOB_ODR &= ~(1<<0) ;
}


// ��λ   |=   ����0 &=~
//



// 1����������������LED��

// 2��дһ���򵥵���ʱ�������õ���˸


// 72M��HSI = 8M��

void SystemInit(void)
{
	// ������Ϊ�գ�Ŀ����Ϊ��ƭ��������������
}


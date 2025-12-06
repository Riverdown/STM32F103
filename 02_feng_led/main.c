


#define RCC_BASE_ADDR		0x40021000
#define GPIOB_BASE_ADDR		0x40010C00
#define RCC_APB2_Offset     0x18

void delay(int times)
{
	 while(times--);
}
int mymain()
{
	unsigned int *pReg;
	
	 /* 使能GPIOB */
	pReg = (unsigned int *)(RCC_BASE_ADDR + RCC_APB2_Offset);
	*pReg |= (1 << 3);
	
	 /* 设置 pin mode ， 设置为 输出 引脚 */
	pReg = (unsigned int*)(GPIOB_BASE_ADDR);
	*pReg |= (1 << 0) | (1 << 4) | (1 << 20);
	
	pReg = (unsigned int*)(GPIOB_BASE_ADDR + 0x0C);
	
	while(1)
	{
		/* 设置 输出 1 */
		*pReg |= (1 << 0);
		delay(1000000);
		/* 设置 输出 0 */
		*pReg &= ~(1<<0);
		delay(1000000); 
		
		/* portB pin 4 设置 输出 1 */
		*pReg |= (1 << 4);
		delay(1000000);
		/* 设置 输出 0 */
		*pReg &= ~(1<<4);
		delay(1000000); 
		
		/*portB pin5 设置 输出 1 */
		*pReg |= (1 << 5);
		delay(1000000);
		/* 设置 输出 0 */
		*pReg &= ~(1<<5);
		delay(1000000);
	}
	
	return 0;
}


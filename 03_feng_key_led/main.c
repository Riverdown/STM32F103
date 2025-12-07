

#define RCC_BASE_ADDR   	0x40021000
#define GPIOB_BASE_ADDR 	0x40010C00
#define RCC_APB2_Offset 	0x18

void delay(int times)
{
	while (times--);
}
int main()
{
	unsigned int *pReg;
	unsigned int *key1_reg;
	unsigned int key1_value = 0;

	/* 使能GPIOB */
	pReg = (unsigned int *)(RCC_BASE_ADDR + RCC_APB2_Offset);
	*pReg |= (1 << 3);

	/* 设置 pin mode ， 设置为 输出 引脚 */
	pReg = (unsigned int *)(GPIOB_BASE_ADDR);
	*pReg |= (1 << 0);

	/* 使能Key1*/
	pReg = (unsigned int *)(0x40021000 + 0x18);
	*pReg |= (1 << 2);

	/* 设置 Key1 为 输入*/
	pReg = (unsigned int *)(0x40010800 + 0x00);
	*pReg = *pReg & ~(0xF);
	*pReg |= (1 << 2);

	/* 设置 Port B pin ODR 寄存器地址 */
	pReg = (unsigned int *)(GPIOB_BASE_ADDR + 0x0C);

	key1_reg = (unsigned int *)(0x40010800 + 0x08);

	while (1)
	{
		key1_value = *key1_reg;

		if ((key1_value & 1) == 0)
		{
			delay(100000);
			if ((key1_value & 1) == 0)
			{
				/* 设置 输出 toggle */
				*pReg = (~ *pReg) & 1;
			}
		}
	}

	return 0;
}

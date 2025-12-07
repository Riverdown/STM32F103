#include <stdio.h>
#include "uart_bsp.h"
void delay(int times)
{
	 while(times--);
}

int main()
{
	uart_bsp_init();

	uart_putchar('A');
	uart_putchar('B');
	uart_putchar('C');
	uart_putchar('D');
	uart_putchar('\n');
	uart_putchar('\n');
	
	while(1)
	{
		unsigned char c = uart_getchar();
		uart_putchar(c);
		uart_putchar(c+1);
	}
	return 0;
}


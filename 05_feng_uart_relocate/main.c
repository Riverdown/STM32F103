#include <stdio.h>
#include "string.h"

unsigned char g_ch1 = 'A';
const unsigned char g_ch2 = 'B';
unsigned char g_ch3[24];
void delay(int times)
{
	 while(times--);
}

int Mymain()
{
	uart_bsp_init();

	uart_putchar('A');
	uart_putchar('B');
	uart_putchar('C');
	uart_putchar('D');
	uart_putchar('\n');
	uart_putchar('\r');
	
	put_s_hex("g_ch1 is addr: ", &g_ch1);
	put_s_hex("g_ch2 is addr: ", &g_ch2);
	
	uart_putchar(g_ch1);
	uart_putchar(g_ch2);
	uart_putchar('\n');
	uart_putchar('\r');
	void (*fun_p)(const char *, unsigned int);
	fun_p = put_s_hex;
	fun_p("g_ch2 is addr: ", &g_ch2);
	for (unsigned char i = 0; i < 24; i++)
	{
		puthex(g_ch3[i]);
		uart_putchar(' ');
	}
	
	while(1)
	{
		unsigned char c = uart_getchar();
		uart_putchar(c);
		uart_putchar(c+1);
	}
	return 0;
}


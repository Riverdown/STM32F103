#include "string.h"


int puts(const char *s)
{
	while (*s)
	{
		uart_putchar(*s);
		s++;
	}
	return 0;
}

void puthex(unsigned int val)
{
	/* 0x76543210 */
	int i, j;

	puts("0x");
	for (i = 7; i >= 0; i--)
	{
		j = (val >> (i*4)) & 0xf;
		if ((j >= 0) && (j <= 9))
			uart_putchar('0' + j);
		else
			uart_putchar('A' + j - 0xA);
	}	
}

void put_s_hex(const char *s, unsigned int val)
{
	puts(s);
	puthex(val);
	puts("\r\n");
}

void memcpy(void *dest, const void *src, unsigned int len)
{
	unsigned char *pcDest = (unsigned char *)dest;
	unsigned char *pcSrc  = (unsigned char *)src;
	while (len--)
	{
		*pcDest = *pcSrc;
		pcDest++;
		pcSrc++;
	}
}

void memset(void *dest, unsigned char val, unsigned int len)
{
	unsigned char *pcDest = (unsigned char *)dest;
	while (len--)
	{
		*pcDest = val;
		pcDest++;
	}
}


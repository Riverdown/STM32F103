
#ifndef _STRING_H
#define _STRING_H
#include "uart_bsp.h"
int puts(const char *s);
void puthex(unsigned int val);
void put_s_hex(const char *s, unsigned int val);
#endif


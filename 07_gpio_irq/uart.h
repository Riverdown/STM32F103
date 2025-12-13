
#ifndef _UART_H
#define _UART_H
void uart_init(void);
int getchar(void);
int putchar(char c);
int puts(const char *s);
void put_s_hex(const char *s, unsigned int val);
void memcpy(void *dest, const void *src, unsigned int len);
void memset(void *dest, unsigned char val, unsigned int len);

#endif

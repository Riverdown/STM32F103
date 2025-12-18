#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#include "stm32f1xx_hal.h"

#define RING_BUFFER_SIZE 128

typedef struct {
    uint8_t head;
    uint8_t tail;
    uint8_t data[RING_BUFFER_SIZE];
} ring_buffer_t;

extern void ring_buffer_init(ring_buffer_t *rb);
extern int ring_buffer_write(ring_buffer_t *rb, uint8_t data);
extern int ring_buffer_read(ring_buffer_t *rb, uint8_t *data);
#endif  /* __RING_BUFFER_H__ */


#include "ring_buffer.h"

void ring_buffer_init(ring_buffer_t *rb) 
{
    rb->head = 0;
    rb->tail = 0;
}

int ring_buffer_write(ring_buffer_t *rb, uint8_t data) 
{
    int head = (rb->head + 1) % RING_BUFFER_SIZE;
    if (head == rb->tail)
    {
        return -1; /* buffer full */
    }

    rb->data[rb->head] = data;
    rb->head =head;

    return 0;
}

int ring_buffer_read(ring_buffer_t *rb, uint8_t *data) 
{
    if (rb->head == rb->tail)
    {
        return -1; /* buffer empty */
    }

    *data = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
    
    return 0;
}


#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include<stdint.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 80




typedef struct {
    uint8_t *data;
    uint8_t head;
    uint8_t tail;

} circular_buffer;

int create(circular_buffer *buffer, uint8_t *array);

int  insert(circular_buffer *buffer, uint8_t data);

#endif //CIRCULAR_BUFFER_H

#include<CircularBuffer.h>

int create(circular_buffer *buffer , uint8_t *array)
{   int r =-1;
    if (buffer){
        buffer->data = buffer;
        buffer->head =0;
        buffer->tail =0 ;
        r=0;
    }
    return r;

}

int insert(circular_buffer *buffer, uint8_t data){
    int r=-1;
    if (buffer){
        buffer->data[buffer->tail] = data;
        buffer->tail =  buffer->tail+1% MAX_SIZE ;

        if (buffer->head == buffer->tail){

            buffer->head = buffer->head +1 % MAX_SIZE;
        }
        r=0;

    }

    return r;
}


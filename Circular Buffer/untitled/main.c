#include<CircularBuffer.h>

void main(){


    circular_buffer buffer;
    uint8_t array[MAX_SIZE];
    create(&buffer, &array);
    int i =0;

    while (insert(&buffer,rand()%100)) {
        printf("%d\n",buffer.data[i]);
        i++;

    }


}

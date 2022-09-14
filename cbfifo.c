#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cbfifo.h"
#include "BUF_SIZE.h"

uint8_t circularBuffer[CB_SIZE];
uint8_t read_pointer = 0;
uint8_t write_pointer = 0;
uint8_t end_point = CB_SIZE;



// -------------------------------------------------------CB-FIFO-ENQUEUE-----------------------------------------------------------------------
size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
    // checking if the input buffer data is null
    if (buf == NULL)
        return -1;
    // type casting the data to uint8_t to make it compatible and generic
    uint8_t *data = buf;
    int i;
    if(write_pointer==0 && read_pointer==0)
    {
        circularBuffer[write_pointer++] = *data++;
    }
    // only when write index is behind end index, data is enqueued
    //&& (write_pointer&127) < ((read_pointer)?(read_pointer&127):(read_pointer+1))  && ((read_pointer)!=((write_pointer-1)&127))
    for (i = write_pointer; i < nbyte ; i++)
    {
        if((read_pointer+1)&127==(write_pointer))
            return -1;
//        printf("%d\n",*data);
        circularBuffer[write_pointer] = *data++;
        write_pointer =(write_pointer+1)&127;

    }
    // type casting the number of bytes written
    return (size_t)i;
}

size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
    // null buffer pointer check
    if (buf == NULL)
        return -1;
    uint8_t *data = buf;

    int i;
    int temp_read=read_pointer;
    for(i=read_pointer;i<(nbyte+temp_read);i++)
    {
        *data++ = circularBuffer[i];
        read_pointer =((read_pointer+1)&127);
//        printf("%d ",read_pointer);
    }
    printf("\n%d ",read_pointer);
    return (size_t)i;
}

size_t cbfifo_length()
{
    // because of the dequeue reset function everytime the length of the buffer will be same as the write index
    return (size_t)(write_pointer&127)-(read_pointer&127);
}

size_t cbfifo_capacity()
{
    // buffer size has been statically allocated to be 128 bytes in commons.h
    return (size_t)CB_SIZE;
}
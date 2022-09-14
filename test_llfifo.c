//Test code has been adapted from Chinmay Shalawadi's implementation

//#include "test_llfifo.h"
#include "llfifo.h"
//#include "llfifo.c"
#include <stdio.h>

#include <stdlib.h>

int test_llfifo(void) {
    int dequeued = 0;
    node_t *newfifo = llfifo_create(7);

//    printf("\n\nlength:%d capacity:%d\n\n",llfifo_length(newfifo),llfifo_capacity(newfifo));

    llfifo_enqueue(newfifo, 6);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 17);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 98);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 41);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_enqueue(newfifo, 6);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 17);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 98);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_enqueue(newfifo, 41);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));
    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));

    llfifo_dequeue(newfifo);
    printf("length:%d capacity:%d\n", llfifo_length(newfifo), llfifo_capacity(newfifo));


    dequeued = llfifo_dequeue(newfifo);


    return 0;
}
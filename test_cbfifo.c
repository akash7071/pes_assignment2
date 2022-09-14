//Test code has been adapted from Chinmay Shalawadi's implementation

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cbfifo.h"
#include "cbfifo.c"
#include "test_cbfifo.h"
#include "BUF_SIZE.h"

// These static data is used to test the buffer and the results
char *str_store = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789*-,thequickbrownfoxjumpedoverthelazydogandthefoxatethedogbrutally";
char str[128] = {""};

//The core buffer variables definied in the CB Buffer file,
// They are used here for testing purposes
extern uint8_t circularBuffer[];
extern uint8_t read_pointer;
extern uint8_t write_pointer;
extern uint8_t end_pointer;

// ---------------------------------------------------------TEST-CBFIFO------------------------------------------------

int test_cbfifo()
{
    printf("****************************************************************************************\n\n");
    printf("Starting CBFIFO Tests...\n\n");
    printf("****************************************************************************************\n\n");

    int passed_count = 0;
    int passed = 1;

    // Various test cases, queueing and dequeing cycles and length check.

    printf("Capacity of the  buffer is -> %lu \n\n", cbfifo_capacity());
    printf("Enqueueing 500 Bytes of Data, Bytes actually Queued");
    printf("-> %lu \n \n", cbfifo_enqueue(str_store, 500));
    if (cbfifo_length() == 128)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 10 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 10));
    if (cbfifo_length() == 118)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 50 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 50));
    if (cbfifo_length() == 68)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 68 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 68));
    if (cbfifo_length() == 0)
        passed_count++;
    else
        passed = 0;

    printf("Enqueueing 50 Bytes of Data, Bytes actually Queued");
    printf("-> %lu \n \n", cbfifo_enqueue(str_store, 50));
    if (cbfifo_length() == 50)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 0 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 0));
    if (cbfifo_length() == 50)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing -1 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, -1));
    if (cbfifo_length() == 0)
        passed_count++;
    else
        passed = 0;

    printf("Enqueueing 1 Bytes of Data, Bytes actually Queued");
    printf("-> %lu \n \n", cbfifo_enqueue(str_store, 1));
    if (cbfifo_length() == 1)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 5 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 5));
    if (cbfifo_length() == 0)
        passed_count++;
    else
        passed = 0;

    printf("Enqueueing 127 Bytes of Data, Bytes actually Queued");
    printf("-> %lu \n \n", cbfifo_enqueue(str_store, 127));
    if (cbfifo_length() == 127)
        passed_count++;
    else
        passed = 0;

    printf("Dequeueing 128 Bytes of Data into Memory, Bytes actually Dequeued");
    printf("-> %lu \n \n", cbfifo_dequeue(str, 128));
    if (cbfifo_length() == 0)
        passed_count++;
    else
        passed = 0;

    printf("CASES PASSED %d/11 \n \n", passed_count);
    return passed;
}

/*
Below function is just for debugging, to dumpt the contents of the buffer to crosscheck
*/
void cbfifo_dump_state()
{
    printf("*********************************************DUMP*******************************************************\n");
    printf("The state of FIFO Array is dumped below \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("[");
    for (int i = 0; i < CB_SIZE; i++)
    {
        printf(" %d,", circularBuffer[i]);
    }
    printf("]\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Read Index -> %u | Write Index -> %u \n", read_pointer, write_pointer);
    printf("*********************************************END********************************************************\n\n");
}
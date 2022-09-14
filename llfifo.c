#include <stdio.h>

#include <stdlib.h>
#include "llfifo.h"
//int static first_node=1;
int i;
//int *prev=NULL;
//int *head=NULL;



typedef struct node_s
{
    int data;
    struct llfifo_s *next;

}node_t;
//typedef struct node_s node_t;

typedef struct llfifo_s
{
    node_t*front;
    node_t *rear;
    node_t *end;

    int length;
    int capacity;
}llfifo_t;
//typedef struct llfifo_s llfifo_t;



llfifo_t *llfifo_create (int capacity)
{
    struct llfifo_s *q = (struct llfifo_s*)malloc(sizeof(struct llfifo_s));
    if (q==NULL)
    {
        return NULL;
    }
    q->rear = NULL;


    int a=1;
    node_t *temp;

    if(capacity==0)
    {
        temp = (struct node_s *)malloc(sizeof(struct node_s));

        temp -> next = NULL;
        temp->data=NULL;

    }
    else {
        while (capacity) {

            i++;

            temp = (struct node_s *) malloc(sizeof(struct node_s));

            temp->next = q->rear;
            temp->data = NULL;
            capacity--;
            q->rear = temp;
            if (a) {
                q->end = temp;
                q->end->data = NULL;
                a--;
            }


        }
    }
    q->front=q->rear=temp;

    return q;

}


int llfifo_enqueue(llfifo_t *fifo, void *element)
{
    if(element==NULL)
        return-1;
    if(llfifo_length(fifo)== llfifo_capacity(fifo))
    {

        node_t *temp = (struct node_s *)malloc(sizeof(struct node_s));
        if(temp==NULL)
            return NULL;
        temp->data=NULL;
        temp->next=NULL;
        fifo->end->next=temp;
        fifo->end=temp;
    }

    else if(fifo->front==fifo->rear && fifo->rear->data==NULL)
    {

        fifo->rear->data=element;
        printf("element %d a ",fifo->rear->data);
        return llfifo_length(fifo);
    }
    else if(fifo->front==fifo->rear && fifo->rear->data!=NULL)
    {
        fifo->rear=fifo->rear->next;
        fifo->rear->data=element;
        printf("element %d b ",fifo->rear->data);
        return llfifo_length(fifo);
    }
    fifo->rear=fifo->rear->next;


    if (fifo->rear->data==NULL)
    {

        fifo->rear->data=element;

        printf("element %d c ",fifo->rear->data);
        return 1;
    }

    return llfifo_length(fifo);



};

void *llfifo_dequeue(llfifo_t *fifo)
{

    if(fifo->front->data==NULL)
        return NULL;
    if(llfifo_length(fifo)==0)
        return NULL;
    int temp=fifo->front->data;

    fifo->front->data=NULL;


    fifo->end->next=fifo->front;
    fifo->front=fifo->front->next;
    fifo->end=fifo->end->next;
    fifo->end->next=NULL;
    return temp;

};

int llfifo_length(llfifo_t *fifo)
{

    node_t *temp1 = (struct node_s *)malloc(sizeof(struct node_s));
    if (temp1==NULL) {

        return NULL;
    }

    temp1=fifo->front;
    int count=0;




    while(temp1->data!=NULL)
    {

        if(temp1==fifo->end)
            return count+1;
        count++;

        temp1=temp1->next;

    }

    return count;
};

int llfifo_capacity(llfifo_t *fifo)
{
    node_t *temp = (struct node_s *)malloc(sizeof(struct node_s));
    temp= fifo->front;
    int count=0;
    while(temp->next!=NULL)
    {
        count++;
        //printf("%d",count);
        temp=temp->next;
    }
    return count+1;

};

void llfifo_destroy(llfifo_t *fifo)
{
    node_t *temp = (struct node_s *)malloc(sizeof(struct node_s));

    while(fifo->front!=NULL)
    {
        temp=fifo->front;
        fifo->front=fifo->front->next;
        free(temp);

    }

};

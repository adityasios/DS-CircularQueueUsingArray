//
//  main.c
//  CircularQueueUsingArray
//
//  Created by inncrewin on 26/12/23.
//

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int * Q;
};
struct Queue q;

void createQueue(struct Queue * qT);
void displayQueue(struct Queue  qT);

void enqueue(struct Queue * qT,int data);
int isFull(struct Queue * qT);

int dequeue(struct Queue * qT);
int isEmpty(struct Queue * qT);

int main(int argc, const char * argv[]) {
    createQueue(&q);
    enqueue(&q,2);
    enqueue(&q,4);
    enqueue(&q,6);
    enqueue(&q,8);
    int d1 = dequeue(&q);
    printf("Removed element is  = %d\n",d1);
    enqueue(&q,10);
    displayQueue(q);
    printf("q.front = %d\n",q.front);
    printf("q.rear = %d\n",q.rear);
    
    
    
    int d2 = dequeue(&q);
    printf("Removed element is  = %d\n",d2);
    int d3 = dequeue(&q);
    printf("Removed element is  = %d\n",d3);
    int d4 = dequeue(&q);
    printf("Removed element is  = %d\n",d4);
    

    
    
    return 0;
}

void createQueue(struct Queue * qT){
    qT->size = 4;
    qT->front = 0;
    qT->rear = 0;
    qT->Q = (int *)malloc(qT->size * sizeof(int));
}

void displayQueue(struct Queue  qT){
    int i = qT.front;
    while (i != qT.rear) {
        i = (i+1)%qT.size;
        printf("Q[%d] = %d\n",i,qT.Q[i]);
    }
    
}
void enqueue(struct Queue * qT,int data){
    if(isFull(qT)){
        printf("Queue is full\n");
        return ;
    }
    qT->rear = (qT->rear+1)%(qT->size);
    qT->Q[qT->rear] = data;
}

int isFull(struct Queue * qT){
    return (qT->rear+1)%(qT->size) == (qT->front) ? 1:0;
}


int dequeue(struct Queue * qT){
    if(isEmpty(qT)){
        printf("Queue is Empty\n");
        return -1;
    }
    qT->front = (qT->front+1)%(qT->size);
    return  qT->Q[qT->front];
}

int isEmpty(struct Queue * qT){
    return qT->rear == (qT->front);
}

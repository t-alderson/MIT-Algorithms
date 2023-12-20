#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
// Assuming the vertex structure is defined as follows:


typedef struct _queueNode {
    vertex *v;
    struct _queueNode *next;
} queueNode;

typedef struct _queue {
    queueNode *front;
    queueNode *rear;
} queue;

// Function to create a new queue
queue* createQueue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (!q) {
        perror("Unable to allocate memory for queue");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = NULL;
    return q;
}

// Function to create a new queue node
queueNode* newQueueNode(vertex *v) {
    queueNode *newNode = (queueNode*)malloc(sizeof(queueNode));
    if (!newNode) {
        perror("Unable to allocate memory for queue node");
        exit(EXIT_FAILURE);
    }

    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add a vertex to the queue
void enqueue(queue *q, vertex *v) {
    queueNode *newNode = newQueueNode(v);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to remove a vertex from the queue
vertex* dequeue(queue *q) {
    if (q->front == NULL) {
        return NULL;
    }

    queueNode *temp = q->front;
    vertex *v = temp->v;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return v;
}

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return (q->front == NULL);
}

// Function to delete the queue and free memory
void deleteQueue(queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

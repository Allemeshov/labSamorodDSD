#ifndef SAMORODLABDSD_LAB32_H
#define SAMORODLABDSD_LAB32_H

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <vector>


void lab32();

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    char *array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue *createQueue(unsigned capacity);

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue *queue);

// Queue is empty when size is 0
int isEmpty(struct Queue *queue);

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue *queue, char item);

// Function to remove an item from queue.
// It changes front and size
char dequeue(struct Queue *queue);

// Function to get front of queue
char front(struct Queue *queue);

// Function to get rear of queue
char rear(struct Queue *queue);

#endif //SAMORODLABDSD_LAB32_H

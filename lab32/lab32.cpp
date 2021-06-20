#include "lab32.h"

void lab32() {
    std::fstream file;
    file.open("text32.txt", std::fstream::in);
    std::string line;
    std::vector<std::string> lines;


    if (file.is_open()) {
        struct Queue *letters;
        struct Queue *digits;
        int length;
        while (getline(file, line)) {
            length = line.length();
            letters = createQueue(length);
            digits = createQueue(length);

            for (int i = 0; i < length; ++i) {
                if (isdigit(line[i]))
                    enqueue(digits, line[i]);
                else
                    enqueue(letters, line[i]);
            }

            for (int i = 0; i < length; ++i) {
                if (!isEmpty(letters)) {
                    line[i] = dequeue(letters);
                } else {
                    if (!isEmpty(digits))
                        line[i] = dequeue(digits);
                }
            }

            lines.emplace_back(line);
        }
        file.close();

        file.open("text32.txt", std::fstream::out | std::fstream::trunc);
        for (auto &curLine : lines)
            file << curLine << '\n';
    }
    /*
     * a1b2cc3
     * asd2asd3asd
     * 0s12dsd34d
     * */
}

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *) malloc(
            sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (char *) malloc(
            queue->capacity * sizeof(char));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue *queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue *queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue *queue, char item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
// It changes front and size
char dequeue(struct Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
char front(struct Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
char rear(struct Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


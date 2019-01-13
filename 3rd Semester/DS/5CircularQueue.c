// @author: K Nitesh Srivats
// @title: Circular Queue

#include<stdio.h>

void enqueue(int *queue, int *front, int *rear, int max) {
    if (*rear - *front == max - 1 || *rear == *front - 1)
        printf("Queue Overflow.\n\n");
    else {
        if (*rear == -1)
            *front = *rear = 0;
        else 
            *rear = (*rear + 1) % max;
        printf("Enter Element: ");
        scanf("%d", (queue + *rear));
        printf("\n");
    }
}


void dequeue(int *queue, int *front, int *rear, int max) {
    if (*front == -1) 
        printf("Queue Underflow.\n\n");
    else {
        printf("Popping: %d\n\n", *(queue + *front));
        if (*front == *rear)
            *front = *rear = -1;
        else
            *front = (*front +1) % max;
    }
}


void display(int *queue, int *front, int *rear, int max) {
    if (*front == -1) 
        printf("Queue Empty.\n\n");
    else {
        printf("The Queue:");
        for(int i = *front;; i++) {
              i = i % max;
              printf(" %d", *(queue + i));
              if (*rear == i)
                  break;
        }
        printf("\n\n");
    }
}


int main(int argc, char const *argv[])
{
    int choice = 1, front = -1, rear = -1, max = 2, queue[10]; 
    while (choice) {
        printf("1. Enqueue.\n2. Dequeue.\n3. Display.\n0. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(queue, &front, &rear, max);
                break;
            case 2:
                dequeue(queue, &front, &rear, max);
                break;
            case 3:
                display(queue, &front, &rear, max);
                break;
        }
    }
    return 0;
}

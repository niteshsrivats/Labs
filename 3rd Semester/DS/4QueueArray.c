// @author: K Nitesh Srivats
// @title: Queue as Array

#include<stdio.h>

void enqueue(int *queue, int *front, int *rear, int max) {
    if (*rear == max - 1) 
        printf("Queue Overflow.\n\n");
    else {
        if (*rear == -1)
            *front = 0;
        *rear += 1;
        printf("Enter Element: ");
        scanf("%d", (queue + *rear));
        printf("\n");
    }
}


void dequeue(int *queue, int *front, int *rear) {
    if (*front == -1) 
        printf("Queue Underflow.\n\n");
    else {
        printf("Popping: %d\n\n", *(queue + *front));
        if (*front == *rear)
            *front = *rear = -1;
        else
            *front += 1;
    }
}


void display(int *queue, int *front, int *rear) {
    if (*front == -1) 
        printf("Queue Empty.\n\n");
    else {
        printf("The Queue:");
        for(int i = *front; i <= *rear; i++)
            printf(" %d", *(queue + i));
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
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, &front, &rear);
                break;
        }
    }
    return 0;
}

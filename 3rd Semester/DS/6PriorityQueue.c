// @author: K Nitesh Srivats
// @title: Priority Queue Using Array

#include<stdio.h>

void enqueue(int (*queue)[3], int *front, int *rear, int max) {
    int priority;
    printf("Enter Priority: ");
    scanf("%d", &priority);
    priority -= 1;
    if (*(rear + priority) == max - 1) 
        printf("Queue Overflow.\n\n");
    else {
        if (*(rear + priority) == -1)
            *(front + priority) = 0;
        *(rear + priority) += 1;
        printf("Enter Element: ");
        scanf("%d", (*(queue + *(rear + priority)) + priority));
        printf("\n");
    }
}


void dequeue_operation(int (*queue)[3], int *front, int *rear, int priority) {
     printf("Deleting: %d\n\n", *(*(queue + *(front + priority)) + priority));
        if (*(front + priority) == *(rear + priority))
            *(front + priority) = *(rear + priority) = -1;
        else
            *(front + priority) += 1;
}


void dequeue(int (*queue)[3], int *front, int *rear) {
    if (*front != -1) 
        dequeue_operation(queue, front, rear, 0);
    else if (*(front+1) != -1)
        dequeue_operation(queue, front, rear, 1);
    else if (*(front+2) != -1)
        dequeue_operation(queue, front, rear, 2);
    else
        printf("Queue Underflow.\n\n");
}


void display_operation(int (*queue)[3], int *front, int *rear, int priority) {
    printf("The Queue %d:", priority + 1);
    for(int i = *(front + priority); i <= *(rear + priority); i++)
        printf(" %d", *(*(queue + i) + priority));
    printf("\n\n");
}


void display(int (*queue)[3], int *front, int *rear) {
     if (*front != -1)
        display_operation(queue, front, rear, 0);
     if (*(front+1) != -1)
        display_operation(queue, front, rear, 1);
     if (*(front+2) != -1)
        display_operation(queue, front, rear, 2);
     if (*(front+2) == -1 && *(front+1) == -1 && *front == -1)
        printf("Queue Empty.\n\n");
}


int main(int argc, char const *argv[])
{
    int choice = 1, front[] = {-1, -1, -1}, rear[] = {-1, -1, -1}, max = 2, queue[10][3]; 
    while (choice) {
        printf("1. Insert.\n2. Delete.\n3. Display.\n0. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(queue, front, rear, max);
                break;
            case 2:
                dequeue(queue, front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
        }
    }
    return 0;
}

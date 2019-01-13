// @author: K Nitesh Srivats
// @title: Single Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct QueueLL *Node;

struct QueueLL{
    int data;
    struct QueueLL *link;
};


Node getNode(){
    Node newNode = (Node)malloc(sizeof(Node));
    printf("Enter Element: \n");
    scanf("%d", &(newNode -> data));
    newNode -> link = NULL;
    return newNode;
}


void enqueue(Node *head, Node *rear, int *count, int size, int pos){
    if(*count == size)
        printf("Queue Full.\n");
    else{
        Node newNode = getNode();
        *count += 1;
        if(*head == NULL)
            *head = *rear = newNode;
        else if(pos == 1){
            newNode -> link = *head;
            *head = newNode;
        }
        else if(pos == *count || pos == 0){
            (*rear) -> link = newNode;
            *rear = newNode;
        }
        else if(pos < *count){
            Node temp = *head;
            for(int i = 2; i < pos; i++)
                temp = temp -> link;
            newNode -> link = temp -> link;
            temp -> link = newNode;
        }
    }
}


void dequeue(Node *head, Node *rear, int *count, int pos){
    if(*count == 0)
        printf("Queue Empty.\n");
    else{
        if(*head == *rear){
            printf("Deleting %d.\n", (*head) -> data);
            *head = *rear = NULL;        
        }
        else if(pos <= 1){
            printf("Deleting %d.\n", (*head) -> data);
            *head = (*head) -> link;
        }
        else if(pos <= *count){
            Node temp = *head;
            for(int i = 2; i < pos; i++)
                temp = temp -> link;
            if(pos != *count)
                temp -> link = temp -> link -> link;
            else
                *rear = temp;
        }
        *count -= 1;
    }
}


void display(Node head, Node rear){
    if(head == NULL)
        printf("Queue Empty.\n");
    else{
        Node temp = head;
        printf("The Queue :\n");
        for(;;temp = temp -> link){
        printf("%d ", temp -> data);
            if(temp == rear)
                break;
       }
    }
}


int main(){
  int size = 3, choice = 1, count = 0, temp;
  Node head = NULL;
  Node rear = NULL;
  while (choice){
    printf("1. Insert.\n2. Delete.\n3. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter Position(0 - Normal Operation): ");
            scanf("%d", &temp);
            enqueue(&head, &rear, &count, size, temp);
            break;
        case 2:
            printf("Enter Position(0 - Normal Operation): ");
            scanf("%d", &temp);
            dequeue(&head, &rear, &count, temp);
            break;
        case 3:
            display(head, rear);
            break;
    }
    printf("\n");
  }
  return 0;
}

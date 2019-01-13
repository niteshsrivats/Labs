#include<stdio.h>
#include<stdlib.h>

typedef struct QueueLL *Node;

struct QueueLL{
    int data;
    struct QueueLL *link;
};

Node front = NULL;
Node rear = NULL;

Node getNode() {
  Node newNode = (Node)malloc(sizeof(Node));
  if (newNode == NULL)
    return NULL;
  printf("Enter Data: ");
  scanf("%d", &(newNode -> data));
  newNode -> link = NULL;
  return newNode;
}


void enqueue() {
  Node newNode = getNode();
  if (newNode == NULL)
    printf("Queue Overflow.\n");
  else if (rear == NULL)
    rear = front = newNode;
  else {
    rear -> link = newNode;
    rear = newNode;
  } 
}


void dequeue() {
  if (front == NULL)
    printf("Queue Underflow.\n");
  else {
    printf("Deleting %d.\n", front -> data);
    front = front -> link;
  }
}

void display(){
  if(front == NULL)
    printf("Queue Empty.\n");
  else {
    Node temp = front;
    printf("The Queue: ");
    while (temp != NULL) {
      printf("%d ", temp -> data);
      temp = temp -> link;
    }
  }
}


int main(){
  int choice = 1;
  while (choice) {
    printf("1. Insert.\n2. Delete.\n3. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
    }
    printf("\n");
  }
  return 0;
}

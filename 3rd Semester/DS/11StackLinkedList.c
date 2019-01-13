#include<stdio.h>
#include<stdlib.h>

typedef struct StackLL *Node;

struct StackLL{
    int data;
    struct StackLL *link;
};

Node top = NULL;

Node getNode() {
  Node newNode = (Node)malloc(sizeof(Node));
  if (newNode == NULL)
    return NULL;
  printf("Enter Data: ");
  scanf("%d", &(newNode -> data));
  newNode -> link = NULL;
  return newNode;
}


void push() {
  Node newNode = getNode();
  if (newNode == NULL)
    printf("Stack Overflow.\n");
  else {
    if (top != NULL)
      newNode -> link = top;
    top = newNode;
    }
}


void pop() {
  if (top == NULL)
    printf("Stack Underflow.\n");
  else {
    printf("Popping %d.\n", top -> data);
    top = top -> link;
  }
}

void display(){
  if(top == NULL)
    printf("Stack Empty.\n");
  else {
    Node temp = top;
    printf("The Stack: ");
    while (temp != NULL) {
      printf("%d ", temp -> data);
      temp = temp -> link;
    }
  }
}


int main(){
  int choice = 1;
  while (choice) {
    printf("1. Push.\n2. Pop.\n3. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
    }
    printf("\n");
  }
  return 0;
}

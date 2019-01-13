#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList *Node;

Node head = NULL;

struct linkedList {
  int data;
  Node next, prev;
};


Node getNode() {
  Node newNode = (Node)malloc(sizeof(Node));
  if(newNode == NULL)
    return NULL;
  printf("Enter Data: ");
  scanf("%d", &(newNode -> data));
  newNode -> prev = newNode -> next = NULL;
  return newNode;
}

void createNode() {
  head = NULL;
}


void insertNode() {
  if (head == NULL)
    head = getNode();
  else {
    Node newNode = getNode();
    if (newNode == NULL)
      printf("List Full.\n");
    else {
      newNode -> next = head;
      head -> prev = newNode;
      head = newNode;
    }
  }
}


void deleteNode() {
  if (head == NULL) 
    printf("List Empty.\n");
  else {
    int data;
    Node temp = head;
    printf("Enter Node to Delete: ");
    scanf("%d", &data);
    while (temp != NULL) {
      if (temp -> data == data) {
        printf("Deleting %d.\n", data);
        if (temp -> next == NULL && temp -> prev == NULL)
          head = NULL;
        else if (temp -> next == NULL)
          temp -> prev -> next = NULL;
        else if (temp -> prev == NULL) {
          temp -> next -> prev = NULL;
          head = temp -> next;
        }
        else {
          temp -> prev -> next = temp -> next;
          temp -> next -> prev = temp -> prev;
        }
        free(temp);
        return;
      }
      else 
        temp = temp -> next;
    }
  printf("Element Not Found.\n");
  }
}


void displayNodes() {
  if (head == NULL) 
    printf("List Empty.\n");
  else {
    Node temp = head;
    printf("The List: ");
    while (temp != NULL) {
      printf(" %d", temp -> data);
      temp = temp -> next;
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  int choice = 1;
  while (choice) {
    printf("1. Create List.\n2. Insert.\n3. Delete.\n4. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            createNode();
            break;
        case 2:
            insertNode();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            displayNodes();
            break;
    }
    printf("\n");
  }
  return 0;
}

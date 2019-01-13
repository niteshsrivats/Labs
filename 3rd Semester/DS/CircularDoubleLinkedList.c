// @author: K Nitesh Srivats
// @title: Linear Double Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct CQueueDLL *Node;

struct CQueueDLL{
  int data;
  struct CQueueDLL *leftLink;
  struct CQueueDLL *rightLink;
};


Node getNode()
{
  int element;
  printf("Enter Element to Enqueue: \n");
  scanf("%d", &element);
  Node newNode = (Node)malloc(sizeof(Node));
  newNode -> data = element;
  newNode -> leftLink = NULL;
  newNode -> rightLink = NULL;
  return newNode;
}


void enqueue(Node *head, Node *rear, int *count, int size, int pos){
  if(*count == size)
    printf("Queue Full.\n");
  else{
    Node newNode = getNode();
    *count += 1;
    if(*head == NULL || pos == 1){
      if(*head != NULL){
        newNode -> leftLink = *head;
        (*head) -> rightLink = newNode;
        *head = newNode;
        (*rear) -> leftLink = *head;
      }
      else{
          *head = *rear = newNode;
          (*head) -> leftLink = *head;
      }
      (*head) -> rightLink = *rear;
    }
    else{
      Node temp = *head;
      for(int i = 1; i < pos && temp != *rear; i++)
        temp = temp -> leftLink;
      if(pos != 0 && pos < *count){  
        newNode -> rightLink = temp -> rightLink;
        newNode -> leftLink = temp;
        newNode -> rightLink -> leftLink = newNode;
        temp -> rightLink = newNode;
      }
      else{
        newNode -> rightLink = *rear;
        (*rear) -> leftLink = newNode;
        (*head) -> rightLink = newNode;
        newNode -> leftLink = *head;
        *rear = newNode;
      }
    }
  }
}


void searchEnqueue(Node *head, Node *rear, int *count, int size, int element){
  if(*head == NULL)
    printf("Queue Empty.\n");
  else{
    int position = 2;
    Node current = *head;
    do{
      if(current -> data == element){
        enqueue(head, rear, count, size, position);
        return;
      }
      current = current -> leftLink;
      position += 1;
    }
    while(current != *head);
    printf("Element Not Found.\n");
  }
}


void dequeue(Node *head, Node *rear, int *count, int size, int pos){
  if(*count == 0)
    printf("Queue Empty.\n");
  else{
    printf("Deleting: ");
    if(*head == *rear || *count == 1){
      printf("%d\n", (*head) -> data);
      *head = *rear = NULL;
    }
    else{
      Node temp = *head;
      for(int i = 1; i < pos && temp != *rear; i++)
        temp = temp -> leftLink;
      if(pos != 0){  
        printf("%d\n", temp -> data);
        temp -> leftLink -> rightLink = temp -> rightLink;
        temp -> rightLink -> leftLink = temp -> leftLink;
        if(pos == 1)
          *head = temp -> leftLink;
      }
      else{
        printf("%d\n", (*head) -> data);
        (*head) -> leftLink -> rightLink = *rear;
        *head = (*head) -> leftLink;
        (*rear) -> leftLink = *head;
      }
      temp = NULL;
      free(temp);
    }
    *count -= 1;
  }
}


void searchDequeue(Node *head, Node *rear, int *count, int size, int element){
  if(*head == NULL)
    printf("Queue Empty.\n");
  else{
    int position = 1;
    Node current = *head;
    do{
      if(current -> data == element){
        dequeue(head, rear, count, size, position);
        return;
      }
      current = current -> leftLink;
      position += 1;
    }
    while(current != *head);
    printf("Element Not Found.\n");
  }
}


void display(Node head, Node rear){
  if(head == NULL){
    printf("\nQueue Empty.\n");
    return;
  }
  else{
    printf("The Queue:\n");
    Node current = head;
    do{
      printf("%d ", current -> data);
      current = current -> leftLink;
    }
    while(current != head);
  }
  printf("\n");
}


int main(){
  int size = 10, choice = 1, count = 0, temp;
  Node head = NULL;
  Node rear = NULL;
  while (choice){
    printf("1. Enqueue.\n2. Enqueue Anywhere.\n3. Search Enqueue.\n4. Dequeue.\n5. Dequeue Anywhere.\n6. Search Dequeue.\n7. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        enqueue(&head, &rear, &count, size, 0);
        break;
      case 2:
        if(count <= size){
          printf("Enter Position: ");
          scanf("%d", &temp);
        }
        enqueue(&head, &rear, &count, size, temp);
        break;
      case 3:
        printf("Enter Search Element: ");
        scanf("%d", &temp);
        searchEnqueue(&head, &rear, &count, size, temp);
        break;
      case 4:
        dequeue(&head, &rear, &count, size, 0);
        break;
      case 5:
        if(count <= size){
          printf("Enter Position: ");
          scanf("%d", &temp);
        }
        dequeue(&head, &rear, &count, size, temp);
        break;
      case 6:
        printf("Enter Search Element: ");
        scanf("%d", &temp);
        searchDequeue(&head, &rear, &count, size, temp);
        break;
      case 7:
        display(head, rear);
        break;
    }
    printf("\n");
  }
  return 0;
}
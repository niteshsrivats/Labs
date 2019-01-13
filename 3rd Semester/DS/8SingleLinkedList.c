// @author: K Nitesh Srivats
// @title: Single Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList *Node;

struct LinkedList {
    int data;
    struct LinkedList *link;
};


Node getNode() {
    Node newNode = (Node)malloc(sizeof(Node));
    printf("Enter Element to Enqueue: \n");
    scanf("%d", &(newNode -> data));
    newNode -> link = NULL;
    return newNode;
}


Node createNode(int *count) {
    *count = 0;
    Node newNode = NULL;
    printf("List Created. \n");
    return newNode;
}


void insert(Node *head, int *count, int size) {
    Node newNode = getNode();
    if(*head == NULL)
        *head = newNode;
    else {
        newNode -> link = *head;
        *head = newNode;
    }
}


void countNodes(Node head, int *count) {
    *count = 0;
    if (head != NULL) {
        Node temp = head;
        for(; temp != NULL; temp = temp -> link)
            *count += 1;
    }
    printf("Count: %d\n", *count);
}


void search(Node head) {
    int search, pos = 1, flag = 0;
    printf("Enter Search Element: ");
    scanf("%d", &search);
    if (head != NULL) {
        Node temp = head;
        for(; temp != NULL; temp = temp -> link) {
            if (temp -> data == search) {
                flag = 1;
                break;
            }
            pos += 1;
        }
    }
    if (flag == 1)
        printf("Element at Position: %d\n", pos);
    else
        printf("Element not found.\n");
}


int main() {
  int size = 3, choice = 1, count = 0;
  Node head = NULL;
  while (choice) {
    printf("1. Create List.\n2. Insert.\n3. Count.\n4. Search.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            head = createNode(&count);
            break;
        case 2:
            insert(&head, &count, size);
            break;
        case 3:
            countNodes(head, &count);
            break;
        case 4:
            search(head);
            break;
    }
    printf("\n");
  }
  return 0;
}

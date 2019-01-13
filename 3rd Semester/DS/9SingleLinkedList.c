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
    printf("Enter Element to Insert: \n");
    scanf("%d", &(newNode -> data));
    newNode -> link = NULL;
    return newNode;
}


void insert(Node *head, int *count, int size) {
    if(*count == size)
        printf("List Full.\n");
    else{
        Node newNode = getNode();
        if (newNode -> data == 0)
            return;
        *count += 1;
        if(*head == NULL)
            *head = newNode;
        else {
            newNode -> link = *head;
            *head = newNode;
        }
    }
}


void display(Node head) {
    if(head == NULL)
        printf("List Empty.\n");
    else{
        Node temp = head;
        printf("List:\n");
        for(;;temp = temp -> link){
            printf("%d ", temp -> data);
            if(temp -> link == NULL)
                break;
       }
    }
}


void reverse(Node *head) {
    if((*head) -> link != NULL){
        Node previous = NULL, current = *head, next = (*head) -> link;
        while(current -> link != NULL) {
            current -> link = previous;
            previous = current;
            current = next;
            next = next -> link;
        }
        current -> link = previous;
        *head = current;
    }
    printf("Reversed ");
    display(*head);
}


void sort(Node head) {
    if((head) -> link != NULL || head == NULL){
        Node temp, outer, inner;
        for(outer = head; outer != NULL; outer = outer -> link)
            for(inner = outer -> link; inner != NULL; inner = inner -> link)
                if(outer -> data > inner -> data){
                    temp -> data = outer -> data;
                    outer -> data = inner -> data;
                    inner -> data = temp -> data;
                }
    }
    printf("Sorted ");
    display(head);
}


void merge(Node *head) {
    Node head2 = NULL;
    Node temp = *head;
    int oldCount = 0, count = 0, size = 3;
    printf("Enter 0 to Exit.\n");
    while (oldCount == count) {
        insert(&head2, &count, size);
        oldCount += 1;
    }
    printf("Second ");
    display(head2);
    while (temp -> link != NULL)
        temp = temp -> link;
    temp -> link = head2;
    printf("\nMerged ");
    display(*head);
}


int main(){
  int size = 3, choice = 1, count = 0, temp;
  Node head = NULL;
  while (choice) {
    printf("1. Insert.\n2. Sort.\n3. Reverse.\n4. Merge.\n0. Exit.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            insert(&head, &count, size);
            break;
        case 2:
            sort(head);
            break;
        case 3:
            reverse(&head);
            break;
        case 4:
            merge(&head);
            break;
    }
    printf("\n");
  }
  return 0;
}

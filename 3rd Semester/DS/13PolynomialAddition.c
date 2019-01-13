#include<stdio.h>
#include<stdlib.h>

typedef struct PolyLL *Node;

struct PolyLL {
    int coeff, pow;
    struct PolyLL *link;
};

Node getNode() {
    Node newNode = (Node)malloc(sizeof(Node));
    printf("Enter Value & Power: ");
    scanf("%d %d", &(newNode -> coeff), &(newNode -> pow));
    newNode -> link = NULL;
    return newNode;
}

void insert(Node *head) {
    Node newNode = getNode();
    if(*head == NULL)
        *head = newNode;
    else {
        newNode -> link = *head;
        *head = newNode;
    }
}

void display(Node head) {
  Node temp = head;
  printf("\nThe Polynomial: ");
  while (temp != NULL) {
    printf("%dx^%d ", temp -> coeff, temp -> pow);
    temp = temp -> link;
  }
}

void addPoly(Node head1, Node head2, Node *head3) {
  *head3 = (Node)malloc(sizeof(Node));
  Node temp = *head3;
  if (head1 -> pow == head2 -> pow) {
      temp -> coeff = head1 -> coeff + head2 -> coeff;
      temp -> pow = head1 -> pow;
      head1 = head1 -> link;
      head2 = head2 -> link;
  }
  else {
    temp -> coeff = head1 -> coeff;
    temp -> pow = head1 -> pow;
    head1 = head1 -> link;
  }
  while (head1 != NULL && head2 != NULL) {
    temp -> link = (Node)malloc(sizeof(Node));
    temp = temp -> link;
    if (head1 -> pow == head2 -> pow) {
      temp -> coeff = head1 -> coeff + head2 -> coeff;
      temp -> pow = head1 -> pow;
      head1 = head1 -> link;
      head2 = head2 -> link;
    }
    else if (head1 -> pow > head2 -> pow) {
      temp -> coeff = head1 -> coeff;
      temp -> pow = head1 -> pow;
      head1 = head1 -> link;
    }
    else {
      temp -> coeff = head2 -> coeff;
      temp -> pow = head2 -> pow;
      head2 = head2 -> link;
    } 
  }
  while (head1 != NULL) {
    temp -> link = (Node)malloc(sizeof(Node));
    temp = temp -> link;
    temp -> coeff = head1 -> coeff;
    temp -> pow = head1 -> pow;
    head1 = head1 -> link;
   }

  while (head2 != NULL) {
    temp -> link = (Node)malloc(sizeof(Node));
    temp = temp -> link;
    temp -> coeff = head2 -> coeff;
    temp -> pow = head2 -> pow;
    head2 = head2 -> link;
  }

  printf("\nResult: ");
  display(*head3);
}

int main(int argc, char const *argv[]) {
  Node head1 = NULL;
  Node head2 = NULL;
  Node head3 = NULL;
  char choice = 'y';
  printf("Enter Polynomial 1: \n");
  while (choice == 'y') {
    insert(&head1);
    getchar();
    printf("continue (y/n)");
    scanf("%c", &choice);
  }
  display(head1);

  choice = 'y';
  printf("\nEnter Polynomial 2: \n");
  while (choice == 'y') {
    insert(&head2);
    printf("continue (y/n)");
    getchar();
    scanf("%c", &choice);
  }
  display(head2);
  if (head1 -> pow >= head2 -> pow) 
    addPoly(head1, head2, &head3);
  else 
    addPoly(head2, head1, &head3);
    
  return 0;
}


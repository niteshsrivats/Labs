#include <stdio.h>
#include <stdlib.h>

typedef struct Tree *Node;

struct Tree {
  int data;
  Node lst, rst;
};


void insert(Node *root, int data) {
  if (*root == NULL) {
    *root = (Node)malloc(sizeof(Node));
    (*root) -> data = data;
    (*root) -> lst = (*root) -> rst = NULL;
  }
  else if (data <= (*root) -> data)
    insert(&((*root) -> lst), data);
  else
    insert(&((*root) -> rst), data);
}


void inorder(Node root) {
  if (root != NULL) {
    inorder(root -> lst);
    printf("%d ", root -> data);
    inorder(root -> rst);
  }
}

void preorder(Node root) {
  if (root != NULL) {
    printf("%d ", root -> data);
    preorder(root -> lst);
    preorder(root -> rst);
  }
}

void postorder(Node root) {
  if (root != NULL) {
    postorder(root -> lst);
    postorder(root -> rst);
    printf("%d ", root -> data);
  }
}

void display(Node root, int level) {
  if (root == NULL)
    return;
  display(root -> rst, level + 1);
  for (int i = 0; i < level; i++)
    printf("  ");
  printf("%d\n", root -> data);
  display(root -> lst, level + 1);
}

int main(int argc, char const *argv[]) {
  int choice = 1, data;
  Node treeRoot = NULL;
  while (choice) {
    printf("1. Insert.\n2. Traverse.\n3. Display.\n0. Exit.\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter Data: ");
        scanf("%d", &data);
        insert(&treeRoot, data);
        break;
      case 2:
        printf("Inorder: ");
        inorder(treeRoot);
        printf("\nPreorder: ");
        preorder(treeRoot);
        printf("\nPostorder: ");
        postorder(treeRoot);
        break;
      case 3:
        printf("The Tree:\n");
        display(treeRoot, 1);
        break;
    }
    printf("\n");
  }
  return 0;
}

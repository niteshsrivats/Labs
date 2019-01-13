// @author: K Nitesh Srivats
// @title: Stack as Array

#include<stdio.h>

void push(int *stack, int *top, int max) {
    if (*top == max - 1) 
        printf("Stack Overflow.\n\n");
    else {
        *top += 1;
        printf("Enter Element: ");
        scanf("%d", (stack + *top));
        printf("\n\n");
    }
}


void pop(int *stack, int *top) {
    if (*top == -1) 
        printf("Stack Underflow.\n\n");
    else {
        printf("Popping: %d\n\n", *(stack + *top));
        *top -= 1;
    }
}


void display(int *stack, int *top) {
    if (*top == -1) 
        printf("Stack Empty.\n\n");
    else {
        printf("The Stack:");
        for(int i = 0; i <= *top; i++)
            printf(" %d", *(stack + i));
        printf("\n\n");
    }
}


int main(int argc, char const *argv[])
{
    int choice = 1, top = -1, max = 3, stack[10]; 
    while (choice) {
        printf("1. Push.\n2. Pop.\n3. Display.\n0. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(stack, &top, max);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
        }
    }
    return 0;
}

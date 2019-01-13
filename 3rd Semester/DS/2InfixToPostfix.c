// @author: K Nitesh Srivats
// @title: Infix to Postfix Conversion

#include<stdio.h>

int encoder(char ch) {
    if (ch == '/')
        return 3;
    else if (ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}


void result_push(char *stack, char *result, int *topStack, int *topRes) {
    *topRes += 1;
    *(result + *topRes) = *(stack + *topStack);
    *topStack -= 1;
}


void stack_push(char *stack, int *topStack, char ch) {
    *topStack += 1;
    *(stack + *topStack) = ch;
}


void convert(char *stack, char *result, int *topStack, int *topRes, char ch) {
    if (ch == '(' || encoder(*(stack + *topStack)) < encoder(ch)) 
        stack_push(stack, topStack, ch);
    else if (ch == ')') {
        while (*(stack + *topStack) != '(')
            result_push(stack, result, topStack, topRes);
        *topStack -= 1;
    }
    else if (encoder(ch) == 0) {
        *topRes += 1;
        *(result + *topRes) = ch;
    }
    else {
        while(encoder(*(stack + *topStack)) >= encoder(ch))
            result_push(stack, result, topStack, topRes);
        stack_push(stack, topStack, ch);
    }
}


int main(int argc, char const *argv[]) {
    char infix[30], stack[30], result[30];
    int topStack = -1, topRes = -1;
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    for (int i = 0; infix[i] != '\0'; i++) 
        convert(stack, result, &topStack, &topRes, infix[i]);
    while (topStack != -1)
        result_push(stack, result, &topStack, &topRes);
    printf("%s\n", result);
    return 0;
}

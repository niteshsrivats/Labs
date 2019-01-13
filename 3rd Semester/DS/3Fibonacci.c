// @author: K Nitesh Srivats
// @title: Recursive Fibonacci

#include<stdio.h>

int fibo(int n) {
    if (n < 2)
        return n;
    return fibo(n-1) + fibo(n-2);
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter Term: ");
    scanf("%d", &n);
    printf("%d\n", fibo(n));
    return 0;
}

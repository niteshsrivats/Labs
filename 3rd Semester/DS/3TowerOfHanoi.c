// @author: K Nitesh Srivats
// @title: Recursive Solution to Towers of Hanoi

#include<stdio.h>

void TowerOfHanoi(int n, char src, char des, char aux) {
    if (n > 0) {
        TowerOfHanoi(n-1, src, aux, des); 
        printf("Move disk %d from %c to %c\n", n, src, des);
        TowerOfHanoi(n-1, aux, des, src);
    }
}

int main(int argc, char const *argv[])
{
    TowerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}

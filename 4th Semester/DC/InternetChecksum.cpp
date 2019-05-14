#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int length = 8, firstHalfSum = 0, secondHalfSum = 0;
    char message[] = "Forouzan";
    for(int i = 0; i < length; i += 2){
        firstHalfSum += message[i];
        secondHalfSum += message[i + 1];
    }
    firstHalfSum += secondHalfSum / 256;
    secondHalfSum %= 256;
    int sum = secondHalfSum + ((firstHalfSum%256) << 8) + firstHalfSum / 256;
    printf("%0x\n%0x\n",sum, ~sum);
    return 0;
}
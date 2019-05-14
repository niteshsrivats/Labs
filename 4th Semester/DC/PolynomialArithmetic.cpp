#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

char* add(char* poly1, char* poly2, int length) {
    char* result = new char[length];

    for (int i = 0; i < length; i++)
        result[i] = (poly1[i] == poly2[i]) ? '0' : '1';
    return result;
}

char* multiply(char* poly1, char* poly2, int length) {
    char *result = new char[length * 2 - 1];
    // result[length * 2 - 1] = '\0';

    for (int i = 0; i < length * 2 - 1; i++)
        result[i] = '0';
    for (int i = 0; i < length; i++)
        if (poly1[i] != '0')
            for (int j = 0; j < length; j++)
                if (poly2[j] == '1')
                    result[i + j] = result[i + j] == '1' ? '0' : '1';
    return result;
}

void print(char* poly) {
    int i = 0;
    for (; poly[i] != '\0'; i++)
        if (poly[i] == '1') {
            if (i == 0)
                cout << "1";
            else
                cout << "x^" << i;
            i++;
            break;
        }
    for (;poly[i] != '\0'; i++)
        if (poly[i] == '1')
            cout << " + x^" << i;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int length;
    cout << "Enter Number of Bits: ";
    cin >> length;
    char* poly1 = new char[length];
    char* poly2 = new char[length];
    cout << "\nEnter Polynomial 1: ";
    cin >> poly1;
    print(poly1);
    cout << "\nEnter Polynomial 2: ";
    cin >> poly2;
    print(poly2);
    cout << "\nSum: ";
    print(add(poly1, poly2, length));
    cout << "\nProduct: ";
    print(multiply(poly1, poly2, length));
    return 0;
}
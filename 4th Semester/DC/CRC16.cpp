#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

int main() {
    char dataWithCRC[MAX], message[MAX], received[MAX], remainder[16], syndrome[16];
    // x^16 + x^12 + x^5 + 1
    char div[] = "10001000000100001";
    int i, j, k, len;

    cout << "Enter Message: ";
    cin >> message;
    strcpy(dataWithCRC, message);
    len = strlen(dataWithCRC);
    
    for(i = len ; i < len + 16 ; i++)
        dataWithCRC[i] = '0';
    dataWithCRC[i] = '\0';

    // Division for geting 16 bit remainder
    for(i = 0 ; i < len ; i++) {
        j = i;
        if(dataWithCRC[j] == '0')
            continue;
        for(k = 0 ; k < 17; k++) {
            dataWithCRC[j] = dataWithCRC[j] == div[k] ? '0' : '1';
            j++;
        }
    }
    strcpy(remainder, &dataWithCRC[len]);
    // Data With CRC = Message + Remainder
    strcpy(dataWithCRC, message);
    strcpy(&dataWithCRC[len], remainder);
    cout << "Data With CRC: " << dataWithCRC << endl;
    cout << "CRC: " << remainder << endl;

    cout << "Enter Received Data: ";
    cin >> received;
    len = strlen(received) - 16;
    for(i = 0 ; i < len; i++) {
        j = i;
        if(received[j] == '0')
            continue;
        for(k = 0 ; k < 17; k++) {
            received[j] = received[j] == div[k] ? '0' : '1';
            j++;
        }
    }

    strcpy(syndrome, &received[len]);
    cout << "Syndrome: " << syndrome << endl;
    for(i = 0 ; i < 16 ; i++)
        if(syndrome[i] == '1') {
            cout<<"Improper transmission\n";
            return 0;
        }
    cout<<"Proper transmission\n";
    return 0;
}

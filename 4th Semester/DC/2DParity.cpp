#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{ 
    int numRows, parity, i;
    cout << "Enter Number of Rows of Data: ";
    cin >> numRows;
    int data[numRows + 1][8], received[numRows + 1][8];

    for (i = 0; i < numRows; i++) {
        cout << "Enter Row " << i + 1 << ": ";
        parity = 0;
        for (int j = 0; j < 7; j ++) {
            cin >> data[i][j];
            parity += data[i][j];
        }
        data[i][7] = parity % 2;
    }

    for (int j = 0; j < 7; j++) {
        parity = 0;
        for (i = 0; i < numRows; i++)
            parity += data[i][j];
        data[numRows][j] = parity % 2;
    }

    parity = 0;
    for (int j = 0; j < 7; j++)
        parity += data[numRows][j];
    data[numRows][7] = parity % 2;


    cout << "Transmitted Data: \n";
    for (i = 0; i <= numRows; i++) {
        for (int j = 0; j < 8; j ++) 
            cout << data[i][j] << " ";
        cout << endl;
    }

    cout << "Enter Received Data: ";
    for (i = 0; i <= numRows; i++) {
        cout << "Enter Byte " << i + 1 << ": ";
        for (int j = 0; j < 8; j ++)
            cin >> received[i][j];
    }

    int rowParity = 0;
    for (int j = 0; j < 7; j ++) {
        parity = 0;
        for (i = 0; i <= numRows; i++) {
            if (i != numRows) {
                rowParity = 0;
                for (int k = 0; k < 8; k++)
                    rowParity += received[i][k];
                if (rowParity % 2) {
                    cout << "Error in Transmission\n";
                    return 0;
                }
            }
            parity += received[i][j];
        }
        if (parity % 2) {
            cout << "Error in Transmission\n";
            return 0;
        } 
    }
    cout << "No Error in Transmission\n";
    return 0;
}
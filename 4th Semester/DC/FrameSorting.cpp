#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct frame {
    int frameNumber;
    char* data;
};

char* padding(char* message, int size) {
    char* result = new char[size];
    for (int i = 0; i < strlen(message); i ++)
        result[i] = message[i];
    for (int i = strlen(message); i < size; i++)
        result[i] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    char* message = new char[50];
    int size, numFrames;
    cout << "Enter Message: ";
    cin >> message;
    cout << "Enter Number of Characters per Frame: ";
    cin >> size;
    numFrames = ceil(strlen(message) / (size * 1.0));
    message = padding(message, numFrames * size);
    struct frame* frames = new frame[numFrames];
    
    // Framing
    for (int i = 0; i < numFrames; i++) {
        frames[i].frameNumber = i;
        frames[i].data = new char[size];
        for (int j = 0; j < size; j++)
            frames[i].data[j] = message[(i * size) + j];
    }

    // Shuffling
    struct frame temp;
    int randomIndex1, randomIndex2;
    for (int i = 0; i < 100; i++) {
        randomIndex1 = rand() % numFrames;
        randomIndex2 = rand() % numFrames;
        temp = frames[randomIndex1];
        frames[randomIndex1] = frames[randomIndex2];
        frames[randomIndex2] = temp;
    }

    // Bubble Sort
    for (int i = 0; i < numFrames; i++)
        for (int j = 0; j < numFrames - i - 1; j++)
            if (frames[j + 1].frameNumber < frames[j].frameNumber) {
                temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }

    for (int i = 0; i < numFrames; i++)
        cout << frames[i].data;
    cout << endl;
    return 0;
}
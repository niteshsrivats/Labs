#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int xmax, ymax, number;
    int* bitArray;

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, NULL);

    setcolor(getmaxcolor());
    xmax = getmaxx();
    ymax = getmaxy();

    setlinestyle(DOTTED_LINE, 0, 0);
    line(0, 0, 0, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    cout << "Enter Number of Bits: ";
    cin >> number;
    bitArray = new int[number];

    cout << "Enter the Bits: ";
    for (int i = 0; i < number; i++)
        cin >> bitArray[i];

    for (int i = 0; i < number; i++)
      line(i * 100, 0, i * 100, ymax);

    setlinestyle(SOLID_LINE, 0, 0);
    lineto(0, ymax / 2);
    int prev = 1;

    for (int i = 0; i < number; i++) {
        if (bitArray[i]) {
           linerel(0, 100 * prev);
           linerel(100, 0);
           linerel(0, -100 * prev);
           prev *= -1;
        }
        else {
            linerel(100, 0);
        }
    }
    getch();
    closegraph();
    return 0;
}
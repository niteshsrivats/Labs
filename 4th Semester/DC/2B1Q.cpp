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
    lineto(0, ymax / 2 - 50);
    // Previous Positive 1 or 0
    int prevPositive = 1, previousLevel = 1, currentPositive, currentLevel;

    for (int i = 0; i < number; i++) {
        // Current Positive 1 or -1
        currentPositive = (bitArray[i] + prevPositive) % 2;
        prevPositive = currentPositive;
        if (!currentPositive)
            currentPositive = -1;
        i += 1;
        if (bitArray[i])
            currentLevel = 3 * currentPositive;
        else
            currentLevel = 1 * currentPositive;
        linerel(0, (previousLevel - currentLevel) * 50);
        linerel(100, 0);
        previousLevel = currentLevel;
    }
    getch();
    closegraph();
    return 0;
}
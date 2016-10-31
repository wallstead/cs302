#ifndef BUBBLE_H // make sure we don't redefine class
#define BUBBLE_H

#include <iostream>
#include <ctime> // for keeping track of time

using namespace std;

class Bubble {
public:
    Bubble(int toSort[], int count);
    void sort();

    friend ostream& operator<<(ostream& out, const Bubble& bubble);

    int count;
    int *data;
    double elapsedTime; // CPU time specifically
    int comparisonCount;
    int swapCount;
};

#endif

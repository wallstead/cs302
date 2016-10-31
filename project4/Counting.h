#ifndef Counting_H // make sure we don't redefine class
#define Counting_H

#include <iostream>
#include <ctime> // for keeping track of time

using namespace std;

class Counting {
public:
    Counting(int toSort[], int count);
    void sort();
    double timePassed();

    friend ostream& operator<<(ostream& out, const Counting& Counting);

private:
    int count;
    int *countingArray;
    int *data;
    double elapsedTime; // CPU time specifically
    int comparisonCount;
    int swapCount;
};

#endif

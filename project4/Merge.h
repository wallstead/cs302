#ifndef MERGE_H // make sure we don't redefine class
#define MERGE_H

#include <iostream>
#include <ctime> // for keeping track of time

using namespace std;

class Merge {
public:
    Merge(int toSort[], int count);
    void merge(int first, int mid, int last);
    void sort(int first, int last);
    double timePassed();

    friend ostream& operator<<(ostream& out, const Merge& merge);

private:
    int count;
    int *data;
    double elapsedTime; // CPU time specifically
    int comparisonCount;
    int swapCount;
};

#endif

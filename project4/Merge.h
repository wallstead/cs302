#ifndef MERGE_H // make sure we don't redefine class
#define MERGE_H

#include <iostream>
#include <ctime> // for keeping track of time

using namespace std;

class Merge {
public:
    Merge(int toSort[], long count);
    void merge(long first, long mid, long last);
    void sort(long first, long last);

    friend ostream& operator<<(ostream& out, const Merge& merge);

    int count;
    int *data;
    double elapsedTime; // CPU time specifically
    int comparisonCount;
    int swapCount;
};

#endif

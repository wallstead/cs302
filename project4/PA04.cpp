#include <iostream>
#include <string>
#include <fstream>
#include "Bubble.h"
#include "Merge.h"
#include "Counting.h"

using namespace std;

int main() {

    // O(n^2) -> Bubble
    // O(nlog(n)) -> Merge
    // O(n) -> Counting

    /* get the 1,000 random numbers */
    int randThousand[1000];
    ifstream thousandFile("rand_1,000");
    if (thousandFile.is_open()) {
        int number; // holds number on each line
        int counter = 0; // increment throught randThousand array
        while(thousandFile >> number) {
            // cout << counter << ": " << number << endl;
            randThousand[counter] = number; // add it to array
            counter++;
        }
        thousandFile.close();
    } else {
        cout << "Cannot open thousand integer file";
    }

    /* get the 10,000 random numbers */
    int randTenThousand[10000];
    ifstream tenThousandFile("rand_10,000");
    if (tenThousandFile.is_open()) {
        int number; // holds number on each line
        int counter = 0; // increment throught randTenThousand array
        while(tenThousandFile >> number) {
            // cout << counter << ": " << number << endl;
            randTenThousand[counter] = number; // add it to array
            counter++;
        }
        tenThousandFile.close();
    } else {
        cout << "Cannot open ten thousand integer file";
    }

    /* get the 100,000 random numbers */
    int randHundredThousand[100000];
    ifstream hundredThousandFile("rand_100,000");
    if (hundredThousandFile.is_open()) {
        int number; // holds number on each line
        int counter = 0; // increment throught randHundredThousand array
        while(hundredThousandFile >> number) {
            // cout << counter << ": " << number << endl;
            randHundredThousand[counter] = number; // add it to array
            counter++;
        }
        hundredThousandFile.close();
    } else {
        cout << "Cannot open hundred thousand integer file";
    }

    /* get the 1,000,000 random numbers */
    int *randMillion = new int[1000000]; // to avoid stack overflow
    ifstream millionFile("rand_1,000,000");
    if (millionFile.is_open()) {
        int number; // holds number on each line
        int counter = 0; // increment throught randMillion array
        while(millionFile >> number) {
            // cout << counter << ": " << number << endl;
            randMillion[counter] = number; // add it to array
            counter++;
        }
        millionFile.close();
    } else {
        cout << "Cannot open million integer file";
    }


    /*
        Just have a table listing timing of each algorithm for each run of
        random and sorted inputs. At the bottom of the table average of the
        10 runs. Do this for every algorithm.
    */

    /* run bubble sort 10 times for 1,000 random numbers, average totals */

    /* Working Bubble Sort */
    // long totalCPUTime = 0;
    // long totalSwapCount;
    // long totalComparisonCount;
    //
    // for (int i = 0; i < 10; i++) {
    //     Bubble bubble = Bubble(randTenThousand, 10000); // sort random array using bubble sort
    //     bubble.sort();
    //     totalCPUTime += bubble.timePassed();
    //     cout << "[" << i+1 << "]" << endl << bubble  << "------------------------" << endl;
    // }
    // cout << "Average elapsed CPU time: " << long(totalCPUTime/10) << endl;

    /* Not-Fully-Working Merge Sort */
    // long totalCPUTime = 0;
    // long totalSwapCount;
    // long totalComparisonCount;
    //
    // for (int i = 0; i < 10; i++) {
    //     Merge merge = Merge(randHundredThousand, 100000); // sort random array using merge sort
    //     merge.sort(0, 100000-1);
    //     totalCPUTime += merge.timePassed();
    //     cout << "[" << i+1 << "]" << endl << merge  << "------------------------" << endl;
    // }
    // cout << "Average elapsed CPU time: " << double(totalCPUTime/10) << endl;


    /* Not-Working Counting Sort */
    long totalCPUTime = 0;
    long totalSwapCount;
    long totalComparisonCount;

    for (int i = 0; i < 10; i++) {
        Counting counting = Counting(randThousand, 1000); // sort random array using merge sort
        counting.sort();
        
        totalCPUTime += counting.timePassed();
        cout << "[" << i+1 << "]" << endl << counting  << "------------------------" << endl;
    }
    cout << "Average elapsed CPU time: " << double(totalCPUTime/10) << endl;

    return 0;
}

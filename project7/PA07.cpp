/**
 * @file PA07.cpp
 *
 * @brief Main driver for project 7
 *
 * @author Willis Allstead
 *
 * @version 1.0
 *
 */

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

bool existsInArray(int toCheck, int arr[], int count);

void visit(int &visited) {
  cout << visited << endl;
}

const int numValues = 1000;

int main() {
  /* Randomly generate 1000 unique values in the range of [1-10,000] */
  int randArr[numValues];
  int max = 10000;
  for (int index = 0; index < numValues; index++) {
      int random_int;
      do {
        random_int = (rand()%(max-1))+1; // from 1 to 10,000
      } while (existsInArray(random_int, randArr, index)); // inefficient
      // cout << random_int << endl;
      randArr[index] = random_int;
  }

  /* Insert them into a binary search tree (BST1) */
  RedBlackTree<int> RBT1;

  for (int i = 0; i < numValues; i++) {
    RBT1.add(i);
    cout << "height after adding: " << i << ": "<< RBT1.getHeight() << endl; //DEBUG ONLY
  }

  cout << RBT1.getHeight() << endl;
//

  return 0;
}

bool existsInArray(int toCheck, int arr[], int count) {
  for (int i = 0; i < count; i++) {
    if (arr[i] == toCheck) {
      return true;
    }
  }
  return false;
}

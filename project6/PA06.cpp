/**
 * @file PA06.cpp
 *
 * @brief Main driver for project 6
 *
 * @author Willis Allstead
 *
 * @version 1.0
 *
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void visit(int &visited) {
  cout << visited << endl;
}

int main() {
  BinarySearchTree<int> bSearchTree;

  for (int i = 0; i < 100; i+=2) {
    bSearchTree.add(i);
    cout << "height after adding: " << i << ": "<< bSearchTree.getHeight() << endl;
  }

  // cout << "height after adding 100 more nodes: " << bSearchTree.getHeight() << endl;

  return 0;
}

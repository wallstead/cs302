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
#include "BinaryNode.h"

using namespace std;

int main() {
  BinaryNode<float> *bnode = new BinaryNode<float>[1];
  bnode->setItem(99);
  cout << bnode->getItem() << endl;
  cout << bnode->isLeaf() << endl;




  return 0;
}

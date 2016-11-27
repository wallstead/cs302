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
#include "BinaryNodeTree.h"

using namespace std;

void visit(int &visited) {
  cout << visited << endl;
}

int main() {
  BinaryNodeTree<int> bNodeTree;

  bNodeTree.add(9);
  bNodeTree.add(1);
  bNodeTree.add(18);
  bNodeTree.add(22);

  bNodeTree.postorderTraverse(visit);

  return 0;
}

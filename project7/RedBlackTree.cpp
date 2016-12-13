/**
 * @file RedBlackTree.cpp
 *
 * @brief Implementation file for the Binary Search Tree class
 *
 * @author Willis Allstead
 *
 * @version 0.5
 *
 */

template<class ItemType>
RedBlackTree<ItemType>::RedBlackTree() {
  rootPtr = nullptr;
}

template<class ItemType>
RedBlackTree<ItemType>::~RedBlackTree() {

}

template<class ItemType>
void RedBlackTree<ItemType>::rotateLeft(BinaryNode<ItemType> *x) {
  // node y;
  BinaryNode<ItemType> *y;
  // y = x->right;
  y = x->getRightChildPtr();
  // /* Turn y's left sub-tree into x's right sub-tree */
  // x->right = y->left;
  x->setRightChildPtr(y->getLeftChildPtr());
  // if (y->left != nullptr)
  if (y->getLeftChildPtr() != nullptr) {
    // y->left->getParentPtr() = x;
    y->getLeftChildPtr()->setParentPtr(x);
  }
  // /* y's new parent was x's parent */
  // y->getParentPtr() = x->getParentPtr();
  y->setParentPtr(x->getParentPtr());
  // /* Set the parent to point to y instead of x */
  // /* First see whether we're at the root */
  // if ( x->getParentPtr() == NULL ) T->root = y;
  if (x->getParentPtr() == nullptr) {
    rootPtr = y;
  } else { // else
    // if ( x == (x->getParentPtr())->left )
    if (x == (x->getParentPtr()->getLeftChildPtr())) {
      // /* x was on the left of its parent */
      // x->getParentPtr()->left = y;
      x->getParentPtr()->setLeftChildPtr(y);
    } else { // else
      // /* x must have been on the right */
      // x->getParentPtr()->right = y;
      x->getParentPtr()->setRightChildPtr(y);
    }
  }
  // /* Finally, put x on y's left */
  // y->left = x;
  y->setLeftChildPtr(x);
  // x->getParentPtr() = y;
  x->setParentPtr(y);
}

template<class ItemType>
void RedBlackTree<ItemType>::rotateRight(BinaryNode<ItemType> *x) {
  // node y;
  BinaryNode<ItemType> *y;
  // y = x->right;
  y = x->getLeftChildPtr();
  // /* Turn y's left sub-tree into x's right sub-tree */
  // x->right = y->left;
  x->setLeftChildPtr(y->getRightChildPtr());
  // if (y->left != nullptr)
  if (y->getRightChildPtr() != nullptr) {
    // y->left->getParentPtr() = x;
    y->getRightChildPtr()->setParentPtr(x);
  }
  // /* y's new parent was x's parent */
  // y->getParentPtr() = x->getParentPtr();
  y->setParentPtr(x->getParentPtr());
  // /* Set the parent to point to y instead of x */
  // /* First see whether we're at the root */
  // if ( x->getParentPtr() == NULL ) T->root = y;
  if (x->getParentPtr() == nullptr) {
    rootPtr = y;
  } else { // else
    // if ( x == (x->getParentPtr())->left )
    if (x == (x->getParentPtr()->getRightChildPtr())) {
      // /* x was on the left of its parent */
      // x->getParentPtr()->left = y;
      x->getParentPtr()->setRightChildPtr(y);
    } else { // else
      // /* x must have been on the right */
      // x->getParentPtr()->right = y;
      x->getParentPtr()->setLeftChildPtr(y);
    }
  }
  // /* Finally, put x on y's left */
  // y->left = x;
  y->setRightChildPtr(x);
  // x->getParentPtr() = y;
  x->setParentPtr(y);
}

template<class ItemType>
void RedBlackTree<ItemType>::insertNode(BinaryNode<ItemType> *x) {
  // /* Insert in the tree in the usual way */
  // tree_insert( T, x );
  rootPtr = BinarySearchTree<ItemType>::placeNode(rootPtr, x);
  // /* Now restore the red-black property */
  // x->color = red;

  // std::cout << "inserting: " << x->getItem() << std::endl;

  x->color = red;
  // while ( (x != T->root) && (x->getParentPtr()->color == red) ) {
  while ((x != rootPtr) && (x->getParentPtr()->color == red)) {
    if ( x->getParentPtr() == x->getParentPtr()->getParentPtr()->getLeftChildPtr() ) {
      // /* If x's parent is a left, y is x's right 'uncle' */
      // y = x->getParentPtr()->getParentPtr()->right;
      BinaryNode<ItemType> *y = x->getParentPtr()->getParentPtr()->getRightChildPtr();
      // if ( y->color == red )
      if (y != nullptr && y->color == red) {
        /* case 1 - change the colors */
        // x->getParentPtr()->color = black;
        x->getParentPtr()->color = black;
        // y->color = black;
        y->color = black;
        // x->getParentPtr()->getParentPtr()->color = red;
        x->getParentPtr()->getParentPtr()->color = red;
        // /* Move x up the tree */
        // x = x->getParentPtr()->getParentPtr();
        x = x->getParentPtr()->getParentPtr();
      } else { // is black (or null)
        /* y is a black node */
        // if ( x == x->getParentPtr()->right )
        if (x == x->getParentPtr()->getRightChildPtr()) {
          /* and x is to the right */
          // /* case 2 - move x up and rotate */
          // x = x->getParentPtr();
          x = x->getParentPtr();
          // left_rotate( T, x );
          rotateLeft(x);
        }
        // /* case 3 */
        // x->getParentPtr()->color = black;
        x->getParentPtr()->color = black;
        // x->getParentPtr()->getParentPtr()->color = red;
        x->getParentPtr()->getParentPtr()->color = red;
        // right_rotate( T, x->getParentPtr()->getParentPtr() );
        rotateRight(x->getParentPtr()->getParentPtr());
      }
    } else { // RIGHT AND LEFT EXCHANGED FROM PRIOR IF
      // /* If x's parent is a right, y is x's left 'uncle' */
      // y = x->getParentPtr()->getParentPtr()->left;
      BinaryNode<ItemType> *y = x->getParentPtr()->getParentPtr()->getLeftChildPtr();
      // if ( y->color == red )x
      if (y != nullptr && y->color == red) {
        /* case 1 - change the colors */
        // x->getParentPtr()->color = black;
        x->getParentPtr()->color = black;
        // y->color = black;
        y->color = black;
        // x->getParentPtr()->getParentPtr()->color = red;
        x->getParentPtr()->getParentPtr()->color = red;
        // /* Move x up the tree */
        // x = x->getParentPtr()->getParentPtr();
        x = x->getParentPtr()->getParentPtr();
      } else {
        /* y is a black node */
        // if ( x == x->getParentPtr()->left )
        if (x == x->getParentPtr()->getLeftChildPtr()) {
          /* and x is to the left */
          // /* case 2 - move x up and rotate */
          // x = x->getParentPtr();
          x = x->getParentPtr();
          // right_rotate( T, x );
          rotateRight(x);
        }
        // /* case 3 */
        // x->getParentPtr()->color = black;
        x->getParentPtr()->color = black;
        // x->getParentPtr()->getParentPtr()->color = red;
        x->getParentPtr()->getParentPtr()->color = red;
        // left_rotate( T, x->getParentPtr()->getParentPtr() );
        rotateLeft(x->getParentPtr()->getParentPtr());
      }
    }
  }

  //
  // /* color the root black */
  // T->root->color = black;
  rootPtr->color = black;
  std::cout << "--------" << std::endl;
}

template<class ItemType>
bool RedBlackTree<ItemType>::isEmpty() const {
  return (rootPtr == nullptr);
}

template<class ItemType>
int RedBlackTree<ItemType>::getHeight() const {
  return BinaryNodeTree<ItemType>::getHeightHelper(rootPtr);
}

template<class ItemType>
int RedBlackTree<ItemType>::getNumberOfNodes() const {
  return BinaryNodeTree<ItemType>::getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType RedBlackTree<ItemType>::getRootData() const {
  return rootPtr->getItem();
}

template<class ItemType>
void RedBlackTree<ItemType>::setRootData(ItemType &newEntry) {
  return rootPtr->setItem(newEntry);
}

template<class ItemType>
bool RedBlackTree<ItemType>::add(const ItemType &newData) {
  BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>();
  newNodePtr->setItem(newData);

  insertNode(newNodePtr);

  return true;
}

template<class ItemType>
bool RedBlackTree<ItemType>::remove(const ItemType &target) {
  bool isSuccessful = false;
  rootPtr = removeValue(rootPtr, target, isSuccessful);
  return isSuccessful;
}

template<class ItemType>
void RedBlackTree<ItemType>::clear() {
  clearTree(rootPtr);
  rootPtr = nullptr;
}

// Traversals will stay the same for red-black trees

template<class ItemType>
void RedBlackTree<ItemType>::preorderTrav(void visit(ItemType&)) const {
  BinaryNodeTree<ItemType>::preorder(visit, rootPtr);
}

template<class ItemType>
void RedBlackTree<ItemType>::inorderTrav(void visit(ItemType&)) const {
  BinaryNodeTree<ItemType>::inorder(visit, rootPtr);
}

template<class ItemType>
void RedBlackTree<ItemType>::postorderTrav(void visit(ItemType&)) const {
  BinaryNodeTree<ItemType>::postorder(visit, rootPtr);
}

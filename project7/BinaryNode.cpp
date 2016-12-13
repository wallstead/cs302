/**
 * @file BinaryNode.cpp
 *
 * @brief Implementation file for the Binary Node class
 *
 * @author Willis Allstead
 *
 * @version 0.5
 *
 */

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() {
  leftChildPtr = nullptr; // initialize both to null initially
  rightChildPtr = nullptr;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType &anItem) {
  item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  // if no children, return true
  return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr)); 
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
  return leftChildPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
  return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr) {
  leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> *rightPtr) {
  rightChildPtr = rightPtr;
}

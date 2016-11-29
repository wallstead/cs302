#ifndef BINARY_NODE_
#define BINARY_NODE_

template<class ItemType>
class BinaryNode {
private:
  ItemType item;
  BinaryNode<ItemType> *leftChildPtr;
  BinaryNode<ItemType> *rightChildPtr;

public:
  BinaryNode();
  // ~BinaryNode();

  void setItem(const ItemType &anItem);
  ItemType getItem() const;

  bool isLeaf() const;

  BinaryNode<ItemType>* getLeftChildPtr() const;
  BinaryNode<ItemType>* getRightChildPtr() const;

  void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
  void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
};

#include "BinaryNode.cpp"
#endif

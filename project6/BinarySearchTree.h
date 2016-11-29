#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include "BinaryNodeTree.h"

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
  BinaryNode<ItemType> *rootPtr;

protected:
  BinaryNode<ItemType>* placeNode(BinaryNode<ItemType> *subTreePtr,
                                  BinaryNode<ItemType> *newNodePtr);
  BinaryNode<ItemType>* removeValue(BinaryNode<ItemType> *subTreePtr,
                                    const ItemType &target,
                                    bool &isSuccessful);
  BinaryNode<ItemType>* removeNode(BinaryNode<ItemType> *nodeToRemovePtr);
  BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType> *nodePtr,
                                           ItemType &inorderSuccessor);
  BinaryNode<ItemType>* findNode(BinaryNode<ItemType> *treePtr,
                                 const ItemType &target) const;

public:
  BinarySearchTree();
  ~BinarySearchTree();

  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;
  ItemType getRootData() const; // TODO: make this throw for safety
  void setRootData(ItemType &newEntry);
  bool add(const ItemType &newData);
  bool remove(const ItemType &target); // TODO: implement this
  void clear();
  ItemType getEntry(const ItemType &anEntry) const; // TODO: make this throw for safety
};

#include "BinarySearchTree.cpp"
#endif

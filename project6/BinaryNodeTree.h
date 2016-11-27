#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <algorithm>    // for std::max, which is used in book's code
#include "BinaryNode.h"

template<class ItemType>
class BinaryNodeTree {
private:
  BinaryNode<ItemType> *rootPtr;

protected:
  int getHeightHelper(BinaryNode<ItemType> *subTreePtr) const;
  int getNumberOfNodesHelper(BinaryNode<ItemType> *subTreePtr) const;
  BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType> *subTreePtr,
                                    BinaryNode<ItemType> *newNodePtr);
  BinaryNode<ItemType>* removeValue(BinaryNode<ItemType> *subTreePtr,
                                    const ItemType target,
                                    bool &isSuccessful);
  BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType> *subTreePtr);
  BinaryNode<ItemType>* findNode(BinaryNode<ItemType> *treePtr,
                                 const ItemType &target,
                                 bool &isSuccessful) const;
  BinaryNode<ItemType>* copyTree(BinaryNode<ItemType> *oldTreePtr) const;
  void destroyTree(BinaryNode<ItemType> *subTreePtr);

  void preorder(void visit(ItemType&), BinaryNode<ItemType> *treePtr) const;
  void inorder(void visit(ItemType&), BinaryNode<ItemType> *treePtr) const;
  void postorder(void visit(ItemType&), BinaryNode<ItemType> *treePtr) const;

public:
  BinaryNodeTree();
  ~BinaryNodeTree();

  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;
  ItemType getRootData() const;
  void setRootData(const ItemType &newData);
  bool add(const ItemType &newData); // adds item to tree
  bool remove(const ItemType &data); // removes item from treePtr
  void clear();
  ItemType getEntry(const ItemType &anEntry) const;
  bool contains(const ItemType &anEntry) const;

  void preorderTraverse(void visit(ItemType&)) const;
  void inorderTraverse(void visit(ItemType&)) const;
  void postorderTraverse(void visit(ItemType&)) const;

  BinaryNodeTree& operator=(const BinaryNodeTree &rhs);
};

#include "BinaryNodeTree.cpp"
#endif

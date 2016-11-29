template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
  rootPtr = nullptr;
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {

}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(
                                BinaryNode<ItemType> *subTreePtr,
                                BinaryNode<ItemType> *newNodePtr) {
  if (subTreePtr == nullptr) {
    return newNodePtr;
  } else if (subTreePtr->getItem() > newNodePtr->getItem()) {
    BinaryNode<ItemType> *tempPtr = placeNode(subTreePtr->getLeftChildPtr(),
                                              newNodePtr);
    subTreePtr->setLeftChildPtr(tempPtr);
  } else {
    BinaryNode<ItemType> *tempPtr = placeNode(subTreePtr->getRightChildPtr(),
                                              newNodePtr);
    subTreePtr->setRightChildPtr(tempPtr);
  }

  return subTreePtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(
                                BinaryNode<ItemType> *subTreePtr,
                                const ItemType &target, bool &isSuccessful) {
  if (subTreePtr == nullptr) {
    isSuccessful = false;
  } else if (subTreePtr->getItem() == target) { // item is root of a subtree
    subTreePtr = removeNode(subTreePtr); // remove item
    isSuccessful = true;
  } else if (subTreePtr->getItem() > target) {
    // search left subtree
    BinaryNode<ItemType> *tempPtr = removeValue(subTreePtr->getLeftChildPtr(),
                                                target, isSuccessful);
    subTreePtr->setLeftChildPtr(tempPtr);
  } else {
    // search right subtree
    BinaryNode<ItemType> *tempPtr = removeValue(subTreePtr->getRightChildPtr(),
                                                target, isSuccessful);
    subTreePtr->setRightChildPtr(tempPtr);
  }

  return subTreePtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(
                                        BinaryNode<ItemType> *nodeToRemovePtr) {
  if (nodeToRemovePtr->isLeaf()) {
    // remove leaf from tree
    delete [] nodeToRemovePtr; // TODO: check if this works
    return nodeToRemovePtr;
  } else if (nodeToRemovePtr->getLeftChildPtr() != nodeToRemovePtr->getRightChildPtr()) { // != is logical XOR
    // if it has only one child
    BinaryNode<ItemType> *nodeToConnectPtr;
    if (nodeToRemovePtr->getLeftChildPtr()) { // if it has a left child
      nodeToConnectPtr = nodeToRemovePtr->getLeftChildPtr();
    } else { // if it has a right child
      nodeToConnectPtr = nodeToRemovePtr->getRightChildPtr();
    }

    delete [] nodeToRemovePtr;
    return nodeToConnectPtr;
  } else {
    // has two children
    ItemType newNodeValue;
    BinaryNode<ItemType> *tempPtr = removeLeftmostNode(nodeToRemovePtr->getRightChildPtr(),
                                                       newNodeValue);
    nodeToRemovePtr->setRightChildPtr(tempPtr);
    nodeToRemovePtr->setItem(newNodeValue);

    return nodeToRemovePtr;
  }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(
                                          BinaryNode<ItemType> *nodePtr,
                                          ItemType &inorderSuccessor) {
  if (nodePtr->getLeftChildPtr() == nullptr) {
    inorderSuccessor = nodePtr->getItem();
    return removeNode(nodePtr);
  } else {
    BinaryNode<ItemType> *tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(),
                                                       inorderSuccessor);
    nodePtr->setLeftChildPtr(tempPtr);
    return nodePtr;
  }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
  return BinaryNodeTree<ItemType>::isEmpty();
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  return BinaryNodeTree<ItemType>::getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
  return BinaryNodeTree<ItemType>::getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
  return rootPtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(ItemType &newEntry) {
  return rootPtr->setItem(newEntry);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newData) {
  BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>;
  newNodePtr->setItem(newData);

  rootPtr = placeNode(rootPtr, newNodePtr);

  return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target) {
  bool isSuccessful = false;
  rootPtr = removeValue(rootPtr, target, isSuccessful);
  return isSuccessful;
}

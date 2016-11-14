template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
    // slistPtr = <SortedList<ItemType> >();
}

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue& pq)
{
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
    return sList.isEmpty();
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    // return 1;
    return sList.insertSorted(newEntry);
}//end enqueue

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue()
{
    //The highest-priority item is at the end of the sorted list
    return sList.remove(sList.getLength());
}//end dequeue

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcept)
{
    if(isEmpty()){
        throw PrecondViolatedExcept("peek() called with empty queue.");
    }
    // return highest-priority item
    return sList.getEntry(sList.getLength());
}

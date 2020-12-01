#pragma once
#include "assert.hpp"

template <typename E>
void swapInArray(E *array, int pos1, int pos2)
{
    E temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

template <typename E>
class Heap
{
private:
    E *heapElementArray; // elements in a heap
    int maxHeapSize;
    int heapSize;

    // the function that determins if this is a maxHeap or a minHeap
    // equal to 0 means this is a pure virtual function and must be implemented
    virtual bool compare(E a, E b) = 0;
    void siftdown(int pos)
    {
        if (pos >= heapSize)
            return;
        while (!isLeaf(pos))
        {
            int smallerOrBiggerChildPos, leftChildPos = this->getLeftChildPos(pos), rightChildPos = this->getRightChildPos(pos);

            if (rightChildPos < heapSize && compare(heapElementArray[rightChildPos], heapElementArray[leftChildPos]))
                smallerOrBiggerChildPos = rightChildPos;
            else
                smallerOrBiggerChildPos = leftChildPos;

            if (compare(heapElementArray[smallerOrBiggerChildPos], heapElementArray[pos]))
            {
                swapInArray<E>(heapElementArray, smallerOrBiggerChildPos, pos);
                pos = smallerOrBiggerChildPos;
            }
            else
                return;
        }
    }

public:
    Heap(E *elementArray, int num, int max)
    {
        heapElementArray = elementArray;
        heapSize = num;
        maxHeapSize = max;
    }
    inline int getSize()
    {
        return heapSize;
    }
    inline bool isLeaf(int pos)
    {
        return pos >= heapSize / 2 && pos < heapSize;
    }
    inline int getLeftChildPos(int pos)
    {
        return pos * 2 + 1;
    }
    inline int getRightChildPos(int pos)
    {
        return pos * 2 + 2;
    }
    inline int getParentPos(int pos)
    {
        return (pos - 1) / 2;
    }
    void buildHeap()
    {
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            siftdown(i);
    }
    void insert(const E &item)
    {
        assert(heapSize < maxHeapSize, "heap is full");
        int pos = heapSize++;
        heapElementArray[pos] = item;

        int parentPos = getParentPos(pos);
        while (pos > 0 && compare(heapElementArray[pos], heapElementArray[parentPos]))
        {
            swapInArray(heapElementArray, parentPos, pos);
            pos = parentPos;
            parentPos = getParentPos(pos);
        }
    }
    E removeFirst()
    {
        assert(heapSize > 0, "heap is empty");
        E firstElement = heapElementArray[0];
        heapElementArray[0] = heapElementArray[heapSize - 1];
        heapSize--;
        siftdown(0);
        // debug
        std::cout << "removed " << firstElement  << "from heap" << std::endl;
        return firstElement;
    }
};

template <typename E>
class MinHeap : public Heap<E>
{
    using Heap<E>::Heap;

private:
    inline bool compare(E a, E b)
    {
        return a < b;
    }
};

// pointer heap compares two elements after dereferencing them
template <typename E>
class MinPointerHeap : public Heap<E>
{
    using Heap<E>::Heap;

private:
    inline bool compare(E a, E b)
    {
        return *a < *b;
    }
};

template <typename E>
class MaxHeap : public Heap<E>
{
    using Heap<E>::Heap;

private:
    inline bool compare(E a, E b)
    {
        return a > b;
    }
};

template <typename E>
class MaxPointerHeap : public Heap<E>
{
    using Heap<E>::Heap;

private:
    inline bool compare(E a, E b)
    {
        return *a > *b;
    }
};

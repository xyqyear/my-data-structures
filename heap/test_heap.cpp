#include <iostream>
#include "heap.hpp"
#include "../assert.hpp"

using namespace std;

// test
int main(int argc, char const *argv[])
{
    int minHeapArray[100] = {4, 2, 3, 5, 100, 2, 1, 55};
    int minHeapSortedArray[] = {1, 2, 2, 3, 4, 5, 55, 100};

    int maxHeapArray[100] = {5, 2, 3, 567, 6, 4, 4, 1};
    int maxHeapSortedArray[] = {567, 6, 5, 4, 4, 3, 2, 1};

    // test minHeap
    cout << "start testing min heap" << endl;
    MinHeap<int> minHeap(minHeapArray, 8, 100);
    minHeap.buildHeap();
    for (size_t i = 0; i < 8; i++)
    {
        assert(minHeap.removeFirst() == minHeapSortedArray[i], "wrongly built minheap");
    }
    cout << "finished testing min heap" << endl << endl;

    // test maxHeap
    cout << "start testing max heap" << endl;
    MaxHeap<int> maxHeap(maxHeapArray, 8, 100);
    maxHeap.buildHeap();
    for (size_t i = 0; i < 8; i++)
    {
        // cout << maxHeap.removeFirst() << endl;
        assert(maxHeap.removeFirst() == maxHeapSortedArray[i], "wrongly built maxheap");
    }
    cout << "finished testing max heap" << endl << endl;

    // test insert
    cout << "start testing heap insertion" << endl;
    int HeapArray[100] = {4, 2, 3, 5, 100, 2, 1, 55};
    MaxHeap<int> maxHeap1(HeapArray, 8, 100);
    maxHeap1.buildHeap();
    maxHeap1.insert(166);
    maxHeap1.insert(44);
    int insertedHeapArray[] = {166, 100, 55, 44, 5, 4, 3, 2, 2, 1};
    for (size_t i = 0; i < 9; i++)
    {
        // cout << maxHeap1.removeFirst() << endl;
        assert(maxHeap1.removeFirst() == insertedHeapArray[i], "heap insertion error");
    }
    cout << "finished testing heap insertion" << endl;

    return 0;
}

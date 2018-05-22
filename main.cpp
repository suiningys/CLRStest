#include <iostream>
#include <vector>
#include "sortingAlgorithm.h"
using namespace std;

void testInsertSort()
{
    vector<double> A{10,0,12,5,7,6.5};
    inserSort(A);
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

void testMergeSort()
{
    vector<double> A{10,0,12,5,7,6.5,-11};
    mergeSort(A);
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

void testBubbleSort()
{
    vector<double> A{10,0,12,5,7,6.5,-11};
    bubbleSort(A);
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

void testMaxHeapify()
{
    vector<double> A{16,4,10,14,7,9,3,2,8,1};
    maxHeapify(A, 1, A.size());
    printVector(A);
}

void testBuildHeap()
{
    vector<double> A{4,1,3,2,16,9,10,14,8,7};
    buildMaxHeap(A);
    printVector(A);
}

void testHeapSort()
{
    vector<double> A{10,0,12,5,7,6.5,-11};
    heapSort(A);
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

int main()
{
    testHeapSort();
    return 0;
}

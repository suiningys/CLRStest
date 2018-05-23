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

void testQuickSort()
{
    vector<double> A{10,0,12,5,7,6.5,-11};
    quickSort(A);
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

void testCase()
{
    vector<double> A{0,1,2,4,5,6,7,8,9,10};
    vector<double> B{10,9,8,7,6,5,4,3,2,1,0};
    vector<double> C{-10,-9,-8,-7,-5,4,3,1,0,4,10,65535};
    vector<unsigned> D{0,10,12,5,7,6,3,1};
    /*quickSort(A);
    printVector(A);
    quickSort(B);
    printVector(B);
    quickSort(C);
    printVector(C);
    */
    countingSort(D);
    for(auto item:D)
        cout<< item<<" ";
    cout<<endl;
    vector<double> E{0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    bucketSort(E);
    for(auto item:E)
        cout<< item<<" ";
    cout<<endl;
}

int main()
{
    testCase();
    return 0;
}

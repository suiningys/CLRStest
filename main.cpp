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

int main()
{
    //cout << "Hello world!" << endl;
    testMergeSort();
    return 0;
}

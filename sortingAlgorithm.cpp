#include<vector>
#include<iostream>
#include "sortingAlgorithm.h"
using std::vector;
using std::cout;
using std::endl;

void printVector(vector<double> A)
{
    for(auto item:A)
        cout<< item<<" ";
    cout<<endl;
}

void inserSort(vector<double> &A)
{
    auto length = A.size();
    for(decltype(length) jj = 1;jj!=length;jj++)
    {
        double key = A[jj];
        int ii = jj -1;
        while(ii>=0&&A[ii]>key)
        {
            A[ii+1] = A[ii];
            ii = ii - 1;
        }
        A[ii+1] = key;
    }
    printVector(A);
}

void mergeSort(vector<double> &A)
{
    auto length = A.size();
    mergeSortSort(A,0,length-1);
}

void mergeSortSort(vector<double> &A, int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSortSort(A,p,q);
        mergeSortSort(A,q+1,r);
        mergeSortMerge(A,p,q,r);
    }
}

void mergeSortMerge(vector<double> &A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<double> L,R;
    int pL = 0, pR = 0;
    for(int ii = 0;ii<n1;ii++)
        L.push_back(A[p+ii]);
    for(int ii = 0;ii<n2;ii++)
        R.push_back(A[q+ii+1]);
    int ii = 0, jj = 0;
    for(int kk = p;kk<=r;kk++)
    {
        if((pR==n2||L[ii]<=R[jj])&&pL<n1)
        {
            A[kk] = L[ii];
            ii++;
            pL++;
        }
        else
        {
            A[kk] = R[jj];
            jj++;
            pR++;
        }
    }
}

void bubbleSort(vector<double> &A)
{

}

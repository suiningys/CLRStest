#include<vector>
#include<iostream>
#include<random>
#include<cstdlib>
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

void exchange(vector<double> &A, int ii, int jj)
{
    double temp = A[ii];
    A[ii] = A[jj];
    A[jj] = temp;
}

void bubbleSort(vector<double> &A)
{
    auto length = A.size();
    for(unsigned ii = 0;ii<length-1;ii++)
    {
        for(unsigned jj = ii+1;jj<length;jj++)
        {
            if(A[ii]>A[jj])
                exchange(A,ii,jj);
        }
    }
}

void maxHeapify(vector<double> &A, unsigned ii, unsigned heapSize)
{
    unsigned l = leftSon(ii+1)-1;
    unsigned r = rightSon(ii+1)-1;
    //auto length = A.size();
    double largest = 0;
    if (l<heapSize&&A[l]>A[ii])
        largest = l;
    else
        largest = ii;
    if(r<heapSize&&A[r]>A[largest])
        largest = r;
    if(largest!=ii)
    {
        exchange(A,ii,largest);
        maxHeapify(A,largest,heapSize);
    }
}

void buildMaxHeap(vector<double> &A)
{
    auto length = A.size();
    unsigned leafNum = length>>1;
    for(int ii = leafNum;ii>=0;ii--)
        maxHeapify(A, ii,length);
}

void heapSort(vector<double> &A)
{
    buildMaxHeap(A);
    auto length = A.size();
    unsigned heapSize = length;
    for(unsigned ii = length-1;ii>=1;ii--)
    {
        exchange(A,0,heapSize-1);
        heapSize--;
        maxHeapify(A,0,heapSize);
    }

}

unsigned quickPartition(vector<double> &A, unsigned p, unsigned r)
{
    //default_random_engine e;
    //uniform_int_distribution<unsigned> u(p,r);
    unsigned q = random(p,r);
    exchange(A,q,r);
    double x = A[r];
    int ii = p -1;
    for(unsigned jj=p;jj<=r-1;jj++)
    {
        if(A[jj]<x)
        {
            ii++;
            exchange(A,ii,jj);
        }
    }
    exchange(A,ii+1,r);
    return ii+1;
}
/*
 * p and r are int type because p and r can be negative in forth line
 * warning: q-1 can be negative
 */
void quickSortCore(vector<double> &A, int p, int r)
{
    if(p<r)
    {
        int q = quickPartition(A,p,r);
        quickSortCore(A,p,q-1);
        quickSortCore(A,q+1,r);
    }
}

void quickSort(vector<double> &A)
{
    auto length = A.size();
    quickSortCore(A,0,length-1);
}

void countingSort(vector<unsigned> &A)
{
    vector<unsigned> B(A);
    unsigned maxNum = 0;
    vector<unsigned>::iterator it;
    for(it = A.begin();it!=A.end();it++)
    {
        if(*it>maxNum)
            maxNum = *it;
    }
    countingSortCore(A,B,maxNum);
    A.swap(B);
}

void countingSortCore(vector<unsigned> &A, vector<unsigned> &B, unsigned k)
{
    auto length = A.size();
    vector<unsigned> C(k+1,0);
    for(unsigned ii = 0;ii<length;ii++)
        C[A[ii]]++;
    for(unsigned ii=1;ii<=k;ii++)
        C[ii] +=C[ii-1];
    for(int jj = length-1;jj>=0;jj--)
    {
        B[C[A[jj]]] = A[jj];
        C[A[jj]]--;
    }
}

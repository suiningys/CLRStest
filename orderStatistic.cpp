#include<iostream>
#include "sortingAlgorithm.h"
#include "orderStatistic.h"
using namespace std;

void maxMinFounder(vector<double> A, double &minNum, double &maxNum)
{
    auto length = A.size();
    minNum = A[0];
    maxNum = A[0];
    double interBigger, interSmaller;
    for(unsigned ii = 0;ii<length;ii+=2)
    {
        if(ii+1<length)
        {
            bool isBigger = A[ii]>A[ii+1];
            interBigger = isBigger?A[ii]:A[ii+1];
            interSmaller = isBigger?A[ii+1]:A[ii];
            if(interBigger>maxNum)
                maxNum = interBigger;
            if(interSmaller<minNum)
                minNum = interSmaller;
        }
        else
        {
            if(A[ii]>maxNum)
                maxNum = interBigger;
            if(A[ii]<minNum)
                minNum = interSmaller;
        }
    }
}

double selectRandom(vector<double> A, int p, int r, int i)
{
    if(p==r)
        return A[p];
    int q = quickPartition(A,p,r);
    int k = q - p + 1;
    if(i==k)
        return A[q];
    else if(i<k)
        return selectRandom(A,p,q-1,i);
    else
        return selectRandom(A,q+1,r,i-k);
}

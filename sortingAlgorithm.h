#ifndef SORTINGALGORITHM_H_INCLUDED
#define SORTINGALGORITHM_H_INCLUDED
#include<vector>
using std::vector;
using std::cout;
using std::endl;

void printVector(vector<double> A);

void inserSort(vector<double> &A);

void mergeSort(vector<double> &A);

void mergeSortSort(vector<double> &A, int p, int r);

void mergeSortMerge(vector<double> &A, int p, int q, int r);

void bubbleSort(vector<double> &A);
#endif // SORTINGALGORITHM_H_INCLUDED

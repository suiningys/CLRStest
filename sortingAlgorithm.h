#ifndef SORTINGALGORITHM_H_INCLUDED
#define SORTINGALGORITHM_H_INCLUDED
#include<vector>
#include<random>

#define parent(ii) ((ii)>>1)
#define leftSon(ii) ((ii)<<1)
#define rightSon(ii) (((ii)<<1) + 1)
#define random(a,b) (rand()%((b)-(a)+1)+(a))

using std::vector;
using std::cout;
using std::endl;

void printVector(vector<double> A);

void inserSort(vector<double> &A);

void mergeSort(vector<double> &A);

void mergeSortSort(vector<double> &A, int p, int r);

void mergeSortMerge(vector<double> &A, int p, int q, int r);

void exchange(vector<double> &A, int ii, int jj);

void bubbleSort(vector<double> &A);

void maxHeapify(vector<double> &A, unsigned ii, unsigned heapSize);

void buildMaxHeap(vector<double> &A);

void heapSort(vector<double> &A);

unsigned quickPartition(vector<double> &A, unsigned p, unsigned r);

void quickSortCore(vector<double> &A, int p, int r);

void quickSort(vector<double> &A);

void countingSort(vector<unsigned> &A);

void countingSortCore(vector<unsigned> &A, vector<unsigned> &B, unsigned k);

void bucketSort(vector<double> &A);
#endif // SORTINGALGORITHM_H_INCLUDED

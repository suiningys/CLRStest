#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

using namespace std;

struct myStack{
    const unsigned n = 100;
    int mystack[100];
    int top = 0;
};

struct listNode{
    listNode * prev = nullptr;
    listNode * next = nullptr;
    double index = 0;
};

struct myList{
    listNode * head = nullptr;
    listNode * tail = nullptr;
    unsigned length = 0;
};

bool listEmpty(myList * mylist);

listNode * creatNode(double num);

void insertNode(myList * mylist, double num);

void printList(myList * mylist);
#endif // DATASTRUCTURE_H_INCLUDED

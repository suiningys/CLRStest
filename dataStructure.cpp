#include<iostream>
#include "dataStructure.h"
using namespace std;

bool listEmpty(myList * mylist)
{
    return mylist->head==nullptr;
}

listNode * creatNode(double num)
{
    listNode * newNode = new listNode;
    newNode->index = num;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(myList * mylist, double num)
{
    listNode * newNode = creatNode(num);
    if(listEmpty(mylist))
    {
        mylist->head = newNode;
        mylist->tail = newNode;
        mylist->length = 1;
    }
    else
    {
        newNode->prev = mylist->tail;
        mylist->tail->next = newNode;
        mylist->tail = newNode;
        mylist->length += 1;
    }
}

void printList(myList * mylist)
{
    for(listNode * nodeTemp = mylist->head;nodeTemp!=nullptr;nodeTemp = nodeTemp->next)
        cout<<nodeTemp->index<<" ";
    cout<<endl;
}

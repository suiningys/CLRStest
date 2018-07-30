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

struct binaryTreeNode{
    binaryTreeNode * left;
    binaryTreeNode * right;
    binaryTreeNode * parent;
    double index;
};

struct binaryTree{
    binaryTreeNode * root;
};

bool listEmpty(myList * mylist);

listNode * creatNode(double num);

void insertNode(myList * mylist, double num);

void printList(myList * mylist);

listNode * searchList(myList * mylist, double k);

bool deleteNode(myList * mylist, double k);
/*
 * 二叉树
 */
void inorderTreeWalk(binaryTreeNode * node);

binaryTreeNode * searchTree(binaryTreeNode *root, double key);

binaryTreeNode * searchTreeIter(binaryTreeNode * node, double key);

binaryTreeNode * minimumTree(binaryTreeNode * node);

binaryTreeNode * maximumTree(binaryTreeNode * node);

binaryTreeNode * treeSuccessor(binaryTreeNode * node);

binaryTreeNode * treePredecessor(binaryTreeNode * node);

binaryTreeNode * creatTreeNode(double z);

binaryTree * creatTree(double num);

bool insertTree(binaryTree * tree, binaryTreeNode * z);

void transplant(binaryTree * tree, binaryTreeNode * u, binaryTreeNode * v);

bool treeDelete(binaryTree * tree, binaryTreeNode * node);
/*
 * 红黑树
 */
#define BLACK false
#define RED true
struct colorTreeNode{
    colorTreeNode * left;
    colorTreeNode * right;
    colorTreeNode * parent;
    double value;
    bool color;// true ºìÉ« false ºÚÉ«
};

struct colorTree{
    colorTreeNode * root;
    colorTreeNode * nil;//ÉÚ±ø
};

colorTree * creatColorTree(double num);

colorTreeNode * creatColorTreeNode(double num);

void treeLeftRotate(colorTree * tree, colorTreeNode * x);

void treeRightRotate(colorTree * tree, colorTreeNode * x);

bool RBInsert(colorTree * tree, colorTreeNode * z);

void RBInsertFixup(colorTree * tree, colorTreeNode * z);
#endif // DATASTRUCTURE_H_INCLUDED

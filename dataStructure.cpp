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

listNode * searchList(myList * mylist, double k)
{
    listNode * nodeTemp = mylist->head;
    while(nodeTemp!=nullptr && nodeTemp->index!=k)
        nodeTemp = nodeTemp->next;
    return nodeTemp;
}

bool deleteNode(myList * mylist, double k)
{
    listNode * nodeTemp = searchList(mylist,k);
    if(nodeTemp==nullptr)
        return 0;
    if(nodeTemp->prev!=nullptr)
        nodeTemp->prev->next = nodeTemp->next;
    else
        mylist->head = nodeTemp->next;
    if(nodeTemp->next!=nullptr)
        nodeTemp->next->prev = nodeTemp->prev;
    else
        mylist->tail = nodeTemp->prev;
    delete nodeTemp;
    mylist->length -=1;
    return 1;
}

void inorderTreeWalk(binaryTreeNode * node)
{
    if(node!=nullptr)
    {
        inorderTreeWalk(node->left);
        cout<<node->index<<" ";
        inorderTreeWalk(node->right);
    }
}

binaryTreeNode * searchTree(binaryTreeNode *root, double key)
{
    if(root==nullptr||root->index==key)
        return root;
    if(key<root->index)
        return searchTree(root->left,key);
    else
        return searchTree(root->right,key);
}

binaryTreeNode * searchTreeIter(binaryTreeNode * node, double key)
{
    binaryTreeNode * nodeTemp = node;
    while(nodeTemp!=nullptr||nodeTemp->index!=key)
    {
        if(nodeTemp->index<key)
            nodeTemp = nodeTemp->left;
        else
            nodeTemp = nodeTemp->right;
    }
    return nodeTemp;
}

binaryTreeNode * minimumTree(binaryTreeNode * node)
{
    binaryTreeNode * nodeTemp = node;
    while(nodeTemp->left!=nullptr)
    {
        nodeTemp = nodeTemp->left;
    }
    return nodeTemp;
}

binaryTreeNode * maximumTree(binaryTreeNode * node)
{
    binaryTreeNode * nodeTemp = node;
    while(nodeTemp->right!=nullptr)
    {
        nodeTemp = nodeTemp->right;
    }
    return nodeTemp;
}

binaryTreeNode * treeSuccessor(binaryTreeNode * node)
{
    if(node->right!=nullptr)
        return minimumTree(node->right);
    binaryTreeNode * x = node;
    binaryTreeNode * y = node->parent;
    while(y!=nullptr&&x==y->right)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

binaryTreeNode * treePredecessor(binaryTreeNode * node)
{
    if(node->left!=nullptr)
        return maximumTree(node->left);
    binaryTreeNode * x = node;
    binaryTreeNode * y = node->parent;
    while(y!=nullptr&&x == y->left)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

binaryTreeNode * creatTreeNode(double z)
{
    binaryTreeNode * nodeTemp = new binaryTreeNode;
    nodeTemp->index = z;
    nodeTemp->left = nullptr;
    nodeTemp->parent = nullptr;
    nodeTemp->right = nullptr;
    return nodeTemp;
}

binaryTree * creatTree(double num)
{
    binaryTree * tree = new binaryTree;
    binaryTreeNode *root = creatTreeNode(num);
    tree->root = root;
    return tree;
}

bool insertTree(binaryTree * tree, binaryTreeNode * z)
{
    binaryTreeNode * y = nullptr;
    binaryTreeNode * x = tree->root;
    while(x!=nullptr)
    {
        y = x;
        if(z->index < x->index)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y==nullptr)
        tree->root = z;
    else if(z->index<y->index)
        y->left = z;
    else
        y->right = z;
    return true;
}

void transplant(binaryTree * tree, binaryTreeNode * u, binaryTreeNode * v)
{
    if(u->parent==nullptr)
        tree->root = v;
    else if(u==u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if(v!=nullptr)
        v->parent = u->parent;
}

bool treeDelete(binaryTree * tree, binaryTreeNode * node)
{
    /*if(node->left==nullptr&&node->right==nullptr)
    {
        if(node==node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete node;
    }
    */
    if(node->left==nullptr)
        transplant(tree, node, node->right);
    else if(node->right==nullptr)
        transplant(tree, node, node->left);
    else
    {
        binaryTreeNode * y = minimumTree(node->right);
        if(y->parent!=node)
        {
            transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
    }
    delete node;
    return true;
}

colorTree * creatColorTree(double num)
{
    colorTree * tree = new colorTree;
    colorTreeNode * root = new colorTreeNode;
    colorTreeNode * nil = new colorTreeNode;
    nil->color = BLACK;
    nil->parent = nil->right = nil->left = nullptr;
    nil->value = 0;
    root->color = BLACK;
    root->value = num;
    root->left = root->right = root->parent = nil;
    tree->nil = nil;
    tree->root = root;
    return tree;
}

void treeLeftRotate(colorTree * tree, colorTreeNode * x)
{
    colorTreeNode * y = x->right;
    x->right = y->left;
    if(y->left!=tree->nil)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent==tree->nil)
        tree->root = y;
    else if(x==x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void treeRightRotate(colorTree * tree, colorTreeNode * y)
{
    colorTreeNode * x = y->left;
    if(x->right!=tree->nil)
        x->right->parent = y;
    x->parent = y->parent;
    if(x->parent == tree->nil)
        tree->root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

colorTreeNode * creatColorTreeNode(double num)
{
    colorTreeNode * newNode = new colorTreeNode;
    newNode->color = BLACK;
    newNode->left = nullptr;
    newNode->parent = nullptr;
    newNode->right = nullptr;
    newNode->value = num;
    return newNode;
}

bool RBInsert(colorTree * tree, colorTreeNode * z)
{
    colorTreeNode * y = tree->nil;
    colorTreeNode * x = tree->root;
    while(x!=tree->nil)
    {
        y = x;
        if(z->value<x->value)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y==tree->nil)
        tree->root = z;
    else if(z->value<y->value)
        y->left = z;
    else
        y->right = z;
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    RBInsertFixup(tree,z);
    return true;
}

void RBInsertFixup(colorTree * tree, colorTreeNode * z)
{
    while(z->parent->color==RED)
    {
        if(z->parent==z->parent->parent->left)
        {
            colorTreeNode * y = z->parent->parent->right;
            //case1
            if(y->color==RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if(z==z->parent->right)
            {
                z = z->parent;
                treeLeftRotate(tree,z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            treeRightRotate(tree,z->parent->parent);
        }else
        {
            colorTreeNode * y = z->parent->parent->left;
            if(y->color==BLACK)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if(z==z->parent->right)
            {
                z = z->parent;
                treeLeftRotate(tree,z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            treeRightRotate(tree,z->parent->parent);
        }
    }
    tree->root->color = BLACK;
}

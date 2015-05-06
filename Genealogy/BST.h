//
//  Final Project: Extended BST
//  Professor: Rhonda Hoenigman
//  Course: CSCI 2270 Spring 2015
//  Created by Sophia.
//  BST.h
//  Adapted from Assignment 5 & Bogo to Bogo C++ Tutorial Binary Tree Example

#ifndef __Genealogy__Genealogy__
#define __Genealogy__Genealogy__

#include <iostream>
#include <deque>
#include <climits>
#include <vector>

struct Tree
{
    char data;
    Tree *left;
    Tree *right;
    Tree *parent;
};

class BST {
public:
    BST();
    virtual ~BST();
    Tree* lookUp(struct Tree *node, char key);
    Tree* leftMost(struct Tree *node);
    struct Tree *newTreeNode(int data);
    struct Tree* insertTreeNode(struct Tree *node, int data);
    void isBST(struct Tree *node);
    int treeSize(struct Tree *node);
    int maxDepth(struct Tree *node);
    int minDepth(struct Tree *node);
    Tree* minTree(struct Tree *node);
    Tree* maxTree(struct Tree *node);
    Tree *succesorInOrder(struct Tree *node);
    Tree *predecessorInOrder(struct Tree *node);
    void reverseOrderPrint(struct Tree *node);
    Tree *lowestCommonAncestor(Tree *node, Tree *p, Tree *q);
    void clear(struct Tree *node);
    void printTreeInOrder(struct Tree *node);
    void printTreePostOrder(struct Tree *node);
    void printTreePreOrder(struct Tree *node);
    void printTreeReverseOrder(struct Tree *node);
    bool matchTree(Tree *r1, Tree *r2);
    bool subTree(Tree *r1, Tree *r2);
    bool isSubTree(Tree *r1, Tree *r2);
    void mirror(Tree *r);
    void BreadthFirstTraversal(Tree *root);
    int getLevel(struct Tree *node, int elm, int level);
    
};
#endif /* defined(__Genealogy__Genealogy__) */

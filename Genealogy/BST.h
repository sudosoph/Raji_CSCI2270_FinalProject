//
//  Final Project: Extended BST
//  Professor: Rhonda Hoenigman
//  Course: CSCI 2270 Spring 2015
//  Created by Sophia.
//  BST.h
//

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
    void pathFinder(struct Tree *node, int path[], int level);
    bool matchTree(Tree *r1, Tree *r2);
    bool subTree(Tree *r1, Tree *r2);
    bool isSubTree(Tree *r1, Tree *r2);
    void mirror(Tree *r);
    Tree *addToBST(char arr[], int start, int end);
    Tree *createMinimalBST(char arr[], int size);
    void BreadthFirstTraversal(Tree *root);
    int getLevel(struct Tree *node, int elm, int level);
    void BreadthFirst_LevelElement_Print(struct Tree *root, std::vector<std::vector<int> > &v);
    void levelPrint(struct Tree *node, std::vector<std::vector<char> >&elm, int level);
    void NthMax(struct Tree* t);
    void TreeToArray(struct Tree *node, int a[]);
    void level_even_odd(struct Tree *node);
};
#endif /* defined(__Genealogy__Genealogy__) */

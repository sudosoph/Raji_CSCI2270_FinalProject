//
//  Final Project: Extended BST
//  Professor: Rhonda Hoenigman
//  Course: CSCI 2270 Spring 2015
//  Created by Sophia.
//  BST.cpp
//  Adapted from Assignment 5 & Bogo to Bogo C++ Tutorial Binary Tree Example

#include "BST.h"
#include <iostream>
#include <deque>
#include <climits>
#include <vector>

Tree::Tree() {
    
}

Tree::~Tree() {
    //dtor
    delete node;
}

/*
 Function prototype:
 Tree* lookUp(struct Tree, char)
 
 Function description:
 This method searches for a node by eliminating half the nodes from our search on each iteration by choosing to follow the left subtree or the right subtree.
 
 Example:
 Tree t;
 lookUp(t, "A")
 
 Precondition: Tree contains nodes to look up recursively, otherwise returns node passed in. The node passed in is the node we want to search for. The input char is node name.
 Post condition: Node is found and returned by method.
 */

Tree* lookUp(struct Tree *node, char key)
{
    if(node == NULL) return node;
    
    if(node->data == key) return node;
    else {
        if(node->data < key)
            return lookUp(node->right, key) ;
        else
            return lookUp(node->left, key);
    }
}

/*
 Function prototype:
 Tree* leftMost(struct Tree)
 
 Function description:
 This method finds the leftmost node in a tree.
 
 Example:
 Tree t;
 leftMost(t)
 
 Precondition: Tree node must be passed in. The node is the root of the tree where leftmost node is to be found.
 Post condition: Returns leftmost node in tree passed in.
 */

Tree* leftMost(struct Tree *node)
{
    if(node == NULL) return NULL;
    while(node->left != NULL)
        node = node->left;
    return node;
}

/*
 Function prototype:
 struct Tree *newTreeNode(int)
 
 Function description:
 This method creates the root node of a Tree.
 
 Example:
 Tree t;
 t.newTreeNode(7)
 
 Precondition: Tree must be empty to create the root node. The input value is an integer.
 Post condition: Root node with NULL parent, left and right children.
 */

struct Tree *newTreeNode(int data)
{
    Tree *node = new Tree;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    
    return node;
}

/*
 Function prototype:
 struct Tree* insertTreeNode(struct Tree, int)
 
 Function description:
 This method inserts a new node into the tree.
 
 Example:
 Tree t;
 newTreeNode(t, 7)
 
 Precondition: Examines the root node and recursively inserts the new node to the left subtree if the value is less than the root and right subtree if the value is greater than or equal to the root. The input value is an integer.
 Post condition: Inserts a node into the tree and preserves BST properties.
 */

struct Tree* insertTreeNode(struct Tree *node, int data)
{
    static Tree *p;
    Tree *retNode;
    
    //if(node != NULL) p = node;
    
    if(node == NULL)  {
        retNode = newTreeNode(data);
        retNode->parent = p;
        return retNode;
    }
    if(data <= node->data ) {
        p = node;
        node->left = insertTreeNode(node->left,data);
    }
    else {
        p = node;
        node->right = insertTreeNode(node->right,data);
    }
    return node;
}

/*
 Function prototype:
 void isBST(struct Tree)
 
 Function description:
 This method determines if a given tree is a binary search tree.
 
 Example:
 Tree t;
 isBST(t)
 
 Precondition: Binary search tree must already exist. The input is existing tree. If it is a BST, inorder traversal outputs elements in increasing order.
 Post condition: Returns statement about whether tree passed in is a BST or not.
 */

void isBST(struct Tree *node)
{
    static int lastData = INT_MIN;
    if(node == NULL) return;
    
    isBST(node->left);
    
    /* check if the given tree is BST */
    if(lastData < node->data)
        lastData = node->data;
    else {
        cout << "Not a BST" << endl;
        return;
    }
    
    isBST(node->right);
    return;
}

/*
 Function prototype:
 int treeSize(struct Tree)
 
 Function description:
 This method calculates the total number of nodes in a tree.
 
 Example:
 Tree t;
 treeSize(t)
 
 Precondition: Must pass in existing tree. If the tree is empty, it returns 0, otherwise it recursively counts left and right subtree nodes. The input string name is movie title.
 Post condition: Returns int of total number of nodes in tree.
 */

int treeSize(struct Tree *node)
{
    if(node == NULL) return 0;
    else
        return treeSize(node->left) + 1 + treeSize(node->right);
}

/*
 Function prototype:
 int maxDepth(struct Tree)
 
 Function description:
 This method finds the number of nodes along the longest path from the root node to farthest leaf.
 
 Example:
 Tree t;
 maxDepth(t)
 
 Precondition: If tree is empty, max depth will be 0.
 Post condition: Returns int of max value of longest path in tree.
 */

int maxDepth(struct Tree *node)
{
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    
    return leftDepth > rightDepth ?
				leftDepth + 1 : rightDepth + 1;
}

/*
 Function prototype:
 int minDepth(struct Tree)
 
 Function description:
 This method finds the number of nodes along the shortest path from the root node to farthest leaf.
 
 Example:
 Tree t;
 minDepth(t)
 
 Precondition: If tree is empty, min depth will be 0.
 Post condition: Returns int of min value of longest path in tree.
 */

int minDepth(struct Tree *node)
{
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    
    int leftDepth = minDepth(node->left);
    int rightDepth = minDepth(node->right);
    
    return leftDepth < rightDepth ?
				leftDepth + 1 : rightDepth + 1;
}

/*
 Function prototype:
 bool isBalanced(struct Tree)
 
 Function description:
 This method determines if the binary tree is balanced (height of the two subtrees of every node never differ by more than 1).
 
 Example:
 Tree t;
 isBalanced(t)
 
 Precondition: Binary search tree must exist.
 Post condition: Returns boolean for whether it is balanced or not.
 */

bool isBalanced(struct Tree *node)
{
    if(maxDepth(node)-minDepth(node) <= 1)
        return true;
    else
        return false;
}

/*
 Function prototype:
 Tree* minTree(struct Tree)
 
 Function description:
 This method calculates the minimum node in the tree.
 
 Example:
 Tree t;
 minTree(t)
 
 Precondition: If tree has no nodes, it is empty and minTree returns NULL. Otherwise you pass in the tree's root.
 Post condition: Returns minimum node in tree.
 */

/* Tree Minimum */
Tree* minTree(struct Tree *node)
{
    if(node == NULL) return NULL;
    while(node->left)
        node = node -> left;
    return node;
}

/*
 Function prototype:
 Tree* maxTree(struct Tree)
 
 Function description:
 This method calculates the minimum node in the tree.
 
 Example:
 Tree t;
 maxTree(t)
 
 Precondition: If tree has no nodes, it is empty and maxTree returns NULL. Otherwise you pass in the tree's root.
 Post condition: Returns maximum node in tree.
 */

/* Tree Maximum */
Tree* maxTree(struct Tree *node)
{
    while(node->right)
        node = node -> right;
    return node;
}

/* In Order Successor - a node which has the next higher key */
Tree *succesorInOrder(struct Tree *node)
{
    /* if the node has right child, seccessor is Tree-Minimum */
    if(node->right != NULL) return minTree(node->right);
    
    Tree *y = node->parent;
    while(y != NULL && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

/* In Order Predecessor - a node which has the next lower key */
Tree *predecessorInOrder(struct Tree *node)
{
    /* if the node has left child, predecessor is Tree-Maximum */
    if(node->left != NULL) return maxTree(node->left);
    
    Tree *y = node->parent;
    /* if it does not have a left child,
     predecessor is its first left ancestor */
    while(y != NULL && node == y->left) {
        node = y;
        y = y->parent;
    }
    return y;
}


void reverseOrderPrint(struct Tree *node)
{
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) {
        cout << node->data << " ";
        return;
    }
    
    reverseOrderPrint(node->right);
    cout << node->data << " ";
    reverseOrderPrint(node->left);
}


Tree *lowestCommonAncestor(Tree *node, Tree *p, Tree *q)
{
    Tree *left, *right;
    if(node == NULL) return NULL;
    if(node->left == p || node->left == q
       || node->right == p || node->right == q) return node;
    
    left = lowestCommonAncestor(node->left,p,q);
    right = lowestCommonAncestor(node->right, p,q);
    if(left && right)
        return node;
    else
        return (left) ? left : right;
}

void clear(struct Tree *node)
{
    if(node != NULL) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
/* print tree in order */
/* 1. Traverse the left subtree.
 2. Visit the root.
 3. Traverse the right subtree.
 */

void printTreeInOrder(struct Tree *node)
{
    if(node == NULL) return;
    
    printTreeInOrder(node->left);
    cout << node->data << " ";
    printTreeInOrder(node->right);
}

/* print tree in postorder*/
/* 1. Traverse the left subtree.
 2. Traverse the right subtree.
 3. Visit the root.
 */
void printTreePostOrder(struct Tree *node)
{
    if(node == NULL) return;
    
    printTreePostOrder(node->left);
    printTreePostOrder(node->right);
    cout << node->data << " ";
}

void printTreePreOrder(struct Tree *node)
{
    if(node == NULL) return;
    
    cout << node->data << " ";
    printTreePreOrder(node->left);
    printTreePreOrder(node->right);
}


/* In reverse of printTreeInOrder() */
void printTreeReverseOrder(struct Tree *node)
{
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) {
        cout << node->data << " ";
        return;
    }
    
    printTreeReverseOrder(node->right);
    cout << node->data << " ";
    printTreeReverseOrder(node->left);
}

bool matchTree(Tree *r1, Tree *r2)
{
    /* Nothing left in the subtree */
    if(r1 == NULL && r2 == NULL)
        return true;
    /* Big tree empty and subtree not found */
    if(r1 == NULL || r2 == NULL)
        return false;
    /* Not matching */
    if(r1->data != r2->data)
        return false;
    return (matchTree(r1->left, r2->left) &&
            matchTree(r1->right, r2->right));
}

bool subTree(Tree *r1, Tree *r2)
{
    /*Big tree empty and subtree not found */
    if(r1 == NULL)
        return false;
    if(r1->data == r2->data)
        if(matchTree(r1, r2)) return true;
    return
    (subTree(r1->left, r2) || subTree(r1->right, r2));
}

bool isSubTree(Tree *r1, Tree *r2)
{
    /* Empty tree is subtree */
    if(r2 == NULL)
        return true;
    else
        return subTree(r1, r2);
}

/* change a tree so that the roles of the left
 and right hand pointers are swapped at every node */
void mirror(Tree *r)
{
    if(r == NULL) return;
    
    Tree *tmp;
    mirror(r->left);
    mirror(r->right);
    
    /* swap pointers */
    tmp = r->right;
    r->right = r->left;
    r->left = tmp;
}


/* get the level of a node element: root level = 0 */
int getLevel(struct Tree *node, int elm, int level)
{
    if(node == NULL) return 0;
    if(elm == node->data)
        return level;
    else if(elm < node->data)
        return getLevel(node->left, elm, level+1);
    else
        return getLevel(node->right, elm, level+1);
}
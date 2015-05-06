# Raji_CSCI2270_FinalProject
##READ ME
##Project Summary
This project is an extension of Assignment 5, where we created binary search trees to find movies. Rather than creating a movie binary search tree, it is a general binary search tree program. The methods included enable the user to add, search, and delete as in the assignment, but also to determine whether the binary search tree is a BST (left subtree is less than root and right subtree is greater than or equal to root), find the tree size (number of nodes), the maximum and minimum depth (number of nodes from the root to the farthest node in the tree), successor and predecessor, printing in order, post porder and preorder, finding the lowest common ancestor, and getting the level a node is currently in.

##HOW TO RUN
main.cpp is the driver program that calls the class functions that are included in BST.h and BST.cpp. Make sure main.cpp, BST.cpp, and BST.h are all in the same file. Then, in a terminal window in the file with those three functions, type g++ -std=c++11 main.cpp to compile. After that type ./a.out to run.

##DEPENDENCIES
This program uses no external dependencies. It should be run with C++11 and using a terminal.

##SYSTEM REQUIREMENTS
This program was made on Xcode 6, so it is possible to run the program by loading the Xcode project included on a Mac. Otherwise, run in terminal on either Linux or Mac.

##GROUP MEMBERS
No additional group members

##CONTRIBUTORS
N/A

##OPEN ISSUES/BUGS
Enhancements would be error handling when passing in an empty tree and the method requires it to be populated.
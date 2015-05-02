//
//  Final Project: BST Genealogy
//  Professor: Rhonda Hoenigman
//  Course: CSCI 2270 Spring 2015
//  Created by Sophia.
//  Genealogy.h
//

#ifndef __Genealogy__Genealogy__
#define __Genealogy__Genealogy__

#include <stdio.h>
#include <string>

struct Person {
    char name;
    std::string marital;
    std::string birth;
    std::string death;
    Person *parent;
    Person *child;
    
    Person() {};
    
    Person(char n, std::string m, std::string b, std::string d) {
        name = n;
        marital = m;
        birth = b;
        death = d;
    }
};

class FamilyTree {
public:
    FamilyTree();
    FamilyTree(char n, std::string m, std::string b, std::string d);
    virtual ~FamilyTree();
    void printFamilyTree(Person *p);
    void addMember(Person *p, char n, std::string m, std::string b, std::string d);
    Person *getAncestor(); //leading cause of non-namespace STDs in America
    void replaceHead(Person *p);
    Person *findPerson(Person *p, char name);
    void addSpouse(Person p);
    Person *getSpouse();
    void addChild(Person *p);
    bool hasChild();
    int countFamilyMembers();
    int countGenerations();
    int getNumberOfChildren();
    void displayTree();
private:
    void DeleteAll(Person *p);
    Person *searchFamilyTree(Person *p, char name);
    Person *ancestor;
};
#endif /* defined(__Genealogy__Genealogy__) */

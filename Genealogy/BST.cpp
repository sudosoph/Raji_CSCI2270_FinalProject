//
//  Final Project: BST Genealogy
//  Professor: Rhonda Hoenigman
//  Course: CSCI 2270 Spring 2015
//  Created by Sophia.
//  Genealogy.cpp
//

#include "Genealogy.h"
#include <iostream>

FamilyTree::FamilyTree() {
    
}

FamilyTree::~FamilyTree() {
    //dtor
    delete ancestor;
}

FamilyTree::FamilyTree(char n, std::string m, std::string b, std::string d) {
    
}

void FamilyTree::printFamilyTree(Person *p) {
    
}

void FamilyTree::addMember(Person *p, char n, std::string m, std::string b, std::string d){
    
}

Person* FamilyTree::getAncestor(){
    
}

void FamilyTree::replaceHead(Person *p){
    
}

Person* FamilyTree::findPerson(Person *p, char name){
    
}

void FamilyTree::addSpouse(Person p){
    
}

Person* FamilyTree::getSpouse(){
    
}

void FamilyTree::addChild(Person *p){
    
}

bool FamilyTree::hasChild(){
    
}

int FamilyTree::countFamilyMembers(){
    
}

int FamilyTree::countGenerations(){
    
}

int FamilyTree::getNumberOfChildren(){
    
}

void FamilyTree::displayTree(){
    
}
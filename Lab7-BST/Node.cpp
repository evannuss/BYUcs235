#include "BST.h"
#include <iostream>

//CONSTRUCTOR
Node::Node(int val){
    right = NULL;
    left = NULL;
    data = val;
}

//GET DATA
int Node::getData()const{
    return data;
}

//GET LEFT CHILD
Node* Node::getLeftChild()const{
    return left;
}

//GET RIGHT CHILD
Node* Node::getRightChild()const{
    return right;
}
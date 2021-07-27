#pragma once

#include "NodeInterface.h"
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface{
public:
    BST(){root = NULL;}
    ~BST();
    
    Node* getRootNode()const;
    bool add(int data);
    bool remove(int data);
   
    void clear();
    
    bool insert(Node* &nodePtr, int val);
    bool deleteNode(Node* &nodePtr, int val);
    
    int findPredecessor(Node* nodePtr);
private:
    Node* root;
};
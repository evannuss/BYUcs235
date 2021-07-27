#pragma once

#include "NodeInterface.h"
#include "BST.h"
#include <iostream>

class Node : public NodeInterface{
    public:
        Node(int val);
        ~Node(){}
        
        int getData()const;
        Node* getLeftChild()const;
        Node* getRightChild()const;
        
        friend class BST;
    private:
        Node* right;
        Node* left;
        int data;
    };

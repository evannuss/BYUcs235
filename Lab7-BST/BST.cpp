#include "BST.h"

//DESTRUCTOR
BST::~BST(){
    clear();
}

//GET ROOT NODE
Node* BST::getRootNode()const{
    return root;
}

//ADD
bool BST::add(int data){
    return insert(root, data);
}

//REMOVE
bool BST::remove(int data){
    return deleteNode(root, data);
}

//CLEAR
void BST::clear(){
    while(root != NULL){
        remove(root->data);
    }
}

//INSERT NODE
bool BST::insert(Node* &nodePtr, int val){
    if(nodePtr == NULL){
        nodePtr = new Node(val);
        return true;
    }
    if(nodePtr->data == val){
        return false;
    }
    
    if(val < nodePtr->data){
        return insert(nodePtr->left, val);
    }
    else{
        return insert(nodePtr->right, val);
    }
}

//DELETE NODE
bool BST::deleteNode(Node* &nodePtr, int val){
    if(nodePtr == NULL){
        return false;
    }
    
    Node* posterity = NULL;
    
    if(nodePtr->data == val){
        if((nodePtr->right == NULL) && (nodePtr->left == NULL)){
            delete nodePtr;
            nodePtr = NULL;
        }
        else if(nodePtr->right == NULL){
            posterity = nodePtr->left;
            delete nodePtr;
            nodePtr = posterity;
        }
        else if(nodePtr->left == NULL){
            posterity = nodePtr->right;
            delete nodePtr;
            nodePtr = posterity;
        }
        else{
            nodePtr->data = findPredecessor(nodePtr->left);
            deleteNode(nodePtr->left, nodePtr->data);
        }
        return true;
    }
    
    if(val < nodePtr->data){
        return deleteNode(nodePtr->left, val);
    }
    else{
        return deleteNode(nodePtr->right, val);
    }
}

//FIND IN ORDER PREDECESSOR
int BST::findPredecessor(Node* nodePtr){
    while(nodePtr->right != NULL){
        nodePtr = nodePtr->right;
    }
    
    return nodePtr->data;
}
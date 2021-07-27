#pragma once
#include "LinkedListInterface.h"
#include <string>
#include <sstream>

using namespace std;

template<typename ItemType>
class LinkedList : public LinkedListInterface<ItemType>{
public:

    struct Node{
        ItemType value;
        Node *next;

        Node(ItemType val){
            value = val;
            next = NULL;
        }
    };
    
    //CONSTRUCTOR    
    LinkedList(void){
        head = NULL;
        length = 0;
    }
    
    //DESTRUCTOR
    ~LinkedList(void){
        clear();
    }
    
    //INSERT HEAD
    void insertHead(ItemType inputValue){
        if (head == NULL){
            head = new Node(inputValue);
            length++;
            head->next = NULL;
            return;
        }
        else{
            Node* current = head;
            while(current != NULL){
                if(current->value == inputValue){
                    return;
                }
                current = current->next;
            }
            Node* temp = head;
            head = new Node(inputValue);
            head->next = temp;
            length++;
        }
    }
    
    //INSERT TAIL
    void insertTail(ItemType inputValue){
        
        if (head == NULL){
                head = new Node(inputValue);
                length++;
                head->next = NULL;
        }
        else{
            Node *current = head;
            while(current->next != NULL){
                if(current->value == inputValue || current->next->value == inputValue){
                    return;
                }
                current = current->next;
            }
            current->next = new Node(inputValue);
            length++;
            current->next->next = NULL;
        }
    }
    
    //INSERT AFTER
    void insertAfter(ItemType inputValue, ItemType insertionNode){
        if(head == NULL){
            return;
        }
        
        Node *current = head;
        Node *check = head;
        
        while(check != NULL){
            if(check->value == inputValue){
                return;
            }
            check = check->next;
        }
        check = head;
        bool exists = false;
        
        while(check != NULL){
            if(check->value == insertionNode){
                exists = true;
            }
            check = check->next;
        }
        
        if(!exists){
            return;
        }
    
        while(current->value != insertionNode){
            current = current->next;
        }
        Node *temp = current->next;
        current->next = new Node(inputValue);
        current = current->next;
        current->next = temp;
        length++;
        return;
    }
    
    //REMOVE
    void remove(ItemType inputValue){
        if(head == NULL){
            return;
        }
        
        Node *temp = head;
        
        if(head->value == inputValue){
            head = head->next;
            delete temp;
            temp = NULL;
            length--;
            return;
        }
        else{
            while(temp->next != NULL){
                if(temp->next->value == inputValue){
                    Node *temp2 = temp->next;
                    temp->next = temp2->next;
                    delete temp2;
                    temp2 = NULL;
                    length--;
                    return;
                }
                temp = temp->next;
            }
        }
    }
    
    //CLEAR
    void clear(){
        while(head != NULL){
            remove(head->value);
        }
    }
    
    //AT
    ItemType at(int index){
        Node *current = head;
        
        if(index < 0 || index >= length){
            throw out_of_range("Index out of range");
        }
        for(int i = 0; i < length; i++){
            if(i == index){
                return current->value;
            }
            current = current->next;
        }
    }
    
    //SIZE
    int size(){
        return length;
    }
    
    //TO STRING
    string toString(){
        stringstream listString;
        Node *current = head;
        
        for(int i = 0; i < length; i++){
            if(i == length - 1){
                listString << current->value;
            }
            else{
                listString << current->value << " ";
            }
            current = current->next;
        }
        
        return listString.str();
    }
    
private:
    Node* head;
    int length;
};
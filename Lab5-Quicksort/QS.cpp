#include "QS.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//CONSTRUCTOR
QS::QS(){
    position = 0;
    data = NULL;
    maxSize = 0;
}

//DESTRUCTOR
QS::~QS(){
    clear();
}

//QUICK SORT
void QS::quickSort(int left, int right){
    if((right - left) < 1){
        return;
    }
    
    int pivot = medianOfThree(left, right);
    pivot = partition(left, right, pivot);
    
    quickSort(left, pivot - 1);
    quickSort(pivot + 1, right);
}

//SORT ALL
void QS::sortAll(){
    if(position == 0){
        return;
    }
    
    int first = 0;
    int last = position - 1;
    
    quickSort(first, last);
    
}

//MEDIAN OF THREE
int QS::medianOfThree(int left, int right){
    int middle = (left + right)/2;
    int tempInt = 0;
    
    if(position == 0 
        || left < 0
        || right >= position
        || left >= right)
    {
        return -1;
    }
    
    
    if(data[left] > data[middle]){
        tempInt = data[left];
        data[left] = data[middle];
        data[middle] = tempInt;
    }
    if(data[middle] > data[right]){
        tempInt = data[middle];
        data[middle] = data[right];
        data[right] = tempInt;
    }
    if(data[left] > data[middle]){
        tempInt = data[left];
        data[left] = data[middle];
        data[middle] = tempInt;
    }
    
    return middle;
}

//PARTITION
int QS::partition(int left, int right, int pivotIndex){
     if(position == 0 
        || left < 0
        || right >= position
        || left >= right
        || pivotIndex < left
        || pivotIndex > right)
    {
        return -1;
    }
    
    int tempInt = data[pivotIndex];
    data[pivotIndex] = data[left];
    data[left] = tempInt;
    
    int up = left + 1;
    int down = right;
    
    do{
        while(data[up] <= data[left] && up < right){
            up++;
        }
        while(data[down] > data[left] && down > left){
            down--;
        }
        if(up < down){
            tempInt = data[up];
            data[up] = data[down];
            data[down] = tempInt;
        }
    }while(up < down);
    
    tempInt = data[left];
    data[left] = data[down];
    data[down] = tempInt;
    
    return down;
}

//GET ARRAY
string QS::getArray()const{
    if(data == NULL){
        return "";
    }
    stringstream arrayString;
    
    for(int i = 0; i < position; i++){
        if(i == (position - 1)){
            arrayString << data[i];
        }
        else{
            arrayString << data[i] << ",";
        }
    }
    
    return arrayString.str();
}

//GET SIZE
int QS::getSize()const{
    return (position);
}

//ADD TO ARRAY
bool QS::addToArray(int value){
    if(position > (maxSize - 1)){
        return false;
    }
    
    data[position] = value;
    position++;
    
    return true;
}

//CREATE ARRAY
bool QS::createArray(int capacity){
    clear();
    
    if(capacity <= 0){
        return false;
    }
    
    data = new int[capacity];
    maxSize = capacity;
    
    return true;
}

//CLEAR
void QS::clear(){
    if(data == NULL){
        return;
    }
    delete [] data;
    maxSize = 0;
    position = 0;
    data = NULL;
}
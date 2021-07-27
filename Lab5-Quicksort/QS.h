#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"
#include <iostream>
#include <string>
using namespace std;

class QS : public QSInterface{
public:
    QS();
    ~QS();

    void quickSort(int left, int right);
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    
    string getArray()const;
    int getSize()const;
    bool addToArray(int value);
    bool createArray(int capacity);
    void clear();
private:
    int *data;
    int position;
    int maxSize;
};

#endif
//
//  priorityQueue.h
//  Algoritma II Heap
//
//  Created by Hasan Akgün on 03/11/14.
//  Copyright (c) 2014 Hasan Akgün. All rights reserved.
//

#ifndef __Algoritma_II_Heap__priorityQueue__
#define __Algoritma_II_Heap__priorityQueue__

#include <iostream>
#include <vector>
#include <string>

using namespace std;




class priorityQueue {
private:
    vector<int> array;
    int heapSize;
    int d,m,n,logLevel;
    int insertCount, updateCount, removeCount, operationCount, errorCount;
    double p;
    void maxHeapify(int);
public:
    void buildMaxHeap();
    priorityQueue(string, int, int, int, double);
    void heapSort();
    int maximum();
    int extractMax();
    void update(int, int);
    void insert(int);
    void remove(int);
    void print();
    void log(string, int);
};


#endif /* defined(__Algoritma_II_Heap__priorityQueue__) */

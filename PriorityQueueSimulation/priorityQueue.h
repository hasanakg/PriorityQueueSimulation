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
    double cpu_time_used;
    
    
    void maxHeapify(int);
    void buildMaxHeap();
    void heapSort();
    void log(string, int);
public:
    priorityQueue(string, int, int, int, double);
    void insert(int);
    void update(int, int);
    void remove(int);
    int maximum();
    int extractMax();
    void print();
    void output(string);
};


#endif /* defined(__Algoritma_II_Heap__priorityQueue__) */

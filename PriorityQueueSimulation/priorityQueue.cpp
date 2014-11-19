//
//  priorityQueue.cpp
//  Algoritma II Heap
//
//  Created by Hasan Akgün on 03/11/14.
//  Copyright (c) 2014 Hasan Akgün. All rights reserved.
//

#include "priorityQueue.h"
#include <fstream>
#include <ctime>

priorityQueue::priorityQueue(string path, int dIn, int nIn, int mIn, double pIn) {
    d = dIn; // d-ary tree
    n = nIn; // After M operations, N applicants will be invited
    m = mIn; // After M operation, simulation will stop
    p = pIn; // Every operation is an update with probability p
    
    operationCount = 0;
    insertCount = 0;
    updateCount = 0;
    removeCount = 0;
    errorCount = 0;
    heapSize = (int)array.size();
    
    logLevel = 1; // 0 Errors 1 Infos
    
    ifstream inputFile;
    inputFile.open(path);

    srand((unsigned)time(0));

    if(!inputFile.is_open()) {
        log("ERROR:\tFile not exists!", 0);
        return;
    }
    
    string line, eng, math, gpa;
    getline(inputFile, line, '\n');
    
    for (operationCount = 0; operationCount < m;) { // After M operation, simulation will stop
        double rnd = (double)rand()/RAND_MAX; //Random value between 0-1
        if(rnd <= p) {
            if(array.size() == 0) {
                log("ERROR:\tHeap is empty!", 0);
            }
            else
            {
                int i = rand() % array.size();
                int key = rand() % 21 - 10;
                int val = array[i];
                update(i, array[i]+key);
                log("UPDATE:\t Index:\t" + to_string(i) + " updated from\t" + to_string(val) + "to\t" + to_string(array[i]), 1);
                operationCount++;
                updateCount++;
            }
        }
        else {
            inputFile >> eng >> math >> gpa; //Read marks
            
            insert(stod(eng)*0.25 + stod(math)*0.30 + stod(gpa)*0.45);
            log("INSERT:\t Value: \t" + to_string(array[array.size()-1]), 1);
            operationCount++;
            insertCount++;
        }
        if(rnd <= 0.2) {
            if(array.size() == 0) {
                log("ERROR:\t Heap is empty!", 0);
            }
            else {
                int i = rand() % array.size();
                int val = array[i];
                remove(i);
                log("REMOVE:\t Index:\t " + to_string(i) + "\tValue: \t" + to_string(val), 1);
                operationCount++;
                removeCount++;
            }
        }
    }
    if (n > array.size()) {
        n = (int)array.size();
    }
    for (int i = 0; i < n; i++) {
        log("MAX-REMOVE:\t Value:\t" + to_string(extractMax()), 1);
    }
    output("/Users/hasanakg/Desktop/output.txt");
    
    inputFile.close();
}

void priorityQueue::maxHeapify(int i) {

    int largest = i;
    
    
    for (int j = i*d+1; j <= (i+1)*d; j++) {
        if(j < heapSize && array[j] > array[largest])
            largest = j;
    }
    
    if(largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        maxHeapify(largest);
    }
}

void priorityQueue::buildMaxHeap() {
    heapSize = (int)array.size();
    for(int i = heapSize/d-1; i >= 0; i--)
        maxHeapify(i);
}

void priorityQueue::heapSort() {
    buildMaxHeap();
    print();
    int temp;
    for (size_t i = array.size()-1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapSize--;
        maxHeapify(0);
        print();

    }
    heapSize = (int)array.size();
}

int priorityQueue::maximum() {
    return array[0];
}

int priorityQueue::extractMax() {
    if(heapSize < 1)
        throw underflow_error("heap underflow");
    int max = array[0];
    
    array[0] = array[array.size()-1];
    
    heapSize--;
    array.pop_back();
    maxHeapify(0);
    
    return max;
}

void priorityQueue::update(int i, int key) {
    if(key < array[i]) {
        array[i] = key;
        maxHeapify(i);
        return;
    }
    
    array[i] = key;
    int parent = (i-1)/d;
    
    while (i > 0 && array[parent] < array[i]) {
        int temp = array[parent];
        array[parent] = array[i];
        array[i] = temp;
        i = parent;
        parent = (i-1)/d;
    }

}

void priorityQueue::insert(int key) {
    heapSize++;
    array.push_back(INT_MIN);
    update(heapSize-1, key);
}

void priorityQueue::remove(int i) {
    heapSize--;
    array[i] = array[array.size()-1];
    array.pop_back();
    maxHeapify(i);
}

void priorityQueue::print() {
    for(int i=0; i<array.size(); i++)
        cout << array[i] << "\t";
    cout << endl;
}

void priorityQueue::log(string str, int level) {
    if(level == 0)
        errorCount++;
    if(level >= logLevel)
        cout << str << endl;
}

void priorityQueue::output(string path) {
    ofstream outputFile(path);
    
    outputFile << "Operation count: \t" << operationCount <<  endl;
    outputFile << "Insert count: \t\t" << insertCount << endl;
    outputFile << "Remove count: \t\t" << removeCount << endl;
    outputFile << "Update count: \t\t" << updateCount << endl;
    outputFile << "Error count: \t\t" << errorCount << endl;
    outputFile << "Removed max count: \t" << n << endl;
    outputFile << "Total applicants: \t" << array.size() << endl;
    
    outputFile.close();
}
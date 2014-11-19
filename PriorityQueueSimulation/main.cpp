//
//  main.cpp
//  Algoritma II Heap
//
//  Created by Hasan Akgün on 03/11/14.
//  Copyright (c) 2014 Hasan Akgün. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "priorityQueue.h"

int main(int argc, const char * argv[]) {
    
    int d,n,m;
    double p;
    
    d = atoi(argv[1]);
    m = atoi(argv[2]);
    n = atoi(argv[3]);
    p = atof(argv[4]);
    

    priorityQueue queue("/Users/hasanakg/Downloads/scores.txt", d, m, n, p);

    
    return 0;
}

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
    priorityQueue queue("/Users/hasanakg/Downloads/scores.txt", 2, 10, 100000, 0.80);
    return 0;
}

PriorityQueueSimulation
=======================

A school project includes priority queue implemented with heap-sort algorithm.

Best N applicants will be removed after M operations, if N is bigger than the number of applicants all applicants will be removed.

Each operation is an update with a probability of P and addition of new applicant with a probability of 1-P.

If an operation is update, it updates a random applicant with a random increment between -10 and 10.

Otherwise it is a new application and its final score are read and calculated from the provided input file.

For each simulation step, a random applicant withdraws his/her application with a probability of 0.2.

Simulation stops after M add, update or remove operations.

Usage
=======================

./pq d M N P

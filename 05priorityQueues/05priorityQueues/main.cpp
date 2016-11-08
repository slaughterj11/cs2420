/*
 Chris Darais
 Assignment - 05priorityQueues
 A01160727
 */


#include <iostream>
#include <time.h>
#include "heap.h"


int main(){
    int tests;
    std::cout << "Enter number of numbers to test: ";
    std::cin >> tests;
    
    Heap heap;
    Heap heap2;
    
    srand(unsigned(time(NULL)));
    
    for (int i = 0; i < tests; i++) {
        int num = rand() % 1000;
        heap.insert(num);
    }
    
    heap.print(true);
    
    return 0;
    
}

#include <stdio.h>
#include <iostream>
#include "heap.h"

Heap::Heap(){
    minHeap = NULL;
    maxHeap = NULL;
    median = 0;
    first = true;
}

void Heap::insert(int number) {
    node * temp = new node();
    
    if (first) {
        first = false;
        median = number;
        return;
    }
    
    if (number >= median) {
        temp -> value = number;
        
        if (minHeap == NULL) {
            minHeap = temp;
            ++minMerges;
            return;
        }
        
        insertMin(temp);
    }
    
    if (number < median) {
        temp->value = number;
        
        if (maxHeap == NULL) {
            maxHeap = temp;
            ++maxMerges;
            return;
        }
        
        insertMax(temp);
    }
}//end insert

void Heap::insertMin(node * newNode){
    ++minMerges;
    minHeap = mergeMin(minHeap, newNode);
    balance();
}//end insertMin

void Heap::insertMax(node * newNode){
    ++maxMerges;
    maxHeap = mergeMax(maxHeap, newNode);
    balance();
}//end insertMax

Heap::node * Heap::mergeMin(node * me, node * newNode) {
    ++minRecursions;
    node * temp;
    
    if (me == NULL) return newNode;
    
    if (newNode == NULL) return me;
    
    if (me->value <= newNode->value)
    {
        me->right = mergeMin(me->right, newNode);
        temp = me;
    }
    else
    {
        newNode->right = mergeMin(me->right, me);
        temp = newNode;
    }
    
    
    return temp;
}//end mergeMin

Heap::node * Heap::mergeMax(node * me, node * newNode) {
    ++maxRecursions;
    
    node * temp;
    
    if (me == NULL) return newNode;
    
    if (newNode == NULL) return me;
    
    if ( me -> value > newNode -> value){
        me -> left = mergeMax( me -> left, newNode);
        temp = me;
    }
    else
    {
        newNode->left = mergeMax(me->left, me);
        temp = newNode;
        
    }
    
    return temp;
}//end mergeMax

Heap::node * Heap::newMedianFromHeap(node * me){
    median = me -> value;
    if (me -> right != NULL) return minHeap -> right;
    else return maxHeap -> left;
}//end newMedianHeap

void Heap::balance() {
    node * temp = new node();
    temp -> value = median;
    
    if (getSize(minHeap) - 1 > getSize(maxHeap)) {
        insertMax(temp);
        minHeap = newMedianFromHeap(minHeap);
    }
    else if (getSize(maxHeap) - 1 > getSize(minHeap)) {
        insertMin(temp);
        maxHeap = newMedianFromHeap(maxHeap);
    }
}//end balance

int Heap::getSize(node * me) {
    if (me) return getSize(me->left) + getSize(me->right) + 1;
    
    return 0;
}//end getSize

void Heap::print(bool first){
    balance();
    if (first) {
        
        std::cout << "\n\n-- heaps --\n";
        std::cout << "max med min\n";
        std::cout << "-----------\n";
        if (median < 10) std::cout << "      ";
        else if(median < 100)std::cout << "     ";
        else std::cout << "    ";
        
        std::cout << median << std::endl;
        
        printStructures(maxHeap, minHeap);
    }
    
    stats();
}//end print

void Heap::printNumber(int number, bool min){
    if (number < 10) std::cout << "  ";
    else if(number < 100)std::cout << " ";
    std::cout << number;
    if (min) std::cout << std::endl;
}//end printNumber

void Heap::printSpaces(int spaces){
    for (int i = 0; i < spaces; i++) {
        std::cout << " ";
    }
}//end printSpaces

void Heap::printStructures(node * max, node * min){
    
    while (max && min) {
        printNumber(max -> value, false);
        printSpaces(5);
        printNumber(min -> value, true);
        max = max -> left;
        min = min -> right;
    }
    while (max){
        printNumber(max -> value, true);
        max = max -> left;
    }
    while (min){
        printSpaces(8);
        printNumber(min -> value, true);
        min = min -> right;
    }
}//end printStructure

void Heap::stats() {
    balance();
    std::cout << "\nMerges into min heap: " << minMerges;
    std::cout << "\nMerges into max heap: " << maxMerges;
    std::cout << "\nMin heap recursions: " << minRecursions;
    std::cout << "\nMax heap recursions; " << maxRecursions;
    std::cout << "\nThe median number is: " << median;
    std::cout << "\nThe total heap size is (without median): " << getSize(maxHeap) + getSize(minHeap);
    std::cout << "\nThe total heap size is (with median): " << getSize(maxHeap) + getSize(minHeap) + 1;
    std::cout << "\n";
}//stats



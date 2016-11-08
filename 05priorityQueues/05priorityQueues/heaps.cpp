#include <stdio.h>
#include <iostream>


class Heap {
private:
    struct node {
        node * left = NULL;
        node * right = NULL;
        int value = NULL;
    };
    
    
    int minMerges, minRecursions,
        maxMerges, maxRecursions;
    
    node * minHeap, * maxHeap;
    int median;
    bool first = true;
    
public:
    
    Heap(){
        minHeap = NULL;
        maxHeap = NULL;
        median = 0;
    }
    
    
    void insert(int number) {
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
        
    }
    
    void insertMin(node * newNode){
        ++minMerges;
        minHeap = mergeMin(minHeap, newNode);
    }
    
    void insertMax(node * newNode){
        ++maxMerges;
        maxHeap = mergeMax(maxHeap, newNode);
    }
    
    node * mergeMin(node * me, node * newNode) {
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
    }
    
    node * mergeMax(node * me, node * newNode) {
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
    }
    
    void balance() {
        node * temp = new node();
        
        temp -> value = median;
        
        if (sizeOf(minHeap) - 1 > sizeOf(maxHeap)) {
            maxHeap = mergeMax(maxHeap, temp);
            median = minHeap->value;
            minHeap = mergeMin(minHeap->left, minHeap->right);
            return;
        }
        else if (sizeOf(maxHeap) - 1 > sizeOf(minHeap)) {
            median = maxHeap->value;
            maxHeap = mergeMax(maxHeap->left, maxHeap->right);
        }
        return;
    }
    
    int sizeOf(node * me) {
        if (me) return sizeOf(me->left) + sizeOf(me->right) + 1;
        
        return 0;
    }
    
    
    void report() {
        std::cout << "min inserts: " << minMerges << " max inserts: " << maxMerges << std::endl;
        std::cout << "minRecursions: " << minRecursions << " maxRecursions; " << maxRecursions << std::endl;
        std::cout << "The median number is: " << median << "!" << std::endl;
        std::cout << "The total heap size is: " << sizeOf(maxHeap) + sizeOf(minHeap) << "!" << std::endl;
        
    }
    
    
};


int main(){
    
    Heap test;
    test.insert(5);
    test.insert(8);
    test.insert(10);
    test.insert(12);
    test.insert(11);
    test.insert(11);
    test.insert(7);
    test.insert(3);
    test.insert(2);
    test.insert(1);
    test.insert(4);
    
    test.balance();
    test.report();
    return 0;
    
}

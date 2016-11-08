#ifndef heap_h
#define heap_h

#include <stdio.h>

class Heap {

private:
    struct node {
        node * left = NULL;
        node * right = NULL;
        int value = NULL;
    };
    
    
    int minMerges,
        minRecursions,
        maxMerges,
        maxRecursions,
        median;
    
    node * minHeap,
         * maxHeap;

    bool first;
    
public:
    
    Heap();
    
    void insert(int);
    
    void insertMin(node *);
    
    void insertMax(node *);
    
    node * mergeMin(node *, node *);
    
    node * mergeMax(node *, node *);
    
    node * newMedianFromHeap(node *);
    
    void balance();
    
    int getSize(node * me);
    
    void print(bool);
    
    void printNumber(int, bool);
    
    void printSpaces(int );
    
    void printStructures(node *, node *);
    
    void stats();
    
};
#endif /* heap_h */

/*
 A01160727
 Chris Darais
 03 AVL
 
 IDE Used is xCode (macOS)
 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "Game.h"
#include "avlTree.h"

int main() {
    
    
    Game g("dictionary.txt");
    
    AvlTree<int> testTree;
    
    std::string output;
    
    testTree.insert(1);
    testTree.insert(3);
    testTree.insert(5);
    testTree.insert(7);
    testTree.insert(9);
    testTree.insert(9);
    testTree.insert(9);
    testTree.insert(11);
    testTree.insert(2);
    testTree.insert(9);
    testTree.insert(4);
    testTree.insert(8);
    
    std::cout << std::endl << testTree.toString("");
    
    testTree.remove(7);
    testTree.remove(9);
    
    std::cout << std::endl << testTree.toString("");
    
    testTree.insert(30);
    testTree.insert(50);
    testTree.insert(30);
    testTree.insert(30);
    testTree.insert(15);
    testTree.insert(18);
    testTree.insert(17);
    
    std::cout << std::endl << testTree.toString("");

    testTree.removeMin();
    
    std::cout << std::endl << testTree.toString("");

    testTree.removeMin();
    
    std::cout << std::endl << testTree.toString("");

    testTree.removeMin();
    
    std::cout << std::endl << testTree.toString("");
    
    std::cout << std::endl << testTree.toString2("");

    
    g.play("this", "those");
    g.play("vicki", "allan");
    g.play("oops", "pops");
    g.play("happily", "angrily");
    g.play("slow", "fast");
    g.play("stone", "money");
    g.play("stupid","answer");
    g.play("kiss", "woof");
    g.play("cock", "numb");
    g.play("jura", "such");
    g.play("stet", "whey");
    g.play("hiking", "edited");
    
    return 0;
}



#include <iostream>
#include <fstream>
#include <assert.h>
#include "Game.h"

void printLines(){
    std::cout << "-------------\n\n";
}

void printString(std::string line){
    std::cout << std::endl << line << std::endl;

}

int main() {
    
    std::ifstream inf;
    
    inf.open("prog2in.txt");
    
    assert(inf);
    
    //variable for how many trees we are making
    const int SIZE = 12;
    
    //words to find
    std::string word1 = "happy";
    std::string word2 = "lick";
    
    Tree t[SIZE];
    Tree cloned[SIZE];
    
    //1 & 3 - builds tree
    printString("Building trees");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << " is building\n............\n";
        t[i].buildFromFile(inf);
        std::cout << "Tree # " << i << " finished\n\n";
    }
    printString("Tree built!");
    printLines();
    
    
    
    //2 - finds word
    printString("Finding words");
    printLines();
    std::cout << "Finding: " << word1 << std::endl;
    for (int i = 0; i < SIZE; i++) {
        if(t[i].findWord(word1, t[i].root) -> word.compare(word1) != 0) std::cout << "Not Found by tree " << i << "\n";
        else std::cout << "Found by tree: " << i << " @ memory address: " << t[i].findWord(word1, t[i].root) << std::endl;
    }
    std::cout << "Finding: " << word2 << std::endl;
    for (int i = 0; i < SIZE; i++) {
        if(t[i].findWord(word2, t[i].root) -> word.compare(word2) != 0) std::cout << "Not Found by tree " << i << "\n";
        else std::cout << "Found by tree: " << i << " @ memory address: " << t[i].findWord(word2, t[i].root) << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    // 4 prints indented tree
    printString("Indented Tree");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << std::endl;
        t[i].printTree(t[i].root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    //5 prints preorder back out
    printString("Printing Preorder");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << std::endl;
        t[i].toPreorder(t[i].root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    //6 Cloning
    printString("Cloning");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Cloning Tree # " << i << std::endl;
        cloned[i].cloneFirstNode(t[i].root);
        cloned[i].printComparison(t[i].root, cloned[i].root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    //7 prints uppercase tree
    printString("Showing Uppercase");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << std::endl;
        t[i].upperCase(t[i].root);
        t[i].printUpper(t[i].root);
        std::cout << std::endl;

    }
    std::cout << std::endl;
    printLines();
    
    
    
    //9 Fringe stuff
    printString("Fringe Info");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << std::endl;
        t[i].findFringe(t[i].root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    //10 nodes per level
    printString("Nodes per level");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Tree # " << i << std::endl;
        t[i].findNodesPerLevel(t[i].root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    printLines();
    
    
    
    //8 deleting trees
    printString("Deleting all trees");
    printLines();
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Deleting Tree # " << i << std::endl;
        t[i].deleteTree(t[i].root);
        std::cout << "Tree Deleted\n\n";
    }
    std::cout << std::endl;
    printLines();
    
    
    return 0;
}

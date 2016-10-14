#include <iostream>
#include "Game.h"

//1 & 3 - Builds my tree from the file and does it in preorder fashion
Tree::node * Tree::buildFromPrefix(std::ifstream &inf, node * parent, node * lastNode, int newSiblingNumber){
    std::string newWord;
    int kidct = 0;
    
    inf >> newWord >> kidct;
    

    node * currentNode = new node();
    currentNode -> word = newWord;
    currentNode -> children = kidct;
    currentNode -> subtree = kidct;
    currentNode -> treeParent = lastNode;
    currentNode -> parent = parent;
    currentNode -> siblingNumber = newSiblingNumber;
    currentNode -> treeLevel = lastNode -> treeLevel + 1;
    
    if (currentNode -> treeLevel > treeHeight) treeHeight = currentNode -> treeLevel;
    if(kidct > 0) currentNode -> child = buildFromPrefix(inf, currentNode, currentNode, 1);
    if (newSiblingNumber < parent -> children && parent != NULL) currentNode -> sibling = buildFromPrefix(inf, parent, currentNode, (currentNode -> siblingNumber) + 1);
    int upCount = parent -> subtree;

    parent -> subtree = upCount + currentNode -> subtree;

    return currentNode;
}
void Tree::buildFromFile(std::ifstream &inf){
    node * firstNode = new node();
    std::string newWord;
    int kidct;
    
    
    inf >> newWord >> kidct;
    
    firstNode -> word = newWord;
    firstNode -> children = kidct;
    firstNode -> subtree = kidct + 1;
    firstNode -> treeParent = root;
    firstNode -> siblingNumber = kidct;
    if (kidct == 0) return;
    firstNode -> child = buildFromPrefix(inf, firstNode, firstNode, 1);
    root = firstNode;
    
}

//2 - Finds word in tree
Tree::node * Tree::findWord(std::string word, node * me){
    node * temp = new node();
    
    if (word.compare(me -> word) == 0) return me;
    
    if (me -> child != NULL) {
        temp = findWord(word, me -> child);
        if (temp -> word.compare(word) == 0) return temp;
    }
    
    if (me -> sibling != NULL){
        temp = findWord(word, me -> sibling);
        if (temp -> word.compare(word) == 0) return temp;
    }
    
    return temp;
}

//4 - Prints tree with indents, subtree size, and children
void Tree::printTree(node * me){
    for (int i = 0; i < me -> treeLevel; i++) {
        std::cout << " ";
    }
    std::cout << me -> word << "[" << me -> subtree << ":" << me -> children << "]\n";
    if (me -> sibling != NULL) printTree(me -> sibling);
    if (me -> child != NULL) printTree(me -> child);
}

//5 - Prints tree out in preorder text (like the input file)
void Tree::toPreorder(node * me){
    std::cout << me -> word << " " << me -> children << " ";
    if (me -> child != NULL) toPreorder(me -> child);
    if (me -> sibling) toPreorder(me -> sibling);
}

//6 - Clones the tree to a new tree, deep copy style
Tree::node * Tree::cloneNode(node * old, node * cloned, node * parent){
    
    node * currentNode = new node();
    currentNode -> word = old -> word;
    currentNode -> children = old -> children;
    currentNode -> subtree = old -> subtree;
    currentNode -> treeParent = cloned;
    currentNode -> parent = cloned;
    currentNode -> siblingNumber = old -> siblingNumber;
    currentNode -> treeLevel = old -> treeLevel;
    if(old -> child != NULL) currentNode -> child = cloneNode(old -> child, currentNode, old);
    if(old -> sibling != NULL) currentNode -> sibling = cloneNode(old -> sibling, currentNode, parent);
    
    return currentNode;
}
void Tree::cloneFirstNode(node * old){
    node * cloned = new node();
    cloned -> word = old -> word;
    cloned -> children = old -> children;
    cloned -> siblingNumber = old -> siblingNumber;
    cloned -> treeLevel = old -> treeLevel;
    cloned -> subtree = old -> subtree;
    cloned -> sibling = NULL;
    cloned -> child = NULL;
    cloned -> parent = NULL;
    cloned -> treeParent = NULL;
    cloned -> level = old -> level;
    
    if (old -> child != NULL) cloned -> child = cloneNode(old -> child, cloned, cloned);
    
    root = cloned;
}
void Tree::printComparison(node * org, node * clone){
    std::cout << org -> word << "[" << org -> subtree << ":" << org -> children << "]  " << org << " -- " << clone -> word << "[" << clone -> subtree << ":" << clone -> children << "] " << clone << std::endl;
    
    if (org -> sibling != NULL) printComparison(org -> sibling, clone -> sibling);
    if (org -> child != NULL) printComparison(org -> child, clone -> child);

}

//7 - turns the words to uppercase
void Tree::upperCase(node * me){
    for (int i = 0; i < me -> word.size(); i++) {
        me -> word[i] = toupper(me -> word[i]);
    }
    
    if (me -> child != NULL) upperCase(me -> child);
    if (me -> sibling != NULL) upperCase(me -> sibling);
    
}
void Tree::printUpper(node * me){
    std::cout << me -> word << std::endl;
    if (me -> sibling != NULL) printTree(me -> sibling);
    if (me -> child != NULL) printTree(me -> child);
}

//8 - Deletes the tree
void Tree::deleteTree(node * me){
    if (me -> child != NULL) deleteTree(me -> child);
    if (me -> sibling != NULL) deleteTree(me -> sibling);
    me = NULL;
    delete me;
}

//9 - Function finds fringe
void Tree::fringe(node * me){
    if (me -> child != NULL) fringe(me -> child);
    if (me -> sibling != NULL) fringe(me -> sibling);
    if (me -> child == NULL) fringedNodes[me -> treeLevel]++;

}
void Tree::findFringe(node * me){
    for (int i = 0; i < 1000; i++) {
        fringedNodes.push_back(0);
    }
    fringe(me);
    std::cout << "Fringe by tree level\n";
    std::cout << "Levels with 0 nodes are hidden\n";
    std::cout << "Level - Nodes\n";
    for (int i = 0; i < fringedNodes.size(); i++) {
        if(fringedNodes[i] != 0){
            if (i < 10) std::cout << "  " << i << "       " << fringedNodes[i] << std::endl;
            else std::cout << "  " << i << "      " << fringedNodes[i] << std::endl;
        }
    }
}

//10 - Finds the amount of nodes at each level of the binary tree
void Tree::nodesPerLevel(node * me){
    nodeCountPerLevel[me -> treeLevel]++;
    if (me -> child != NULL) nodesPerLevel(me -> child);
    if (me -> sibling != NULL) nodesPerLevel(me -> sibling);
}
void Tree::findNodesPerLevel(node * me){
    for (int i = 0; i < 1000; i++) {
        nodeCountPerLevel.push_back(0);
    }
    nodesPerLevel(me);
    std::cout << "Level - Nodes\n";
    std::cout << "Levels with 0 are hidden\n";
    for (int i = 0; i < nodeCountPerLevel.size(); i++) {
        if (nodeCountPerLevel[i] != 0) {
            if(i < 10)std::cout << "  " << i << "       " << nodeCountPerLevel[i] << std::endl;
            else std::cout << "  " << i << "      " << nodeCountPerLevel[i] << std::endl;
        }
    }
}


#ifndef Game_h
#define Game_h
#include <fstream>
#include <vector>

class Tree{
public:
    //node structure used
    struct node{
        std::string word;
        int children, siblingNumber, treeLevel = 0, subtree = 1;
        node * sibling = NULL;
        node * child = NULL;
        node * parent = NULL;
        node * treeParent = NULL;
        int level = 0;
    };
    node * root;


    //1 Prototype - Builds my tree from the file and does it in preorder fashion
    node * buildFromPrefix(std::ifstream &, node *, node *,int);
    void buildFromFile(std::ifstream &);

    //2 Prototype - Finds word in tree
    node * findWord(std::string, node *);
    
    //4 Prototype - Print indented tree
    void printTree(node *);

    //5 Prototype - Prints to preorder
    void toPreorder(node *);

    //6 Protoype - Cloning
    node * cloneNode(node *, node *, node *);
    void cloneFirstNode(node *);
    void printComparison(node *, node *);

    //7 Prototype - Uppercase the words
    void upperCase(node *);
    void printUpper(node *);
    
    //8 Prototype - Deletes tree
    void deleteTree(node *);

    //9 Prototype - Fringe stuff
    void fringe(node *);
    void findFringe(node *);

    //10 Prototype - Finds nodes
    void nodesPerLevel(node *);
    void findNodesPerLevel(node *);
    

    
private:
    int treeHeight = 0;
    std::vector<int>fringedNodes;
    std::vector<int>nodeCountPerLevel;
};


#endif /* Game_h */

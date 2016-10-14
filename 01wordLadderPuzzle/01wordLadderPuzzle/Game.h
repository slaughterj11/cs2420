
#ifndef Game_h
#define Game_h
class Game{
public:
    typedef std::vector<std::string> Ladder;
    
    struct data{
        std::string word;
        bool used;
    };
    
    struct node{
        Ladder ladders;
        node *next = NULL;
        node *previous = NULL;
    };
    
    node * head;
    node * tail;
    
    void insert(Ladder newLadder){
        node * newNode = new node();
        
        newNode -> ladders = newLadder;
//        newNode -> next = head;
        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    
    Ladder pop(){
        if (!tail) return Ladder();
        
        Ladder returnLadder = tail->ladders;
        
        node * temp = tail;
        tail = temp -> previous;
        delete temp;
              
        return returnLadder;
    }
    
    void resetLinkedList(){
        
        head = NULL;
        tail = NULL;
    }
    
    
    void printList(Ladder);
    
    Game(std::string);
    
    void listWords();//std::string firstWord, std::string secondWord);
    
    void play(std::string, std::string);
    
    bool sizeCompare(std::string, std::string);
    
    bool findWord(std::string);
    
    bool changeWord(Ladder, std::string);
    
private:
    std::vector<data>dict;
    Ladder ladder;
    
};


#endif /* Game_h */

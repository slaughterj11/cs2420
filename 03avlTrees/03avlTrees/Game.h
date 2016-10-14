
#ifndef Game_h
#define Game_h
class Game{
public:
    typedef std::vector<std::string> Ladder;
    
    struct data{
        std::string word;
        bool used;
        int position;
    };
    
    struct node{
        Ladder ladders;
        int distanceAway;
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
        putOn++;
    }
    
    void insertOrdered(Ladder newLadder, int oldDistance){
        tail = recursiveInsert(tail, newLadder, oldDistance);
        putOn++;
    }
    
    node * recursiveInsert(node * tail, Ladder newLadder, int oldDistance){
        
        if (!tail || (tail -> ladders.size() + tail -> distanceAway) > (newLadder.size() + oldDistance)) {
            tail = insertLocalTail(tail, newLadder, oldDistance);
        }else{
            tail -> previous = recursiveInsert(tail -> previous, newLadder, oldDistance);
        }
        
        return tail;
    }
    
    node * insertLocalTail(node * tail, Ladder newLadder, int oldDistance){
        node * newNode = new node();
        
        newNode -> ladders = newLadder;
        newNode -> distanceAway = oldDistance;
        
        newNode -> previous = tail;
        
        if (!this -> head) this -> head = newNode;
        if (!this -> tail) this -> tail = newNode;
        
        tail = newNode;
        
        if (!head -> next) head = tail;
        return tail;
        

    }
    
    Ladder pop(){
        if (!tail) return Ladder();
        
        Ladder returnLadder = tail->ladders;
        
        node * temp = tail;
        tail = temp -> previous;
        delete temp;
        pullOf++;
        return returnLadder;
    }
    
    void resetLinkedList(){
        putOn = 0;
        pullOf = 0;
        head = NULL;
        tail = NULL;
    }
    
    void printList(Ladder);
    
    Game(std::string);
    
    void listWords();//std::string firstWord, std::string secondWord);
    
    void play(std::string, std::string);
    
    bool sizeCompare(std::string, std::string);
    
    bool findWord(std::string);
    
    bool aStarFindWord(std::string, int);
    
    bool changeWord(Ladder, std::string);
    
    bool aStarChangeWord(Ladder, std::string);
    
private:
    std::vector<data>dict;
    Ladder ladder;
    int putOn = 0;
    int pullOf = 0;
    
};


#endif /* Game_h */

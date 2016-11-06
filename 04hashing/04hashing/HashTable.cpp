/*
 Chris Darais
 A01160727
 04 - Hashing
 
 made with xCode
 */

#include "HashTable.h"
#include <iostream>
#include <cstdlib>

#include <fstream>
#include <string>

using namespace std;

class Pair{
public: string word;
    int ct;
    Pair(string w = "no word", int c = 0){
        word = w; ct = c;
    }
    string toString(){
        stringstream ss;
        ss << word << " " << ct; return ss.str();
    }
};
/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 ) return true;
    
    if( n == 1 || n % 2 == 0 ) return false;
    
    for( int i = 3; i * i <= n; i += 2 ) if( n % i == 0 ) return false;
    
    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 ) ++n;
    
    for( ; !isPrime( n ); n += 2 ) ;
    
    return n;
}


int letterValue(string word){
    int lValue = 0;
    for (int i = 0; i < word.length(); i++){
        switch (word[i]) {
            case 'q': case 'z':
                lValue += 10; break;
                
            case 'j': case 'x':
                lValue += 8; break;
                
            case 'k':
                lValue += 5; break;
            
            case 'f': case 'h': case 'v': case 'w': case 'y':
                lValue += 4; break;
                
            case 'b': case 'c': case 'm': case 'p':
                lValue += 3; break;
                
            case 'd': case 'g':
                lValue += 2; break;
                
            default:
                lValue++; break;
        } //end switch
    } //end for
    
    return lValue;
}


int wordFrequency(string word, HashTable<string, Pair> hash){
    int value;
    
    switch (hash.find(word) -> ct) {
        case 0:
            value = 5; break;
            
        case 1: case 2: case 3:
            value = 4; break;
            
        case 4: case 5: case 6:
            value = 3; break;
            
        case 7: case 8: case 9:
            value = 2; break;
            
        default:
            value = 1; break;
    }//end switch
    
    return value;
}

int lengthValue(string word){
    int score = 0;
    switch (word.length()) {
        case 3:  score = 1; break;
            
        case 4:  score = 2; break;
            
        case 5:  score = 3; break;
            
        case 6:  score = 4; break;
            
        case 7:  score = 5; break;
            
        default: score = 6; break;
    }//end switch
    return score;
}

int score(string word, HashTable<string, Pair> hash){
    int total = letterValue(word) * wordFrequency(word, hash) * lengthValue(word);
    return total;
}



// Here is a simple test program
int main() {
    int total = 0, cTotal = 0, tableSize = 0, spaces = 3;
    
    std::string word;
    
    HashTable<string, Pair> data;
    
    std::ifstream fin;
    
    fin.open("game0.txt");
    
    std::cout << "-  Game Table  -\n";
    std::cout << "Word       Score\n";
    std::cout << "----------------\n";
    
    while (fin >> word){
        
        Pair * p = data.find(word);
        if (p == NULL){
            
        data.insert(word, new Pair(word, 1));
            tableSize++;
            cTotal = score(word, data);
            cout <<  word;
            for (int i = 0; i < 17 - word.length() - spaces; i++) {
                cout << ".";
            }
            if (cTotal < 100) cout << ".";
            cout << cTotal << endl;
            total += score(word, data);
        
        }//end if
        else {
            tableSize++;
            cTotal = score(word, data);
            if (cTotal > 99) spaces = 3;

            cout << word;
            for (int i = 0; i < 17 - word.length(); i++) {
                cout << ".";
            }
            cout << " previously inserted\n";
            p -> ct++;
            total += score(word, data);
        }//end else
        
        
    }//end while
    
    cout << "\n-  Table Info  -\n";
    cout << data.toString() << endl;
    cout << "\nThe total score is: " << total << "!" << endl;
    cout << "The size of the table is: " << tableSize << "!" << endl;
    
    return 0;
}

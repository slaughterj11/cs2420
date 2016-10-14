
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "Game.h"

void Game::printList(Ladder answer){
    
    std::cout << "\nThe ladder is\n";
    
    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << std::endl;
    }
    return;
}

bool Game::changeWord(Ladder ladder, std::string lookingWord){
    std::string tempWord;
    Ladder tempLadderData;
    std::string changingWord = ladder.back();
    
    for (int i = 0; i < changingWord.size(); i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            
            tempLadderData = ladder;
            tempWord = changingWord;
            tempWord[i] = j;
            
            if (findWord(tempWord)) {
                if (tempWord.compare(lookingWord) == 0){
                    tempLadderData.push_back(tempWord);
                    printList(tempLadderData);
                    return true;
                }else{
                    tempLadderData.push_back(tempWord);
                    insert(tempLadderData);
                }
            }
            
        }
    }
    return false;
}

bool Game::aStarChangeWord(Ladder ladder, std::string lookingWord){
    std::string tempWord;
    Ladder tempLadderData;
    std::string changingWord = ladder.back();
    int difference = 0;
    
    for (int i = 0; i < changingWord.size(); i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (changingWord[i] != lookingWord[i]) {
                
                tempLadderData = ladder;
                tempWord = changingWord;
                tempWord[i] = j;
            }
            if (findWord(tempWord)) {
                if (tempWord.compare(lookingWord) == 0){
                    tempLadderData.push_back(tempWord);
                    printList(tempLadderData);
                    return true;
                }else{
                    tempLadderData.push_back(tempWord);
                    difference = 0;
                    for (int m = 0; m < tempWord.size(); m++) {
                        if (tempWord[m] != lookingWord[m]) ++difference;
                    }
                    insertOrdered(tempLadderData, difference);
                }
            }
            
        }
    }
    return false;
}

Game::Game(std::string fileName){
    std::string word;
    
    std::ifstream myFile (fileName);
    
    if (myFile.is_open()) {
        
        struct data temp;
        
        while (getline(myFile, word)){
            while (word[word.size() - 1] > 123 || word[word.size() - 1] < 96) {
                word.pop_back();
            }
            temp.word = word;
            temp.used = false;
            dict.push_back(temp);
        }
        myFile.close();
    }
    
}

void Game::listWords(){
    
    std::cout << "First 10 words in the dictionary are: " << std::endl;
    
    for (int i = 0; i < 10; i++) {
        std::cout << i << " - " << dict[i].word << std::endl;
    }
    
    std::cout << std::endl;
    
}

bool Game::sizeCompare(std::string wordOne, std::string wordTwo){
    if (wordOne.length() == wordTwo.length())return true;
    return false;
}

bool Game::findWord(std::string word) {
    
    int max = (int)dict.size();
    int min = 1;
    int mid;
    
    while (min <= max) {
        mid = (min + max) / 2;
        if (word.compare(dict[mid].word) == 0 && !dict[mid].used){
            dict[mid].used = true;
            return true;
        }
        else if(word >= dict[mid].word) min = mid + 1;
        else max = mid - 1 ;
    }
    
    return false;
}

void Game::play(std::string wordOne, std::string wordTwo){
    
    for (int i = 0; i < dict.size(); i++) {
        dict[i].used = false;
    }
    
    std::cout << "Playing word ladder\n";
    std::cout << "-------------------\n";
    std::cout << "Turning " << "\"" << wordOne << "\"" << " into -> " << "\"" << wordTwo << "\"\n";
    
    //Look in dictionary
    if (!findWord(wordOne) || !findWord(wordTwo)){
        
        std::cout << "ERROR!\n";
        if (!findWord(wordOne) && !findWord(wordTwo)) std::cout << "\"" << wordOne << "\" & \"" << wordTwo << "\" is not found in the dictionary" << "\"\n";
        if (findWord(wordOne)) std::cout << "\"" << wordTwo << "\" is not found in the dictionary" << "\"\n";
        if (findWord(wordTwo)) std::cout << "\"" << wordOne << "\" is not found in the dictionary" << "\"\n";
        
    }
    //Compare sizes
    else if (!sizeCompare(wordOne, wordTwo)) std::cout << "ERROR!\n" << "\"" << wordOne << "\"" << " is not the same size as " << "\"" << wordTwo << "\"\n";
    
    //Find Ladder
    else {
        for (int i = 0; i < dict.size(); i++) {
            dict[i].used = false;
        }
        ladder.push_back(wordOne);
        
        bool found = false;
        
        found = changeWord(ladder, wordTwo);
        
        while (tail && !found) {
            
            found = changeWord(pop(), wordTwo);
            
        }
        
        if (!found) {
            std::cout << "\nNo ladder found\n";
        }
        
        std::cout << "\nBRUTE -- enqueue: " << putOn << " - dequeue: " << pullOf << std::endl;
        
        resetLinkedList();
        
        ladder.clear();
        if (found) {
            
            for (int i = 0; i < dict.size(); i++) {
                dict[i].used = false;
            }
            ladder.push_back(wordOne);
            
            bool found = false;
            
            found = aStarChangeWord(ladder, wordTwo);
            
            while (tail && !found) {
                
                found = aStarChangeWord(pop(), wordTwo);
                
            }
            
            if (!found) {
                std::cout << "\nNo ladder found\n";
            }
            
            std::cout << "\nASTAR -- enqueue: " << putOn << " - dequeue: " << pullOf << std::endl;

            
            resetLinkedList();
            
            ladder.clear();
        }
    }
    
    
    std::cout << "\n\n";
    
}












/*
 A01160727
 Chris Darais
 01 Word Ladder
 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "Game.h"

int main() {
    
    
    const int RANDOMCT = 1;
    Game g("dictionary.txt");
    g.listWords();

    g.play("this", "those");
    g.play("vicki", "allan");
    g.play("oops", "pops");
    g.play("happily", "angrily");
    g.play("slow", "fast");
    g.play("stone", "money");
    g.play("stupid","answer");
    for (int i = 0; i < RANDOMCT; i++)
//        g.play("flute");  //if two arguments are not provided, randomly pick both strings.  Use the length of provided argument as length of strings
  
    return 0;
}


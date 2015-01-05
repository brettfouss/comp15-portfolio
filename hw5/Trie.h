/*
 * Trie.h - Header File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions and variables 
 * of Trie class declared here.
 *
 */

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Node.h"

using namespace std;

class Trie {
public:

    //constructor and destructor
    Trie();
  //~Trie(); // CODE THIS

    //insert word into trie
    void insertWord   (string input, songByArtist* info, int freq);

    //print info for given word
    void printWord  (string input);

private:

    //convert string to alpha-only, lowercase
    string process(string word);

    //root node of trie
    Node* root;
};


#endif /* defined TRIE_H */

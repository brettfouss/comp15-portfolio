/*
 * Trie.cpp - Implementation File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions and variables of
 * Trie class defined here.
 *
 */

#include <iostream>
#include "Trie.h"

using namespace std;

//constructor
//effs: initializes root of trie
Trie::Trie()
{
    root = new Node();
}

//insertWord()
//purp: insert word into trie along with associated song info
//      and frequency of that word in song
//args: word to insert, pointer to associated song info, and freq
void Trie::insertWord(string input, songByArtist* info, int freq)
{
    Node* thisNode = root;

    //do not need to insert empty strings
    if (input.length() == 0) {
	return;
    }

    size_t length = input.length();

    //insert string into trie letter by letter
    for (size_t n = 0; n < length; n++) {
	Node* child = thisNode->findChild(input[n]);
	if (child != NULL)
	    thisNode = child;
	else {
	    Node* temp = new Node();
	    temp->setLetter(input[n]);
	    thisNode->appendChild(temp);
	    thisNode = temp;
	}
	if (n == (length-1)) {
	    thisNode->setWord(); //mark as word
	    //one word is marked, set info and frequency
	    thisNode->setInfo(info, freq); 
	}
    }
}

//printWord()
//purp: find word in trie, and print all songs info
//      contained within that node
//args: word to locate and print
void Trie::printWord(string input)
{
    Node* thisNode = root;
    size_t length = input.length();

    //locate word in trie
    while (thisNode != NULL) {
	for (size_t n = 0; n < length; n++) {
	    Node* temp = thisNode->findChild(input[n]);
	    if (temp == NULL)
		return;
	    thisNode = temp;
	}
	//only print if word exists in trie, else return
	if (thisNode->isWord()) {
	    thisNode->printInfo(input);
	    return;
	}
    }
    return;
}

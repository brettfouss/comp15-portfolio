/*
 * Node.h - Header File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions and variables 
 * of Node class declared here.
 *
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

//set to number of songs you want to store
//in each node - algorithm will only keep 
//this number of songs w/ max frequency
const int MAX_SONGS = 10;

//song info struct
struct songByArtist {
    std::string title;
    std::string artist;
    std::string *lyrics;
    int numLyrics;
};

using namespace std;

class Node {

public:

    //constructor and destructor
    Node();
    //~Node();

    //return and set letter of current node
    char getLetter();
    void setLetter(char c);

    //return and set word marker boolean
    bool isWord();
    void setWord();

    //insert and print song info
    void setInfo(songByArtist *info, int frequency);
    void printInfo(string word);

    //find, append children of current node
    Node* findChild(char c);
    void appendChild(Node* child);

private:
    int  songCount;
    char letter;

    //arrays of pointers to song info
    //and frequency of word in each song
    songByArtist * songInfo;
    int          * freq;

    //true if this node is end of a word
    bool marker;

    //vector of current node's children
    vector<Node*> theChildren;

    //sort song info by frequency
    void sort();

    //convert string to alpha-only, lowercase
    string process(string word);
};

#endif /* defined NODE_H */

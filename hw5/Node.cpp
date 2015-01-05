/*
 * Node.cpp - Implementation File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions of Node class
 * defined here.
 * 
 */

#include <iostream>
#include <vector>
#include <sstream>
#include "Node.h"

using namespace std;

//constructor
//effs: initializes private data
Node::Node()
{
    letter = ' ';
    songCount = 0;
    marker = false;

    //max # of songs can be modified in
    //in Node.h file (const)
    //algorithm will only keep up to max # of songs

    songInfo = new songByArtist[MAX_SONGS];
    freq = new int[MAX_SONGS];
}

//Node::~Node()
//{
//
//}

/* Public Functions */

//getLetter()
//purp: returns letter associated with current node
char Node::getLetter() { return letter; }

//setLetter()
//purp: sets current node to letter passed in as parameter
void Node::setLetter(char c) { letter = c; }

//isWord()
//purp: returns true if this node is end of word
bool Node::isWord() { return marker; }

//setWords()
//purp: sets current node as end of word
void Node::setWord() { marker = true; }

//setInfo()
//purp: store song, artist, lyric and frequency info
//      along with current node
//args: pointer to song info (title, artist, lyrics), which
//      are contained within a dynamic array elsewhere AND
//      frequency, which are stored in an static array of
//      MAX_SONG size in current node
//effs: adds songInfo/freq to end of respective arrays in
//      this current node UNLESS this node has 10 songs
//      stored already. in this case, info will only be
//      added if frequency of word is greater than
//      pre-existing minimum
void Node::setInfo(songByArtist * info, int newFreq) {
    if (songCount < 10) {
	songInfo[songCount].title = info->title;
	songInfo[songCount].artist = info->artist;
	songInfo[songCount].lyrics = info->lyrics;
	songInfo[songCount].numLyrics = info->numLyrics;
	freq[songCount] = newFreq;
	songCount++;
	return;
    } else {
	int min = freq[0];
	int minIndex = 0;
	for (int n = 1; n < MAX_SONGS; n++) {
	    if (freq[n] < min) {
		min = freq[n];
		minIndex = n;
	    }
	}
	if (newFreq > min) {
	    songInfo[minIndex].title = info->title;
	    songInfo[minIndex].artist = info->artist;
	    songInfo[minIndex].lyrics = info->lyrics;
	    songInfo[minIndex].numLyrics = info->numLyrics;
	    freq[minIndex] = newFreq;
	    return;
	}
    }
}

//printInfo()
//purp: prints title, artist, context of every instance
//      of given word for top 10 songs
//args: word to find, print
//note: data is unsorted before this function is called.
//      when this function is called, data is sorted into
//      ascending order based on frequency, and then printed
//      from most frequent to least frequent. 
void Node::printInfo(string word) 
{ 
    if (!isWord()) return;
    sort(); //sort arrays in to ascending order
    for (int n = (songCount-1); n >= 0; n--) {
	string title = songInfo[n].title;
	string artist = songInfo[n].artist;
	int numWords = songInfo[n].numLyrics;
	int startPrint = 0;
	int endPrint = numWords;
	string * l = songInfo[n].lyrics; 

	    for (int i = 0; i < numWords; i++) {
		//finds word in lyrics, will print UP TO five 
		//words before and/or after
		if (process(l[i]) == word) {
			if (i > 5) startPrint = (i-5);
			else startPrint = 0;
			if (i < (numWords - 5)) endPrint = (i+5);
			else endPrint = numWords;

			cout << "Title: " << title << endl;
			cout << "Artist: " << artist << endl;
			cout << "Context: ";

			for (int n = startPrint; n <= endPrint; n++) 
			    cout << l[n] << " ";
			cout << "\n\n";
		}
	    }
    }
}

//findChild()
//purp: locate node that contains given letter
//args: letter to find
//rets: pointer to that node OR null if child
//      does not exist
Node* Node::findChild(char c)
{
    for (size_t n = 0; n < theChildren.size(); n++) {
	Node* temp = theChildren.at(n);
	if (temp->getLetter() == c)
	    return temp;
    } /* else */ return NULL;
}

//appendChild()
//purp: add child node to vector of children of
//      current node
void Node::appendChild(Node* child) { theChildren.push_back(child); }

/* Private Functions */

//sort()
//purp: sort info and frequency arrays into ascending
//      order by frequency of given word
//effs: info and frequency arrays are sorted
//note: uses selection sort algorithm. this algorithm
//      is effective on small arrays, and these arrays
//      will never be larger than MAX_SONGS. 
void Node::sort()
{
    int toSort = 0;
    int atIndex = 0;
    int min;

    while (toSort < songCount) {
	min = freq[toSort];
	for (int n = toSort; n < songCount; n++) {
	    if (freq[n] < min) {
		min = freq[n];
		atIndex = n;
	    }
	}
	int tempF = freq[toSort];
	songByArtist tempI = songInfo[toSort];
	freq[toSort] = freq[atIndex];
	songInfo[toSort] = songInfo[atIndex];
	freq[atIndex] = tempF;
	songInfo[atIndex] = tempI;

	toSort++;
	atIndex = toSort;
    }
}

//process()
//purp: remove non-alphabetic characters from string,
//      convert entire string to lowercase
//args: string to convert
//rets: converted string
string Node::process(string word)
{
        ostringstream ss;
        for (size_t i=0;i<word.length();i++) {
                if (isalnum(word[i])){
                        ss << (char)(tolower(word[i]));
                }
        }
        return ss.str();
}

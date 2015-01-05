/*
 * SongSearch.cpp - Implementation File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions and variables 
 * of SongSearch class defined here.
 *
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "SongSearch.h"
#include "Trie.h"

using namespace std;

//constructor
//purp: initialize private data
SongSearch::SongSearch()
{
    songCount = 0;
    songCapacity = 10;

    //create Trie
    wordList = new Trie();

    //create dynamic array
    songInfo = new songByArtist[songCapacity];
}

//read_lyrics()
//purp: read in lyrics from file, insert songs into dynamic
//      array of songs, insert words into trie
void SongSearch::read_lyrics(const char * filename, bool show_progress)
{
        ifstream in(filename);			// creates an input stream
        int    song_count = 0;			// for progress indicator
	string artist, title, word;		// data from the file

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;

		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}
		// -- Create dynamic array for lyrics to be stored in
		string *lyrics = new string[10];
		int numOfWords = 0;
		int wordCap    = 10;

		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		while ( in >> word && word != "<BREAK>" ){
		    lyrics[numOfWords++] = word;
		    if (numOfWords == wordCap) {
			lyrics = expand(lyrics, numOfWords, wordCap);
	       		wordCap *= 2;
		    }
		}

                // -- insert song into array of songs
		songByArtist* info = insertSong(title, artist, 
					lyrics, numOfWords);

		// --  insert words into trie
		insertWord(lyrics, info, numOfWords);

		// -- Important: skip the newline left behind
		in.ignore();
	}
}


//expand()
//purp: expand dynamic array of lyrics
string* SongSearch::expand(string* replaceMe, int num, int curr_capacity)
{
    string* temp = new string[curr_capacity*2];

    for (int n = 0; n < num; n++)
	temp[n] = replaceMe[n];

    delete [] replaceMe;
    return temp;
}

//insertSong()
//purp: insert songByArtist struct into dynamic array of songs
//rets: pointer to this struct so that trie can access it
songByArtist* SongSearch::insertSong(string t, string a, string *l, int num)
{
    if (songCount == songCapacity) {
	songByArtist *temp = new songByArtist[songCapacity*2];
	for (int n = 0; n < songCount; n++)
	    temp[n] = songInfo[n];
	songCapacity *= 2;
	delete [] songInfo;
	songInfo = temp;
    }

    songInfo[songCount].title  = t;
    songInfo[songCount].artist = a;
    songInfo[songCount].lyrics = l;
    songInfo[songCount].numLyrics = num;

    songCount++;
    return (songInfo+(songCount-1));
}

//printSongs()
//purp: print dynamic array of songs
//note: I used this for debugging
void SongSearch::printSongs(int numToPrint)
{
    assert(numToPrint < songCount);

    for (int n = 0; n < songCount; n++) {
	cout << songInfo[n].artist << endl;
	cout << songInfo[n].title  << endl;
	for (int i = 0; i < 10; i++)
	    cout << songInfo[n].lyrics[i] << " ";
	cout << endl << endl;
    }
}

//processWord()
//purp: remove non-alphabetic characters and convert
//      string to lowercase
//args: string to process
//rets: processed string
string SongSearch::processWord(string word)
{
        ostringstream ss;
        for (size_t i=0;i<word.length();i++) {
                if (isalnum(word[i])){
                        ss << (char)(tolower(word[i]));
                }
        }
        return ss.str();
}

//insertWord()
//purp: insert words of a song into trie
//args: lyrics array, pointer to song info, num of words in lyrics
//note: calculates frequency of that word
void SongSearch::insertWord(string l[], songByArtist *info, int num)
{
    vector<string> toInsert;
    vector<int>    freq;
    size_t         numToInsert = 0;
    bool           alreadyInList = false;
    string         word = "";
    //calculate frequency of every word
    for (int n = 0; n < num; n++) {
	alreadyInList = false;
	word = processWord(l[n]);
	for (size_t i = 0; i < numToInsert; i++) {
	    if (word == toInsert[i]) {
		alreadyInList = true;
		freq[i] = (freq[i] + 1);
		break;
	    }
	}
	if (!alreadyInList) {
	    word = processWord(word);
	    toInsert.push_back(word);
	    freq.push_back(1);
	    numToInsert++;
	}
    }
    //insert words into trie with freq
    for (size_t n = 0; n < numToInsert; n++)
	wordList->insertWord(toInsert[n], info, freq[n]);
}

//print()
//purp: print song info for given word
//args: word to find in trie
void SongSearch::print(string word)
{
    wordList->printWord(processWord(word));
}

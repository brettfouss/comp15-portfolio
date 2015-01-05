/*
 * SongSearch.h - Header File
 * Author: Brett Fouss
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Public/Private functions and variables 
 * of SongSearch class declared here.
 *
 */

#ifndef SONGSEARCH_H
#define SONGSEARCH_H

#include <iostream>
#include "Trie.h"

using namespace std;

class SongSearch {

public:
    //constructor and destructor
    SongSearch();
   //~SongSearch();

    //operate on trie
    string processWord(string word);
    void   insertWord(string lyrics[], songByArtist *songInfo, int numWords);
    void   print(string word);

    //operate on songByArtist dynamic array
    void read_lyrics  (const char*  filename, bool show_progress );
    songByArtist* insertSong   (string title, string artist, 
				  	string *lyrics, int num);
    void printSongs   (int numToPrint);

private:
    //count and capacity of dynamic array of songs
    int songCount;
    int songCapacity;

    //expand function for lyric storage
    string* expand(string* lyrics, int num, int curr_capacity);

    //dynamic array of songs/artists/lyrics
    songByArtist *songInfo;

    //trie containing words for quick searching
    Trie *wordList;
};

#endif /* defined SONGSEARCH_H */

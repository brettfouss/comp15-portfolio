/*
 * main.cpp
 * Author: Brett Fouss - Copied from Prof. Chris Gregg's Code
 * 4/29/14
 * Comp 15 - HW 5
 *
 * Main of Song Search application defined here.
 *
 */

#include <iostream>
#include <fstream>
#include "SongSearch.h"

using namespace std;

//main()
//purp: create instance of song search, send file to
//      read_lyrics function through command line
//      user will cin search values, terminated by
//      <BREAK>
//args: num of command line args, filename to read in
int main(int argc, char *argv[])
{
    SongSearch songsearch;
    
    if (argc == 2) {

	songsearch.read_lyrics(argv[1], false);

	string input;

	while (input != "<BREAK>") {
	    cin >> input;
	    if (input == "<BREAK>") break;
	    songsearch.print(input);
	    cout << "<END-OF-REPORT>\n";
	}
    } else
	cout << "Usage: songsearch database.txt\n";
    return 0;
}

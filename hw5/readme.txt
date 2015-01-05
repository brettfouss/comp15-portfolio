Song Search
Brett Fouss
4/29/14
Comp 15

Purpose: Build a program that allows the user to search a database of
	 songs to locate instances of words within song lyrics. 

List of Files:

- main.cpp       - create instance of songsearch class
		   specify read-in file, read in user input
- SongSearch.h   - header file for songsearch class
- SongSearch.cpp - implementation file for songsearch class
- Trie.h         - header file for trie class
- Trie.cpp       - implementation file for trie class
- Node.h         - header file for node class
- Node.cpp       - implementation file for node class

Compiling:
To compile, type: "make"

Manual Compiling: " g++ -o main.o -c main.cpp "
                  " g++ -o SongSearch.o -c SongSearch.cpp "
                  " g++ -o Trie.o -c Trie.cpp "
		  " g++ -o Node.o Node.cpp " 
                  " g++ -o songsearch SongSearch.o Trie.o 
				    main.o Node.o "

Note: Song Search class may access Trie public functions, which
      in turn operate on nodes.

Data Structure:

Trie
Tries are both compact and allow for fast insertion and lookup.Tries
are made of nodes, which each contain a letter and a vector of all
of that node's children. Each string contained within the trie is
broken up by character - each character is stored within a node, and
the characters after that are stored subsequently as children.

Dynamic Array
Song Info is contained within dynamic array. While this
data structure has similar properties and restrictions as an array,
it has the added capabilities of expanding itself as it reaches
memory capacity. In this case, if capacity is reached, the program
will create a new array on the heap that is double the size. The
data is copied over and the pointer to the array is re-assigned.

Algorithm (copied, modified slightly from design doc):

Storage Process

1. Main will pass in a data text file to a read-in function.
2. Lyrics will be packaged as an array along with artist and song name.
3. Songs (including artist name and lyrics) are stored in a dynamic array
   for reference. 
4. Each word will then be processed.
	a. Capitilized letters will be converted to lowercase.
	b. Special characters and punctuation will be removed.
	c. Frequency of each word (within each song) are calculated 
           and packaged.
5. The word/song will then be then added to a trie.
6. If word is not yet in trie, word and info are added to the trie.
   If word is already in the trie, word and info are only added if the
   frequency of that word in the song is greater than the pre-existing 
   minimum OR if there are less than 10 songs stored along with that word.
	a. address of song info is stored as a member variable of that heap node
	b. frequency of that word in that song is stored in node as well

Search Process

1. Word to find in trie is read in from cin
2. Word is processed, then passed to function in trie
3. Trie follows corresponding children from root to locate word.
4. If word exists, data is sorted based on frequency.
5. Every instance of word in lyrics are printed along with
   title of song, artist, and context of that word. 




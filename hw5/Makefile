#
# Makefile for SongSearch, Assignment 5
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

songsearch: Node.cpp Node.h Trie.cpp Trie.h SongSearch.cpp SongSearch.h main.cpp
	${CXX} ${FLAGS} -o songsearch SongSearch.cpp main.cpp Trie.cpp Node.cpp
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw5_design songsearch_design.txt

provide:
	provide comp15 hw5 <all your files go here>



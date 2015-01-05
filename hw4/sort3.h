/*
 * sort3.h
 * Author: Brett Fouss
 *
 * Header file of MERGESORT Algorithm
 *
 * Private/Public functions and variables 
 * MergeSort class declared here.
 *
 * April 6th, 2014
 * Comp 15
 *
 */

#ifndef SORT3_H
#define SORT3_H

#include <iostream>

struct arrayWithLength {
  int length;
  int *arr;
};

class MergeSort {

 public:

  //constructor
  MergeSort();

  //read in list from stdin
  //keep track of array size
  void readList();

  //sort array using merge sort algorithm
  void sort();

  //print sorted list
  void printArray();

 private:

  //recursive mergeSort algorithm, recursively splits
  //and sorts array
  void mergeSort (int start, int end, int *newArray);

  //merges two portions of array into one sorted list
  void sorter    (int start, int end, int *newArray);

  arrayWithLength sortArray;

};

#endif /* defined SORT3_H */

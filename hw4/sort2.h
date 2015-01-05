/*
 * sort2.h
 * Author: Brett Fouss
 *
 * Header file of QUICKSORT Algorithm
 *
 * Private/Public functions and variables 
 * quickSort class declared here.
 *
 * April 6th, 2014
 * Comp 15
 *
 */

#ifndef SORT2_H
#define SORT2_H

#include <iostream>

struct arrayWithLength {
  int length;
  int *arr;
};

class QuickSort {

 public:
  QuickSort(); // constructor

  //read in array from stdin
  void readList();

  //sort array using quick sort
  void sort();

  //print sorted list
  void printArray();

 private:

  //sorted array with length
  arrayWithLength sortArray;

  //recursive quickSort function for given range
  void quickSort(int left, int right);

  //partition function, returns pivot value
  //that splits array for next recursive call
  int partition(int left, int right);

};

#endif /* defined SORT2_H */

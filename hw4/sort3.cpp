/*
 * sort3.cpp
 * Author: Brett Fouss
 *
 * Implementation file of MERGESORT Algorithm
 *
 * Private/Public functions of MergeSort class 
 * defined here.
 *
 * April 6th, 2014
 * Comp 15
 *
 */

#include <iostream>
#include "sort3.h"

using namespace std;

//constructor
//effs: initializes private data
MergeSort::MergeSort()
{
  sortArray.length = 0;
  sortArray.arr = NULL;
}

//readList function
//purp: reads in values, keeps track of # of elements
//      arrayWithLength's array 
//note: copied directly from SelectionSort.cpp's readList
void MergeSort::readList() {
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];

        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity)
{
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

//sort function
//purp: public function to sort an entire array
//      from index 0 to (length-1)
void MergeSort::sort()
{
  int *newArray = new int[sortArray.length];
  mergeSort(0, (sortArray.length-1), newArray);
  delete [] newArray;
}

//mergeSort function
//purp: recursively sort an array by merging ordered portions 
//      of the array together
//args: range of indexes to sort, pointer to temporary sorted array
void MergeSort::mergeSort(int start, int end, int *newArray)
{
  if (start < end) { //base case: array has 1 or 0 elements
  int mid = ((end+start)/2);
  //top => down implementation
  //array is FIRST split completely into single elements
  //then merged together in order  
  mergeSort(start, mid, newArray); //split
  mergeSort(mid+1, end, newArray); //split
  sorter   (start, end, newArray); //sort
  }
}

//sorter function
//purp: sort/merge two portions of sortArray into new array
//args: range of indexes to sort, temp array to sort into
void MergeSort::sorter(int start, int end, int *newArray)
{
  //divide into two ranges to operate on
  //abstract representation of two seperate lists
  int mid      = ((end+start)/2);
  int arrayOne = start;
  int arrayTwo = (mid+1);

  //index of newArray to insert into
  int n        = start;

  //this loop will sort the lists into a new lists WHILE
  //there are elements in BOTH array portion one AND two
  while ((arrayOne <= mid) && (arrayTwo <= end)) {
    if (sortArray.arr[arrayOne] < sortArray.arr[arrayTwo]) {
        newArray[n] = sortArray.arr[arrayOne];
        arrayOne++;
    } else {
      newArray[n] = sortArray.arr[arrayTwo];
      arrayTwo++;
    }
    n++; //move on to next space in new array
  }

  //either array portion one OR array portion two has
  //been completely moved into the new array.
  //copy rest of OTHER array portion into new array
  if (arrayOne > mid) {
    while (arrayTwo <= end) {
      newArray[n++] = sortArray.arr[arrayTwo];
      arrayTwo++; //next element to copy
    } 
  } else {
	while (arrayOne <= mid) {
	  newArray[n++] = sortArray.arr[arrayOne];
	  arrayOne++; //next element to copy
	}
    }
  //recopy into original array
  for (int n = start; n <= end; n++)
    sortArray.arr[n] = newArray[n];
}

//printArray
//purp: print sorted array
void MergeSort::printArray()
{
  for (int n = 0; n < sortArray.length; n++)
    cout << sortArray.arr[n] << endl;
}

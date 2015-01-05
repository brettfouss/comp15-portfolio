/*
 * sort2.cpp
 * Author: Brett Fouss
 *
 * Implementation file of QUICKSORT Algorithm
 *
 * Private/Public functions of QuickSort class 
 * defined here.
 *
 * April 6th, 2014
 * Comp 15
 *
 */

#include <iostream>
#include "sort2.h"

using namespace std;

//constructor
//effs: initializes private data
QuickSort::QuickSort()
{
  sortArray.length = 0;
  sortArray.arr = NULL;
}

//readList function
//purp: reads in list into dynamic array of arrayWithLength.
//      keeps track of array length. 
//note: copied directly from SelectionSort.cpp's readList
void QuickSort::readList() {
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
//purp: sort the entire list by passing 0 and
//      length-1 into recursive quicksort function
void QuickSort::sort()
{
  //sort the entire array
  int firstValue = 0;
  int lastValue = (sortArray.length-1);
  quickSort(firstValue, lastValue);
}

//quickSort function
//purp: recursively sort any given portion of the array
//args: range of indexes to sort
void QuickSort::quickSort(int left, int right)
{
  //base case: list has 1 number or less
  if (left < right) { 
    //partition function will return the index of
    //the pivot value after the array has been partitioned
    //around that value
    int split = partition(left, right);
    quickSort(left, split); //sort of left half includes split
    quickSort((split+1), right);
  } else /* left >= right */ return;
}

//partition function
//purp: partition portion array around a pivot value
//args: range of indexes to operate on
//rets: 
int QuickSort::partition(int left, int right)
{
  int pivot = left; // pivot is leftmost value in this algorithm

  while (left < right) { 
    //find greater value from left to switch
    while ((sortArray.arr[left] < sortArray.arr[pivot]) 
	    && (left < (sortArray.length-1))) 
      left++;
    //find lesser value from right to switch
    while ((sortArray.arr[right] > sortArray.arr[pivot]) && (right >= 0))
      right--;
    //this portion of code deals with equal values
    //if both left and right are equivalent to pivot,
    //there is NO NEED to switch
    if (sortArray.arr[left] == sortArray.arr[right]) {
      if (left < right) {
	//move past equivalent left OR right value
	//UNLESS both left and right have reached the pivot
	if (left != pivot) { left++; 
	  continue; // do not switch
	} else if (right != pivot) { right--; 
	  continue; // do not switch
	}
      } else break;
    }
    //switch left/right
    int temp = sortArray.arr[left];
    sortArray.arr[left] = sortArray.arr[right];
    sortArray.arr[right] = temp;
  }
  //switch right with pivot, return pivot index
  int temp = sortArray.arr[right];
  sortArray.arr[right] = sortArray.arr[pivot];
  sortArray.arr[pivot] = temp;
  return pivot;
}

//printArray function
//purp: print out the sorted array
void QuickSort::printArray()
{
  for (int n = 0; n < sortArray.length; n++)
    cout << sortArray.arr[n] << endl;
}

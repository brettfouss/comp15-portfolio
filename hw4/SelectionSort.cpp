//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm

#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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

//sorts the array using a selection sort
//algorithm: 
// - finds min of list
// - switches first element and min element
// - repeats until list is completely sorted
void SelectionSort::sort() {

  int toSort  = 0; // index of min to be moved to front
  int atIndex = 0; // index of item to be switched
  int min;

  while (toSort < sortArray.length) {
    //find minimum element of list to be sorted
    //starts at beginning of unsorted list
    min = sortArray.arr[toSort];
    for (int n = toSort; n < sortArray.length; n++) {
      if (sortArray.arr[n] < min) {
	min = sortArray.arr[n];
	atIndex = n;
      }
    }
    //perform switch
    int temp = sortArray.arr[toSort];
    sortArray.arr[toSort] = sortArray.arr[atIndex];
    sortArray.arr[atIndex] = temp;

    toSort++;        
    atIndex = toSort; // reset atIndex to search from
                      // beginning of unsorted list
  }
}

void SelectionSort::printArray(){
  for (int n = 0; n < sortArray.length; n++)
    cout << sortArray.arr[n] << endl;
}

/*
 * Main2.cpp
 * Author: Brett Fouss
 * (copied from original main1.cpp file)
 *
 * Implementation of QUICKSORT Algorithm
 *
 * April 6th, 2014
 * Comp 15
 *
 */


#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
  QuickSort sorter;

  sorter.readList();   //reads in input from stdin
  sorter.sort();       //sorts data (public function)
  cout << "Output:\n";
  sorter.printArray(); //prints array from class

}

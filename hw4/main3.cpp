/*
 * main3.cpp
 * Author: Brett Fouss
 * (copied from original main1.cpp file)
 *
 * Implementation of MERGESORT Algorithm
 *
 * April 6th, 2014
 * Comp 15
 *
 */

#include <iostream>
#include "sort3.h"

using namespace std;

int main()
{
  MergeSort sorter;

  sorter.readList();   //read in list from stdin
  sorter.sort();       //sort list using merge sort
  cout << "Output:\n";
  sorter.printArray(); //print array
}

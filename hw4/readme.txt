Three Sorts
Selection Sort, QuickSort, and Merge Sort
Brett Fouss
4/5/14
Comp 15

Purpose: Practice 3 sorting algorithms, compare time and space
	 complexity.

List of Files:

Selection Sort
 - main1.cpp		- creates instance of selection sorter
 - SelectionSort.h      - header file for selection sorter class
 - SelectionSort.cpp    - implementation file for selection sorter
 - private variables:   arrayWithLength sortArray (*array + array length)

QuickSort
 - main2.cpp		- creates instance of quicksorter
 - QuickSort.h		- header file for quicksorter class
 - QuickSort.cpp        - implementation file for quicksorter class
 - private variables:   arrayWithLength sortarray (*array + array length)
 - private functions:   quickSort - recursively sorts a partition
   	   		partition - partitions array into x < pivot < y,
				    returns index of pivot

Merge Sort
 - main3.cpp		- creates instance of merge sorter
 - mergeSort.h  	- header file for merge sorter class
 - mergeSort.cpp        - implementation file for merge sorter class
 - private variables:   arrayWithLength sortArray (*array + array length)
 - private functions:   mergeSort - recursively splits, then sorts array
   	   		sorter	  - merges sub-arrays into sorted array

Note: All main files are identical. Implementation of all three sorts
      have been designed to work with identical main files. 

Algorithms:

- Selection Sort -

Selection sort is fairly simple comparison sort algorithm. An array is 
divided into three sections: sorted, to be sorted, and unsorted. The
sort builds the sorted section of the array by finding the minimum value
of the array and switching this value with the first element of the
unsorted array (to be sorted element). This process continues until the
entire array is sorted.

Worst-case time complexity: O(n^2)
Best -case time complexity: O(n^2)

One of the downsides of the selection sort is that the function must search
through the entire array once for every unit of input. Therefore, the array
may prove inefficient for large data inputs.

- Quicksort -

Quicksort, a recursive comparison algorithm, uses a partition function to
sort data. With each recursive call of quicksort, an array is divided into
three sections: values less than a determined pivot value, the pivot value
itself, and values greater than the pivot value. By recursively partitioning
the array (until the size of the array is equal to or less than one), the 
array is naturally sorted. To correctly partition the array, every partition
function places the pivot in the middle of the array and returns this value.
The quicksort function is called recursively based on the partition index.

Worst-case time complexity: O(n^2)
Best-case time complexity: O(nlogn)

The time complexity of quickSort depends on the selection of a pivot value.
If the pivot value is the median of the unsorted list at each iteration, the
speed of the program will approach the best-case O(nlogn). The more even each
seperate partition (left-mid/mid-right) is with every recursive call, the less
recursive calls the algorithm will have to make throughout the sort, and therefore
the less comparisons necessary to sort.

The worst case occurs IF at every iteration, the array is partitioned into 
sub-arrays of size 1 and (n-1). In this case, the sorting algorithm behaves
virtually like a simple insertion sort, and will have a complexity of O(n^2)
(Reference: http://stackoverflow.com/questions/11963986/quick-sort-time-complexity)

According to wikipedia, given the random nature of the selected pivot at each
iteration, quickSort usually only performs 39% worse than its best case speed.
This assumes that the input data is a random permutation.
(Reference: http://en.wikipedia.org/wiki/Quicksort)

My quickSort algorithm is in-place, with a space complexity of O(n).
While in an abstract sense, the array is indeed split into "sub-arrays", the
algorithm is in fact only recursively dividing a single array by splitting
index values. 

- Merge Sort -

Merge sort is an incredibly simple algorithm with a surprisingly (more) complex
implementation. I used a "top-down" implementation of merge sort. After recursively
splitting the array into sub-arrays of size 1 (this serves as a base case for the
recursive function), the algorithm pieces the array back together by merging the
sub-arrays into a single sorted array. A "sorter" function will (in an abstract 
sense) take in two sub-arrays, which are presumably pre-sorted, and compare/insert
the first elements until one is empty - after which the rest of the non-empty list's
elements will be copied into the new array. Before the sorter function returns,
it copies data from the new array into the original array (I ran into a lot of
problems because I overlooked this last step, luckily online resources were able
to help me in the end. 

Worst-case time complexity: O(nlogn)
Best-case time complexity: O(nlogn)

Merge sort is an incredibly efficient algorithm - in my tests, it proved to be
surprisingly much faster than quickSort. The time complexity is not difficult
to comprehend. The algorithm breaks down n elements into n sub-arrays, and through
recursion works it's way up towards a single sorted array. However, because the
two sub-arrays that are being merged are PRE-SORTED, the algorithm approaches a
time complexity of O(nlogn). The algorithm is dividing the problem into smaller
sub-problems with every recursive call, simplifying the problem at each level.
The worst case and best case scenarios are identical as (for example) the 
algorithm will still recursively split and re-sort an already-sorted list - 
giving the same time complexity as a completely random list. 

Unfortunately, my implementation of a merge sort uses a temporary "newArray"
to sort the data, giving it a space complexity of O(2n), however we describe
the complexity simply as O(n).

(Source: http://www.sorting-algorithms.com/merge-sort)

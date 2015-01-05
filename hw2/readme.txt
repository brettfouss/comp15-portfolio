Calendar
Ordered Dynamic Array and Ordered Linked List
Brett Fouss
2/11/14
Comp 15

Purpose: Keep track of a calendar of days that contain ordered
         lists of events. Each event includes start time, end time,
         and a short description of the event.

List of Files:
 - main.cpp	       - Main file containing simple/advanced input tests 
 - event.h             - Header file containing declaration of Event class.
 - event.cpp           - Implementation file of Event class containing
                         definition of private/public members of an Event.
 - dayDynamicArray.h   - Header file containing declaration of Day class.
                         Day is an ordered dynamic array of Events.
 - dayDynamicArray.cpp - Implementation file of Day class (dynamic array
                         version). 
 - dayLinkedList.h     - Header file containing another declaration of Day
                         class. This one uses a singly-linked list instead
                         of a dynamic array, however is also ordered and
                         can be used along with the same main file. 
 - dayLinkedList.cpp   - Implementation file of Day class (linked list
                         version).

Compiling:
To compile both files, type:    " make "
To compile dynamic array, type: " make orderedDynamicArray "
To compile linked list, type:   " make orderedLinkedList "

Manual compiling: " g++ -o main.o -c main.cpp "
                  " g++ -o event.o -c event.cpp "
                  " g++ -o dayDynamicArray.o -c dayDynamicArray.cpp "
                  " g++ -o orderedDynamicArray dayDynamicArray.o event.o main.o "
                  FOR DYNAMIC ARRAY VERSION, OR

                  " g++ -o main.o -c main.cpp "
                  " g++ -o event.o -c event.cpp "
                  " g++ -o dayLinkedList.o -c dayLinkedList.cpp "
                  " g++ -o orderedLinkedList dayLinkedList.o event.o main.o "

Data Structure: 

Dynamic Array
The first version of this program uses a dynamic array. While this
data structure has similar properties and restrictions as an array,
it has the added capabilities of expanding itself as it reaches
memory capacity. In this case, if capacity is reached, the program
will create a new array on the heap that is double the size. The
data is copied over and the pointer to the array is re-assigned. 

Linked List
Each node of a list contains an event along with a pointer to 
the next node. As events are added to each day in order, the
program reconnects the nodes so that each pointer connects to
the correct node in pointer. 

Algorithm:

Dynamic Array
1. Event is created and passed into the Day. 
2. Array grows as events are added in order. 
3. If event count reaches capacity, capacity is doubled
   and new array is created. Data is copied. 
4. Client program may print array as needed. Couts from
   event class.

Linked List
1. Event is created and passed into day.
2. If event is first event, event list pointer gets that event.
3. If event is second event (start time after first event), the 
   first node's pointer will point to that event. 
4. If event is the last event (if end of list is reached), inserts
   after last event.
5. Otherwise, program will insert event before the correct event
   in order by comparing the events start time to the start time
   of the event after the current event node. This is so that the
   singly linked list retains BOTH the current event node AND
   the next event node at once, otherwise it would be impossible
   to insert between the two. 
6. Client program may print list as needed. Couts from event class.







Calendar
Ordered Dynamic Array and Ordered Linked List
Brett Fouss
2/11/14
Comp 15

Purpose: Keep track of a calendar of multiple days that contain
	 ordered events. Each event includes start time, end time
	 and a short description. Days are kept in order.

	 This program has the added functionality of being able to export
	 to Google calendar and other calendar applications by exporting
	 CSV strings. 

List of Files:
 - main.cpp	       - contains various tester functions
 - event.h 	       - Header file containing declaration of Event class/
 - event.cpp           - Implementation file of Event class containing
			 definition of private/public members of an Event.
 - dayDynamicArray.h   - Header file containing declaration of Day class.
			 For this version of Calendar, a dynamic array
			 implementation is used. 
 - dayDynamicArray.cpp - Implementation file of Day class, contains various
			 functions to schedule/cancel events, plus a function
			 that will look through a single day to find a free
			 block of time given that there is a conflict. 
 - Calendar.h	       - Header file containing declaration of Calendar class.
 - Calendar.cpp	       - Implementation file of Calendar class, containing
			 functions that keep days in order. This file also
			 contains functions that convert time from military
			 to standard time and dates into the correct formatting
			 (mm/dd/yyyy). Calendar.cpp can either output the data
			 regularly or as CSV strings. 

Compiling:
To compile, type: "make"

Manual Compiling: " g++ -o main.o -c main.cpp "
                  " g++ -o event.o -c event.cpp "
                  " g++ -o dayDynamicArray.o -c dayDynamicArray.cpp "
		  " g++ -o calendar.o Calendar.cpp " 
                  " g++ -o calendar dayDynamicArray.o event.o 
				    main.o calendar.o "

Data Structure: 

Dynamic Array
The first version of this program uses a dynamic array. While this
data structure has similar properties and restrictions as an array,
it has the added capabilities of expanding itself as it reaches
memory capacity. In this case, if capacity is reached, the program
will create a new array on the heap that is double the size. The
data is copied over and the pointer to the array is re-assigned.

Algoithm:

Each calendar can create any amount of days, which are stored in a
dynamic array. Subsequently, multiple events can be scheduled on
each day. Events are also stored in a dynamic array. 

A day is created through one of multiple constructors and then
sorted into the array, which is ordered. Main keeps an array of
pointers to the address of each day for access. The implementation
of a calendar is contained within Calendar.cpp. Through each
calendar object, days may be printed, compared, and exported
in the CSV format. The calendar also provides a method through
which events can be scheduled into days, however main MUST use
the calendar implementation to schedule events. 

Events have similar functionality to days. When an event is 
scheduled, it is placed into an ordered dynamic array of 
events for each day. If the event conflicts with another event
on that day, the program will either find a free block of time
later that day, or report that the event cannot be scheduled. 
Like days, events can be compared, printed, and cancelled. 

Algorithm for various functions:

nextFreeBlock:

Next free block is a fairly simple function. It either returns the
start time of a free block of time, OR the integer -1 if there an
event. First, nextFreeBlock finds if the new event conflicts with
any event in the array already. If so, then the function will reset
the new event's start time to the conflicting event's end time. It
will also adjust the new event's end time accordingly. The adjusted
event will be subsequently compared to the next event in the list.
This process will be repeated until the last event, and after that
the function will see if the new event fits in between the last 
event and the end of the day.

conflictsWith:

An event conflicts with another event if it meets the following conditions:

	1. The end time of event a is GREATER than event b's start time.
					AND
	2. Event b's start time is greater than event a's start time.

This logic applies both ways for events a and b. 


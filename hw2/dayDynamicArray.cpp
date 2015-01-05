//
//  day.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;

Day::Day(){ // constructor
    eventCount    = 0;
    eventCapacity = INIT_CAPACITY;
    eventList     = new Event[INIT_CAPACITY];
}

void Day::scheduleEvent() { // add default event for a full Day
        scheduleEvent(0,2359,"");
}

//adds events to days in order
void Day::scheduleEvent(int startTime, int endTime, string description){

    Event newEvent(startTime, endTime, description);

    if ((eventCount+1) == eventCapacity)
	expand(); // will expand array at capacity + 1 
                  // + 1 prevents segfaults if data needs
                  // to be shifted over
    if (eventCount == 0) {
	eventList[0] = newEvent;
    } else {
	if (eventList[eventCount-1].amIBefore(newEvent))
	    eventList[eventCount] = newEvent;
	else
	    for (int n = 0; n < eventCount; n++) {
		if (newEvent.amIBefore(eventList[n])) {
		    shift_from(n); // will move rest of array over 1
		    eventList[n] = newEvent; // to the right so that
		    break;         // there is space for new data 
		}
	    }
    }
    eventCount++;
}

// moves over every data point to the next spot
// in the array from n up to eventcount + 1
void Day::shift_from(int n)
{
    int i = (eventCount + 1);

    while (i > n) {
	eventList[i] = eventList[i-1];
	i--;
    }
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent){

    for(int n = 0; n < eventCount; n++) {
	if (eventList[n].isSameEventAs(anEvent)) {
	    for(int i = n; i < eventCount; i++) {
		eventList[i] = eventList[i+1];
	    }
	    eventCount--;
	    break;
	}
    }
}

//prints every event (couts from event)
void Day::printDay() {
    for (int n = 0; n < eventCount; n++) {
	eventList[n].printEvent();
    }
}

string Day::exportDay(){
        string csvString = "";
        for (int index=0;index < eventCount; index++) {
                csvString+= eventList[index].eventCSV() + "\n";
        }
        return csvString;
}

// creates new array twice the size, reassigns pointer
void Day::expand() {

    int newCapacity = (2*eventCapacity);

    Event *temp = new Event[newCapacity];

    for (int n = 0; n < eventCount; n++)
	temp[n] = eventList[n]; // copy data to new array

    eventList = temp;
    delete [] temp;

    eventCapacity = newCapacity; // updates capacity

}

Day::~Day(){
        delete [] eventList;
}

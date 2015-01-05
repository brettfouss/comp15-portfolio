//
//  DayLinkedList.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "dayLinkedList.h"
#include <cassert>

Day::Day(){ // constructor
    eventList = NULL;
    eventCount = 0;
}

void Day::scheduleEvent() { // add default Event for a full Day
        scheduleEvent(0,2359,"");
}

// add an event to each day linked list IN ORDER
void Day::scheduleEvent(int startTime, int endTime, string description){

    EventNode *newEvent = new EventNode;
    newEvent-> theEvent = Event(startTime, endTime, description);
    newEvent-> next = NULL;

    if (eventList == NULL)
	eventList = newEvent;
    else {
	EventNode *temp = eventList;
	while (temp != NULL) {
	    if (temp->next == NULL) {
		if (newEvent->theEvent.amIBefore(temp->theEvent)) {
		    eventList = newEvent;
		    newEvent->next = temp;
		    break;
		} else {
		    temp->next = newEvent;
		    break;
		}
	    } else if (newEvent->theEvent.amIBefore(temp->theEvent)) {
		eventList = newEvent;
		newEvent->next = temp;
		break;
	    } else if(newEvent->theEvent.amIBefore(temp->next->theEvent)) {
		newEvent->next = temp->next;
		temp->next = newEvent;
		break;
	    } else
		temp = temp->next;
	}
    }
    eventCount++;
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

// cancels event that is the same as event passed in
void Day::cancelEvent(Event anEvent){

    EventNode *temp = eventList->next;
    EventNode *prev = eventList;

    if (prev->theEvent.isSameEventAs(anEvent)) {
	eventList = temp;
	eventCount--;
	return;
    } else
	while (temp != NULL) {
	    if(temp->theEvent.isSameEventAs(anEvent)) {
		prev->next = temp->next;
		eventCount--;
		break;
	    }
	    temp = temp->next;
	    prev = prev->next;
	}
}

void Day::printDay() {
    EventNode *temp = eventList;

    while (temp != NULL) {
	temp->theEvent.printEvent();
	temp = temp->next;
    }
}

string Day::exportDay(){
        string csvString = "";
        EventNode *tempEventNode = eventList;
        while (tempEventNode != NULL) {
                csvString+= tempEventNode->theEvent.eventCSV() + "\n";
                tempEventNode = tempEventNode->next;
        }
        return csvString;
}
Day::~Day() {
        while (eventList != NULL) {
                EventNode *tempNextNode = eventList->next;
                delete eventList;
                eventList = tempNextNode;
        }
}

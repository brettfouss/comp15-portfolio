//
//  event.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Event::Event() { // constructor

    startTime   = 0;
    endTime     = 2359;
    description = "";

}

Event::Event(int startT, int endT, string desc) {

    startTime   = startT;
    endTime     = endT;
    description = desc;

}

int Event::getStartTime() {
    return startTime;
}

int Event::getEndTime() {
    return endTime;
}

std::string Event::getDescription() {
    return description;
}

void Event::setStartTime(int startT) {
    startTime = startT;
}

void Event::setEndTime(int endT) {
    endTime = endT;
}

void Event::setDescription(string str) {
    description = str;
}

bool Event::amIBefore(Event otherEvent) {
    return (startTime < otherEvent.getStartTime());
}

bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}

void Event::printEvent(){

    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Description: " << description << "\n\n";

}

string Event::eventCSV() {
        ostringstream startTimeStr,endTimeStr;
        startTimeStr << startTime;
        endTimeStr << endTime;
        
        string EventString = startTimeStr.str()+","+
                                endTimeStr.str()+","+
                                description;
        return EventString;
        
}

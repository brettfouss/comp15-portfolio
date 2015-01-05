//
// event.cpp
//
// Last modified:
// Brett Fouss
// 3/5/2014
//
// Implementation file of event class.
// Contains:
// Multiple constructors 
// Getters/setters
// Comparison functions (amIBefore, isSameEventAs,
//                       conflictsWith)
// Method to convert from military time to 
// standard 12 hour time. 
//

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Event::Event() { // constructor
        startTime = 0;
        endTime = 2359;
        description = "";        
}

Event::Event(int startT, int endT, string desc) {
        startTime = startT;
        endTime = endT;
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

// true if this event is before event
// passed in as argument
bool Event::amIBefore(Event otherEvent) {
        if (startTime < otherEvent.getStartTime()) {
                return true;
        }
        return false;
}

// true if this event is the same as
// event passed in as arguement
bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}

// conflictsWith returns true if this event overlaps with another event
// during the day
// events can "touch" but not overlap. I.e., one event can end
// at the same time the next event begins and this is not an overlap
bool Event::conflictsWith(Event anEvent) {
        // this event overlaps with another event if:
        // (easy to look this up on StackOverflow if you can't figure it out!)
    if ((endTime > anEvent.getStartTime()) && (startTime < anEvent.getEndTime()))
	return true;
    if ((anEvent.getEndTime() > startTime) && (anEvent.getStartTime() < endTime))
	return true;
    return false;
					     
}

//prints the event using 24 hour time conversions
void Event::printEvent(){
        cout << "Start Time: " << convert24HourTime(startTime) << "\n";
        cout << "End Time: " << convert24HourTime(endTime) << "\n";
        cout << "Description: " << description << "\n\n";
}

string Event::eventCSV() {
        string EventString = convert24HourTime(startTime) + "," +
                                convert24HourTime(endTime) + "," +
                                description;
        return EventString;
        
}

// converts an integer in 24-hour time (e.g., 1330) to
// a string that is in 12-hour time with AM or PM, as follows:
// The int 1330 becomes
// the string "1:30 PM"
string Event::convert24HourTime(int time24){
        string fullTime, meridiem; // meridiem is used for "AM" or "PM"
        
        // ostringstream is used to convert an int to a string
        // use as follows, to read hourNum into hour_oss:
        // hour_oss << hourNum
        //
        // To convert an osstringstream to a string,
        // use the .str() conversion:
        // hour_oss.str() will produce a string
        ostringstream hour_oss,minute_oss;
        
        int hourNum, minuteNum;
        
        // first determine whether we are in AM or PM

	if (time24 < 1200)
	    meridiem = "AM";
	else {
	    meridiem = "PM";
	    if (time24 >= 1300) 
		time24 = (time24 - 1200);
	}

	//integer division: moves last two digits
	//into decimal position, then rounded away
	hourNum = (time24/100);
	//get rid of first two digits
	minuteNum = (time24 -(hourNum*100));

	if (hourNum == 0) //twelve o'clock AM
	    hour_oss << 12;
	else
	    hour_oss   << hourNum;

	if (minuteNum >= 10) //two digit minutes
	    minute_oss << minuteNum;
	else                 //one digits minutes
	    minute_oss << 0 << minuteNum;
        
        fullTime = hour_oss.str() + ":" + minute_oss.str() + " " + meridiem;
        return fullTime;
}

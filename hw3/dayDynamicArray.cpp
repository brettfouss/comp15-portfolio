//
//  dayDynamicArray.cpp
//
// Last modified:
// Brett Fouss
// 3/5/2014
// 
// Implementation file of dynamic array of days. 
// Events may be scheduled or cancelled on each day, 
// as well as printed or exported as in CSV format. 
//

#include "dayDynamicArray.h"
#include <cassert>
#include <string>
#include <sstream>

const int Day::INIT_CAPACITY;

Day::Day(){ // constructor
        eventList = NULL; // empty Day
        eventCount = 0;
        eventCapacity = 0;
        theDate.day = 1;
        theDate.month = 1;
        theDate.year = 2014;
}

Day::Day(date aDate) { // constructor
        eventList = NULL; // empty Day
        eventCount = 0;
        eventCapacity = 0;

	theDate.day   = aDate.day;
	theDate.month = aDate.month;
	theDate.year  = aDate.year;
}

void Day::scheduleEvent() { // add default event for a full Day
        scheduleEvent(0,2359,"");
}
void Day::scheduleEvent(int startTime, int endTime, string description){
        if (eventList == NULL) {
                eventList = new Event[INIT_CAPACITY];
                eventCapacity = INIT_CAPACITY;
        }
        else if (eventCapacity == eventCount){
                Event *tempList = new Event[eventCapacity * 2];
                for (int index=0;index<eventCount;index++){
                        tempList[index] = eventList[index];
                }
                delete [] eventList;
                eventList = tempList;
                eventCapacity = eventCapacity * 2;
        }
        
        // create a new event
        Event evt = Event(startTime,endTime,description);
        
        // find the location where we need to insert the event
        int index;
        for (index=0;index<eventCount;index++) {
                if (evt.amIBefore(eventList[index])) break;
        }
        // move the second to last item to the end, and then
        // continue down the list
        for (int moveIndex=eventCount;moveIndex > index; moveIndex--) {
                eventList[moveIndex] = eventList[moveIndex - 1];
        }
        eventList[index] = evt;
        eventCount++;
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

// attempts to schedule an Event at the earliest time available at or after the event starts
// This may schedule the Event at the original time, or later in the Day.
// Returns true if successful, false if the Day is full and the Event could not be scheduled
bool Day::scheduleEarliest(Event anEvent){
        int nextAvailableTime = nextFreeBlock(anEvent);
        if (nextAvailableTime == -1) {
                return false; // no time during the Day!
        }
        else {
	    int startT = nextAvailableTime;
	    int length = duration(anEvent.getStartTime(), anEvent.getEndTime());
	    int endT   = addTimes(startT, length);
	    string desc = anEvent.getDescription();
	    scheduleEvent(startT, endT, desc);
	    return true;
	}
}

void Day::cancelEvent(Event anEvent){
        // find the event
        int index;
        for (index = 0;index < eventCount; index++){
                if (eventList[index].isSameEventAs(anEvent)){
                        int delIndex;
                        for (delIndex=index;delIndex<eventCount-1;delIndex++){
                                eventList[delIndex] = eventList[delIndex+1];
                        }
                        eventCount--;
                        break; // found it, so no need to continue
                }
        }
}

// nextFreeBlock() returns a startTime integer for the next free block of time
// that will fit the Event.
// If the time is the same as the event's original startTime,
// then there wasn't a conflict.
// The function returns -1 if there was no suitable time for the event to end before 2359.
//
// algorithm: 
// if there is a conflict, set the start time to the conflicting
// events endtime and compare with the NEXT event.
// if the loop reaches the last event, it will compare with the
// end of the day. 
int Day::nextFreeBlock(Event anEvent) {

    int conflict = false;
    int nextEvent = 0;     // will not check events BEFORE the
    int newStartTime = -1; // proposed start time 
    int length = duration(anEvent.getStartTime(), anEvent.getEndTime());

    for (int n = 0; n < eventCount; n++) {
	if (anEvent.conflictsWith(eventList[n])) {
	    conflict = true; //
	    nextEvent = n;   //finds the first other event
	    break;           //that anEvent conflicts with
	}
    }

    if (conflict == true) {
	while (nextEvent < eventCount) {
	// reset start and end times
	    anEvent.setStartTime(eventList[nextEvent].getEndTime());
	    anEvent.setEndTime(addTimes(anEvent.getStartTime(),length));
	// change event that is being compared (next one)
	    nextEvent++;
	    if (nextEvent == eventCount)
		break; // prevents seg faults
	    if (!anEvent.conflictsWith(eventList[nextEvent])) {
		conflict = false;
		newStartTime = anEvent.getStartTime();
		break;
	    }
	}
	// IF no available time found so far
	// currently, start time is set to endTime of last event
	// will compare with the end of the day (2400)
	if ((nextEvent == eventCount) && (conflict == true)) {
	    if (anEvent.getEndTime() < 2400) {
		conflict = false;
		newStartTime = anEvent.getStartTime();
	    }
	}
    } else if (length < 2400) // if there is no conflict, then
			      // return unaltered start time
			      // given that length is under
			      // 24 hours.
	newStartTime = anEvent.getStartTime();

    return newStartTime;
}	    

// the printDay() function prints an entire Day, beginning with the Date on one line, in the
// following format:
// Date: 4/25/2014
void Day::printDay() {
    cout << "Date: ";
    cout << theDate.month << "/" << theDate.day << "/" << theDate.year << endl;
    for (int n = 0; n < eventCount; n++) {
	eventList[n].printEvent();
    }
}

string Day::exportDay(){
        // this function exports the day into 
        ostringstream day_oss;
        day_oss << theDate.month << "/" << theDate.day << "/" << theDate.year;
        string csvString = "";
        for (int index=0;index < eventCount; index++) {
                csvString+= day_oss.str() + "," + day_oss.str() + "," +
                eventList[index].eventCSV() + "\n";
        }
        return csvString;
}

bool Day::isBefore(Day anotherDay) {
        // check year
        if (theDate.year < anotherDay.theDate.year) return true;
        if (theDate.year > anotherDay.theDate.year) return false;
        
        // year is the same, check month
        if (theDate.month < anotherDay.theDate.month) return true;
        if (theDate.month > anotherDay.theDate.month) return false;
        
        // month is the same, check day
        if (theDate.day < anotherDay.theDate.day) return true;
        if (theDate.day > anotherDay.theDate.day) return false;
        return false;
}

int Day::duration(int time1,int time2){
        // calculate a duration between two times in the same day
        // time1 <= time2
        // returns a duration in 24-hour time
        int durationHours,durationMinutes;
        
        int time1Hours = time1 / 100;
        int time1Minutes = time1 - (time1Hours * 100);
        
        int time2Hours = time2 / 100;
        int time2Minutes = time2 - (time2Hours * 100);
        
        durationHours = time2Hours-time1Hours;
        durationMinutes = time2Minutes-time1Minutes;
        
        if (durationMinutes < 0) {
                durationHours--;
                durationMinutes+=60;
        }
        return durationHours * 100 + durationMinutes;
}

int Day::addTimes(int time1,int time2){
        // add two 24-hour times together
        int totalHours,totalMinutes;
        
        int time1Hours = time1 / 100;
        int time1Minutes = time1 - (time1Hours * 100);
        
        int time2Hours = time2 / 100;
        int time2Minutes = time2 - (time2Hours * 100);
        
        totalHours = time2Hours+time1Hours;
        totalMinutes = time2Minutes+time1Minutes;
        
        if (totalMinutes >=60) {
                totalHours++;
                totalMinutes-=60;
        }
        return totalHours * 100 + totalMinutes;
}

Day::~Day(){
        //if (eventList != NULL)
        //        delete [] eventList;
}

Day::Day(const Day &rightHandSide) {
        // first copy the values
        eventCapacity = rightHandSide.eventCapacity;
        eventCount = rightHandSide.eventCount;
        theDate = rightHandSide.theDate;
        eventList = NULL;
        
        if (eventCapacity==0) return;
        
        // create a new eventList and copy all events
        delete [] eventList;
        eventList = new Event[eventCapacity];
        
        for (int i=0;i<eventCount;i++) {
                eventList[i] = rightHandSide.eventList[i];
        }
}

Day &Day::operator=(const Day &rightHandSide){
        if (this != &rightHandSide) {
                // first copy the values
                eventCapacity = rightHandSide.eventCapacity;
                eventCount = rightHandSide.eventCount;
                theDate = rightHandSide.theDate;
                eventList = NULL;
                if (eventCapacity == 0) return *this;
                delete [] eventList;
                
                eventList = new Event[eventCapacity];
                
                for (int i=0;i<eventCount;i++) {
                        eventList[i] = rightHandSide.eventList[i];
                }
        }
        return *this;
        
}

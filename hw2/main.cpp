//
//  main.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#define simpleTest
//#define advancedTest

#include <iostream>
#include <string>
#include "dayDynamicArray.h"

int main()
{

Event breakfast = Event(900,1000,"Breakfast");
Event dinner = Event(1700,1800,"Dinner");
Event lunch = Event(1200,1300,"Lunch");
Event a = Event(1202, 1300,"a");
Event b = Event(100, 800, "b");
Event c = Event(2300, 2350, "c");

#ifdef simpleTest
        // simple test program
        // -----
        // /*
        Day *aDay = new Day();
        
        aDay->scheduleEvent(dinner);
        aDay->scheduleEvent(lunch);
        aDay->scheduleEvent(breakfast);

	aDay->cancelEvent(dinner);
	aDay->cancelEvent(breakfast);
	aDay->cancelEvent(lunch);
        
        aDay->printDay();
        return 0;
#else
        Event multipleEvents[3];
        multipleEvents[0] = breakfast;
        multipleEvents[1] = lunch;
        multipleEvents[2] = dinner;
        
        // permute all combinations of adding events
        int testCount = 1;
        for (int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        if (i==j) continue;
                        for(int k=0;k<3;k++){
                                if (i==k || j==k) continue;
                                
                                cout << "Test: " << testCount << " ------------------\n";
                                Day *aDay = new Day();
                                
                                aDay->scheduleEvent(multipleEvents[i]);
                                aDay->scheduleEvent(multipleEvents[j]);
                                aDay->scheduleEvent(multipleEvents[k]);
                                
                                aDay->printDay();
                                cout << "..................\n";
                                cout << "CSV:\n";
                                cout << aDay->exportDay();
                                cout << "..................\n\n";
                                
                                // cancel the lunch event
                                aDay->cancelEvent(multipleEvents[1]);
                                
                                aDay->printDay();
                                cout << "------------------\n\n";
                                delete aDay;
                                testCount++;
                        }
                }
        }
        return 0;
#endif
}


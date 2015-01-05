/*
 * rectangleTester.cpp
 * main file
 * 
 * Brett Fouss
 *
 * Client will enter in width, height.
 * Helper function will calculate perimeter,
 * area of passed rectangle, as well as cout
 * results. 
 *
 */

#include "rectangle.h"
#include <iostream>

using namespace std;

void output(rectangle r, int n);
bool error (float height, float width);

// Main
// Purp: create instances of rectangles,
//       prompt user input, pass data to
//       helper function for output.
int main()
{
    float height, width;

    rectangle r1; // creates unit rectangle

    cin >> height; // user input
    cin >> width;  // user input

    if (error(height, width))
	return 1; // ends program
    else {
	rectangle r2(height, width); // creates rectangle
                                     // with given height and width

	output(r1, 1);// pass rectangle and then rectangle # to output
	output(r2, 2); // helper function

	return 0;
    }
}

// Output
// Purp: Retrieve perimeter, area
//       Output results and calculations
// Args: Rectangle, number of rectangle
// Rets: Nothing
// Note: Uses functions in implementation file
//       rectangle.cpp
void output(rectangle r, int n)
{
    float perimeter = r.perimeter();
    float area      = r.area();
    bool  isSquare  = r.isSquare(); // true if rectangle is also square

    // text output //

    cout << "r" << n << " has area " << area;
    cout << " perimeter " << perimeter; 

    if (isSquare)
	cout << " and is a square";
    else
	cout << " and is not a square";

    cout << endl;
}

bool error(float height, float width)
{
    if ((height <= 0) || (width <= 0))
	return true;
    else
	return false;
}

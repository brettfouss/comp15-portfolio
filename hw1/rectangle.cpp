/*
 * Rectangle.cpp
 * Implementation File of rectangle class
 *
 * Brett Fouss
 *
 * This file allows the user to retrieve or set
 * the length and width of rectangles, calculate
 * the perimeter and area of a stored rectangle,
 * and check whether or not that rectangle is a
 * square or not. 
 *
 */

#include "rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

//Constructor 1 - creates unit rectangle
rectangle::rectangle()
{
    width = 1;
    height = 1;
}

//Constructor 2 - creates square
rectangle::rectangle(float side)
{
    width = side;
    height = side;
}
//Constructor 3 - creates square with given width/height
rectangle::rectangle(float w, float h)
{
    width = w;
    height = h;
}

//returns width
float rectangle::getWidth()
{
    return width;
}

//returns height
float rectangle::getHeight()
{
    return height;
}

//allows user to set width of rectangle
//pass new width as parameter
void rectangle::setWidth(float w)
{
    width = w;
}

//allows user to set height of rectangle
//pass new height as parameter
void rectangle::setHeight(float h)
{
    height = h;
}

//calculates, returns perimeter
float rectangle::perimeter()
{
    float perimeter = 0;

    perimeter = (2 * width) + (2 * height);

    return perimeter;
}

//calculates, returns area
float rectangle::area()
{
    float area = 0;

    area = width * height;

    return area;
}

//returns if rectangle is square or not
bool rectangle::isSquare()
{
    return (width == height);
}

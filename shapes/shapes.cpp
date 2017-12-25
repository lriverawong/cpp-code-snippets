
#include <iostream>
#include <string>
#include "shapes.h"

using namespace std;

// Shape*********************
Shape::Shape(const string col) :
		colour(col) {}
//Shape::~Shape() {}
string Shape::getColour() const {
	return colour;
}
// Display nonsense values so we can see if these functions get invoked:
double Shape::normalGetArea() const {
	return -100;
}
double Shape::virtualGetArea() const {
	return -100000;
}
// Uncomment this when abstractGetArea is no longer pure virtual
//double Shape::abstractGetArea() const {
//	return -9999;
//}

// Rectangle******************
Rectangle::Rectangle(const string col, double hite, double wid) :
		Shape(col), width(wid), height(hite) {}
double Rectangle::getArea() const {
	return height * width;
}
double Rectangle::normalGetArea() const {
	return height * width;
}
double Rectangle::virtualGetArea() const {
	return height * width;
}
//double Rectangle::abstractGetArea() const {
//	return height * width;
//}
void Rectangle::rectangleMessage() {
	cout << "Here is a message from inside a Rectangle!" << endl;
}

// Square********************
Square::Square(const string col, double s) :
		Rectangle(col, s, s) {}
void Square::squareMessage() {
	cout << "Here is a message from inside a Square!" << endl;
}
void Square::rectangleMessage(const string name) {
	cout << "Here is a message from " + name + " from inside a Square!" << endl;
}


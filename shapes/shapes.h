
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	Shape(const string);
	virtual ~Shape();							// Virtual destructor.  Put this line
												// back in to get rid of the "bug".
	string getColour() const;
	double normalGetArea() const;				// normal
	virtual double virtualGetArea() const;		// virtual
	virtual double abstractGetArea() const; // pure virtual.  Make this just
	// virtual double abstractGetArea() const = 0; // pure virtual.  Make this just
												// virtual so that the testing program
												// will run.
private:
	string colour;
};

class Rectangle : public Shape {
public:
	Rectangle(const string, double, double);
	double getArea() const;
	double normalGetArea() const;
	virtual double virtualGetArea() const override;
	virtual double abstractGetArea() const;
	void rectangleMessage();
protected:
	double width;
	double height;
};

class Square : public Rectangle {
public:
	Square(const string, double);
	void squareMessage();
	// to allow actual overloading use the following:
	using Rectangle::rectangleMessage;
	void rectangleMessage(const string);	// Attempt to overload inherited function.
};


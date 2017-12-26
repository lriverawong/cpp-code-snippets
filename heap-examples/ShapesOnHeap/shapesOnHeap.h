#pragma once

#include <string>
using namespace std;

namespace cisc320 {

	class Shape {
	public:
		Shape(const string&);
		Shape(const Shape&);			// Copy constructor
		virtual ~Shape();				// Virtual Destructor
		Shape& operator=(const Shape&);	// Operator overload of =
		string getColour() const;
		virtual double getArea() const = 0;
	private:
		string* colour;					// Will be on the heap this time
	};

	class Rectangle : public Shape {
	public:
		Rectangle(const string, const string, double, double);
		Rectangle(const Rectangle&);
		virtual ~Rectangle();
		Rectangle& operator=(const Rectangle&);
		string getFillColour() const;
		virtual double getArea() const;
	private:
		string* fillColour;				// On heap
		double height, width;			// Not on heap
	};

	class Square : public Rectangle {
	public:
		Square(const string, const string, double);
		Square(const Square&);
		virtual ~Square();
		Square& operator=(const Square&);
	};

} // end cisc320 namespace


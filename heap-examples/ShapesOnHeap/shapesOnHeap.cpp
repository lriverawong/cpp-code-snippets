
#include <iostream>
#include <string>

#include "shapesOnHeap.h"

using namespace std;

namespace cisc320 {

	// Shape*********************
	// colour is on the heap (even though it really does not have to be...)
	Shape::Shape(const string& col) {
		cout << "Shape constructor." << endl;
		colour = new string(col);
	}
	Shape::Shape(const Shape& right) {
		cout << "Shape copy constructor." << endl;
		colour = new string(right.getColour());
	}
	Shape::~Shape() {
		cout << "Shape destructor: " << *colour << " colour." << endl;
		delete colour;
		colour = nullptr;
	}
	Shape& Shape::operator=(const Shape& right) {
		cout << "Shape operator=." << endl;
		if (this != &right) {
			delete colour;
			colour = new string(right.getColour());
		}
		return *this;
	}
	string Shape::getColour() const {
		return *colour;
	}

	// Rectangle******************
	// fillColour is also on the heap.
	Rectangle::Rectangle(const string col, string fill, double len, double wid) :
			Shape(col), height(len), width(wid) {
		cout << "Rectangle constructor." << endl;
		fillColour = new string(fill);
	}
	Rectangle::Rectangle(const Rectangle& right) : Shape(right), height(right.height), width(right.width) {
		cout << "Rectangle copy constructor." << endl;
		fillColour = new string(right.getFillColour());
	}
	Rectangle::~Rectangle() {
		cout << "Rectangle destructor." << endl;
		delete fillColour;
		fillColour = nullptr;
	}
	Rectangle& Rectangle::operator=(const Rectangle& right) {
		cout << "Rectangle operator=." << endl;
		if (this != &right) {
			Shape::operator=(right);
			delete fillColour;
			fillColour = new string(right.getFillColour());
		}
		return *this;
	}
	string Rectangle::getFillColour() const {
		return *fillColour;
	}
	double Rectangle::getArea() const {
		return height * width;
	}

	// Square********************
	Square::Square(const string col, const string fill, double s) :
			Rectangle(col, fill, s, s) {
		cout << "Square constructor." << endl;
	}
	Square::Square(const Square& right) : Rectangle(right) {
		cout << "Square copy constructor." << endl;
	}
	Square::~Square() {
		cout << "Square destructor. " << getFillColour() << " fill." << endl;
	}
	Square& Square::operator=(const Square& right) {
		cout << "Square operator=." << endl;
		if (this != &right) {
			Rectangle::operator=(right);
		}
		return *this;
	}

} // end cisc320 namespace

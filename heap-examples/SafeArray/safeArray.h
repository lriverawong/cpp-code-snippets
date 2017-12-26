
#pragma once

#include <iostream>
using namespace std;

class SafeArrayException {
public:
	SafeArrayException(const string&);
	string& what();
private:
	string message;
};

class MyArray {
public:
	MyArray(int);				// Constructor, argument is size of the array
	MyArray(const int[], int);	// Constructor, array to convert, size
	~MyArray();					// Destructor!
	int& operator[](int);		// Overloading [] - use on LHS of =
	int operator[](int) const;	// Overloading [] - use on RHS of =
private:
	int size;
	int* values;
friend ostream& operator<<(ostream&, const MyArray&);
};


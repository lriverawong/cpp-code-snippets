#include <iostream>
#include <sstream>		// Only used by conversion constructor
#include <memory>		// NEW
#include <cstring>		// NEW, just for fun
#include "String.h"

using namespace std;

// Used to turn messages from constructors and destructor on or off.
bool showMessages = true;

// Exception thrown if attempt is made to go out of bounds on the buffer
StringBoundsException::StringBoundsException(const string& m) : message(m) {}
string& StringBoundsException::what() { return message; }

// Default constructor
MyString::MyString() {
	len = 0;
	buffer = nullptr;
	if (showMessages)
		cout << "CCCCCCCC  Default Constructor()" << endl;
}
// Simple constructor
MyString::MyString(const char inString[]) {
	len = 0;
	while (inString[len] != '\0')
		len++;
	buffer = unique_ptr<char[]>(new char[len + 1]);	// NEW
	for (int i = 0; i < len; i++)
		buffer[i] = inString[i];
	buffer[len] = '\0';
	if (showMessages) {
		cout << "CCCCCCCC  Simple Constructor(\"";
		cout << buffer.get();
		cout << "\")" << endl;
	}
}
// Copy constructor
MyString::MyString(const MyString& right) {
	len = right.length();
	buffer = unique_ptr<char[]>(new char[len + 1]);	// NEW
	for (int i = 0; i < len; i++)
		buffer[i] = right[i];
	buffer[len] = '\0';
	if (showMessages) {
		cout << "CCCCCCCC  Copy Constructor(\"";
		cout << buffer.get();
		cout << "\")" << endl;
	}
}
// C++ Conversion constructor
MyString::MyString(int aNum) {
	// Demonstrating the old way of converting a number to a string before to_string worked.
	stringstream ss;
	ss << aNum;
	char temp[40];		// assuming an int has less than 40 digits (pretty safe!)
	ss >> temp;
	len = strlen(temp);
	buffer = unique_ptr<char[]>(new char[len + 1]);	// NEW
	strcpy(buffer.get(), temp);
	if (showMessages) {
		cout << "CCCCCCCC  Conversion Constructor(\"";
		cout << buffer.get();
		cout << "\")" << endl;
	}
}
// Destructor
MyString::~MyString() {
	if (showMessages) {
		if (buffer != nullptr) {
			cout << "DDDDDDDD  Destructor(\"";
			cout << buffer.get();
			cout << "\")" << endl;
		} else
			cout << "DDDDDDDD  Destructor() buffer is null" << endl;
	}
// NEW - the destructor no longer does anything!
// Old code:
//	delete[] buffer;
//	buffer = nullptr;
}
// Assignment Overloading
MyString& MyString::operator=(const MyString& right) {
	if (showMessages)
		cout << "OOOOOOOO  Assignment Overloading(\"" << right << "\")" << endl;
	if (this != &right) {		// Check to see if assigning to self
		len = right.length();
		// NEW The old buffer is automatically deleted by the assignment operation:
		buffer = unique_ptr<char[]>(new char[len + 1]);	// NEW
		for (int i = 0; i < len; i++)
			buffer[i] = right[i];
		buffer[len] = '\0';
	}
	return *this;				// Return ref to self
}
// += Operator Overloading to provide concatenation
MyString& MyString::operator +=(const MyString& right) {
	int i, left_len, right_len;
	left_len = len;
	right_len = right.length();
	len = left_len + right_len;
	unique_ptr<char[]> new_buffer(new char[len + 1]);	// NEW
	for (i = 0; i < left_len; i++)
		new_buffer[i] = buffer[i];
	for (i = 0; i < right_len; i++)
		new_buffer[left_len + i] = right[i];
	new_buffer[len] = '\0';
	// NEW Old buffer is automatically deleted by the assignment operation.
	// NEW Note use of move to move the pointer from new_buffer to buffer - it is not copied.
	// NEW new_buffer will bet set to nullptr after the assignment.
	buffer = unique_ptr<char[]>(move(new_buffer));		// NEW
	return *this;
}
// Overloading []
char& MyString::operator[](int index) {
	if (index < 0 || index >= len)
		throw StringBoundsException("Index out of bounds!");
	return buffer[index];
}
char MyString::operator[](int index) const {
	if (index < 0 || index >= len)
		throw StringBoundsException("Index out of bounds!");
	return buffer[index];
}
// String length accessor
int MyString::length() const {
	return len;
}
// For use with cout
ostream& operator<<(ostream& out, const MyString& right) {
	if (right.length() == 0)
		out << "(Empty MyString)";
	else
		for (int i = 0; i < right.length(); i++)
			out << right[i];
	return out;
}

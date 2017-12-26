#include <iostream>
#include <cstring>		// Only used by conversion constructor
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
	// Not using strlen and strcpy, but we could...
	len = 0;
	while (inString[len] != '\0')	// '\0' is the "null character" which is always at the
									// end of a C-string.  We will use the same convention.
		len++;
	buffer = new char[len + 1];		// Using heap
	for (int i = 0; i < len; i++)
		buffer[i] = inString[i];
	buffer[len] = '\0';
	if (showMessages)
		cout << "CCCCCCCC  Simple Constructor(\"" << buffer << "\")" << endl;
}
// Copy constructor
MyString::MyString(const MyString& right) {
	// Do "we" need to delete[] the buffer array here?
	// Are "we" concerned about aliasing here?
	len = right.length();
	buffer = new char[len + 1];		// Using heap
	for (int i = 0; i < len; i++)
		buffer[i] = right[i];
	buffer[len] = '\0';
	if (showMessages)
		cout << "CCCCCCCC  Copy Constructor(\"" << buffer << "\")" << endl;
}
// C++ Conversion constructor
MyString::MyString(int aNum) {
	char temp[40];		// assuming an int has less than 40 digits (pretty safe!)
	len = 0;
	strcpy(temp, to_string(aNum).c_str());
	while (temp[len] != '\0')
		len++;
	buffer = new char[len + 1];		// using heap
	for (int i = 0; i < len; i++)
		buffer[i] = temp[i];
	buffer[len] = '\0';
	if (showMessages)
		cout << "CCCCCCCC  Conversion Constructor(\"" << buffer << "\")" << endl;
}
// Destructor
MyString::~MyString() {
	if (showMessages) {
		if (buffer != nullptr)
			cout << "DDDDDDDD  Destructor(\"" << buffer << "\")" << endl;
		else
			cout << "DDDDDDDD  Destructor() buffer is null" << endl;
	}
	delete[] buffer;
	buffer = nullptr;
}
// Assignment Overloading
MyString& MyString::operator=(const MyString& right) {
	if (showMessages)
		cout << "OOOOOOOO  Assignment Overloading(\"" << right << "\")" << endl;
	if (this != &right) {		// Check to see if assigning to self
		delete[] buffer;		// Get rid of old buffer
		len = right.length();
		buffer = new char[len + 1];	// Using heap
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
	char* new_buffer = new char[len + 1];	// Using heap
	for (i = 0; i < left_len; i++)
		new_buffer[i] = buffer[i];
	for (i = 0; i < right_len; i++)
		new_buffer[left_len + i] = right[i];
	new_buffer[len] = '\0';
	delete[] buffer;						// Using heap
	buffer = new_buffer;
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





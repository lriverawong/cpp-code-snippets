
#pragma once

#include <iostream>
#include <memory>		// NEW

using namespace std;

class StringBoundsException {
public:
	StringBoundsException(const string&);
	string& what();
private:
	string message;
};

class MyString {
public:
	MyString();					// Default constructor
	MyString(const char[]);		// Simple constructor
	MyString(const MyString&);	// Copy constructor
	MyString(int);				// Conversion constructor
	~MyString();				// Destructor
	MyString& operator=(const MyString&);
	MyString& operator+=(const MyString&);
	char& operator[](int);
	char operator[](int) const;
	int length() const;
private:
	unique_ptr<char[]> buffer;	// NEW
	//char* buffer;				// old
	int len;
};

ostream& operator<<(ostream& out, const MyString&);

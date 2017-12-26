#include <iostream>
#include "String.h"

using namespace std;

MyString globalString("I\'m a global variable!");

// Passing by value
void aUselessFunction(const MyString myStr) {
	cout << "Inside a function: " << myStr << endl;
}

// Passing by const reference (preferred)
void anotherUselessFunction(const MyString& myStr) {
	cout << "Inside another function: " << myStr << endl;
}

int main() {
	cout << "\nMMMMMMMM main starts. MMMMMMMM" << endl;

	// Constructors
	cout << "Constructing Strings:" << endl;
	MyString testA("Hello!");
	cout << testA << endl;
	MyString testB(456);
	cout << testB << endl;
	MyString testC;
	cout << testC << endl;

	cout << "\nInvoking a function, by value:" << endl;
	aUselessFunction(testA);
	cout << "\nInvoking a function, by reference:" << endl;
	anotherUselessFunction(testA);

	// Copy constructors
	cout << "\nCopy constructors:" << endl;
	MyString testD("TestD");
	MyString testE(testD);
	cout << testE << endl;

	cout << "\nAssignment operator:" << endl;
	MyString testF;
	testF = testE;
	testE[0] = 'B';			// String is mutable!
	cout << testF << endl;
	cout << testE << endl;	// Test aliasing

	// testG is on the heap
	cout << "\nUsing the heap:" << endl;
	MyString* testG = new MyString("TestG");
	cout << *testG << endl;
	delete testG;
	testG = nullptr;
	delete testG;	// Nothing bad happens!

	// Testing concatenation, etc.
	cout << "\nConcatenation:" << endl;
	MyString test1("Test1");
	MyString test2("Test2");
	test2 += test1;
	cout << test2 << endl;

	cout << "\nMixed type concatenations:" << endl;
	MyString test3("Test3");
	test3 = 123;
	cout << test3 << endl;
	test3 += "aString";
	cout << test3 << endl;
	test3 += 'Z';
	cout << test3 << endl;

	cout << "\nDeclared on the heap, but not deleted:" << endl;
	MyString* lastOne = new MyString("Last local variable");
	cout << *lastOne << endl;

	cout << "\nMMMMMMMM main is done. MMMMMMMM" << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <memory>
#include "String.h"

using namespace std;

// Passing unique_ptr by reference
void aUselessFunction(const unique_ptr<MyString>& myStr) {
	cout << "Inside a function: " << *myStr << endl;
}

// Passing unique_ptr by value
void anUselessFunction(const unique_ptr<MyString> myStr) {
	cout << "Inside a function: " << *myStr << endl;
}

// Normal passing by const reference
void anotherUselessFunction(const MyString& myStr) {
	cout << "Inside another function: " << myStr << endl;
}

int main() {
	cout << "\nMMMMMMMM main starts. MMMMMMMM" << endl;

	cout << "\nInvoking a function, by passing a unique_ptr by reference:" << endl;
	unique_ptr<MyString> testA(new MyString("Some string for the function."));
	aUselessFunction(testA);
	cout << "Back in main: " << *testA << endl;

	cout << "\nInvoking a function, by passing a unique_ptr by value:" << endl;
	unique_ptr<MyString> testB(new MyString("Another string for the function."));
	anUselessFunction(move(testB));		// main has to relinquish ownership of testA
	cout << "Back in main: " << testB.get() << endl;

	cout << "\nInvoking another function, by passing a normal reference:" << endl;
	unique_ptr<MyString> testC(new MyString("Yet another string for the function."));
	anotherUselessFunction(*testC);
	cout << "Back in main: " << *testC << endl;

	// make_unique puts the unique_ptr on the heap, but is only available in C++14:
	// No need to use new with make_unique.
	cout << "\nPut a smart pointer on the heap:" << endl;
	unique_ptr<MyString> testD = make_unique<MyString>(MyString("A string on the heap."));

	// Memory leak test.  Watch for increasing memory usage if pointer is not being deleted properly.
	// Turn messages off for this test, and comment out vector test.
//	for (int i = 0; i < 10000000; i++)
//		unique_ptr<MyString> test(new MyString("Some string for the constructor."));

	// Demonstrates the automatic destruction of an entire collection of unique_ptrs:
//	vector<unique_ptr<MyString>> strings;
//	for (int i = 0; i < 100; i++) {
//		MyString* toAdd = new MyString("String number ");
//		*toAdd += i;
//		strings.push_back(unique_ptr<MyString>(toAdd));
//	}

	cout << "\nMMMMMMMM main is done. MMMMMMMM" << endl;
	return 0;

} // end main


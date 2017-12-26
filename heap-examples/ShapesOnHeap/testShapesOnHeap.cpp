#include <iostream>

#include "shapesOnHeap.h"

using namespace std;

int main() {

	cout << "Constructing a Square:" << endl;
	cisc320::Square* sq = new cisc320::Square("red", "blue", 10);
	cout << "\nCopying, then deleting a Square:" << endl;
	cisc320::Square* sqCopy = new cisc320::Square(*sq);
	delete sqCopy;
	cout << "\nAssigning a Square:" << endl;
	cisc320::Square sqOnStack("pink", "yellow", 20);
	cisc320::Square sqAssign("gray", "black", 5);
	sqAssign = sqOnStack;
	cout << "\nDeleting a Square:" << endl;
	delete sq;

	cout << "\nConstructing a Square assigned to a Shape pointer:" << endl;
	cisc320::Shape* shapeSq = new cisc320::Square("green", "violet", 30);
	cout << "\nDeleting Shape pointer:" << endl;
	delete shapeSq;

	cout << "\nEnd of main. Followed by destruction of stack variables:" << endl;

	return 0;

} // end main function

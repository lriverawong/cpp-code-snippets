#include <iostream>
#include <string>
#include <typeinfo>
#include "shapes.h"

using namespace std;

void areaPassPointer(const Shape* sh) {
	cout << sh->virtualGetArea() << endl;
}
void areaPassReference(const Shape& sh) {
	cout << sh.virtualGetArea() << endl;
}
// This will not work if Shape is abstract because of the attempted use of a copy
// constructor for the parameter.
void areaPassValue(Shape sh) {
	cout << sh.virtualGetArea() << endl;
}

int main() {

	Shape shpVar("pink");		// Won't work if Shape is abstract

	// Creation of a pointer without using the heap
	Square sqrVar("red", 20);
	Shape* shapePtr = &sqrVar;
	sqrVar.squareMessage();
	sqrVar.rectangleMessage();		// Not inherited - hidden!
	cout << "The previous message was an overloaded inherited virtual method" << endl;
	sqrVar.rectangleMessage("Alan");

	cout << "Testing the pointer:" << endl;
	cout << "Square area = " << shapePtr->normalGetArea() << endl;	// Static binding
																	// uses the pointer type
	cout << "Square area = " << shapePtr->virtualGetArea() << endl;	// Dynamic binding
																	// uses the object type

	// What about using a reference instead of a pointer?
	// Polymorphism still works
	Shape& shapeRef = sqrVar;
	cout << "\nTesting reference:" << endl;
	cout << "Square area = " << shapeRef.normalGetArea() << endl;
	cout << "Square area = " << shapeRef.virtualGetArea() << endl;
	// shapeRef.squareMessage();		// Fails early binding

	// Normal instantiation - no funny stuff (polymorphism) here!
	cout << "\nNormal instantiation:" << endl;
	Rectangle rectVar("blue", 20, 10);

	cout << "Rectangle colour = " << rectVar.getColour() << endl;	// Inherited from Shape
	cout << "Rectangle area = " << rectVar.getArea() << endl;		// Function in Rectangle
	cout << "Rectangle area = " << rectVar.normalGetArea() << endl;	// Rectangle version
	cout << "Rectangle area = " << rectVar.virtualGetArea() << endl;// Overridden version in Rectangle
	rectVar.rectangleMessage();

	// Testing function calls
	cout << "\nTesting function calls:" << endl;
	areaPassPointer(&sqrVar);
	areaPassReference(sqrVar);
	areaPassValue(sqrVar);		// Object Slicing!!

	// Testing dynamic_cast<>
	cout << "\nTesting dynamic_cast<> with a Square:" << endl;
	Square sqrVarAgain("green", 30);
	Shape* whatAmI = &sqrVarAgain;
	if (dynamic_cast<Square*>(whatAmI) == nullptr)
		cout << "I am not a Square!" << endl;
	else
		cout << "I am a Square!" << endl;
	if (dynamic_cast<Rectangle*>(whatAmI) == nullptr)
		cout << "I am not a Rectangle!" << endl;
	else
		cout << "I am a Rectangle!" << endl;
	if (dynamic_cast<Shape*>(whatAmI) == nullptr)
		cout << "I am not a Shape!" << endl;
	else
		cout << "I am a Shape!" << endl;

	cout << "\nTesting dynamic_cast<> again with a Rectangle:" << endl;
	Rectangle rectVarAgain("green", 30, 10);
	Shape* whatAmIAgain = &rectVarAgain;
	if (dynamic_cast<Square*>(whatAmIAgain) == nullptr)
		cout << "I am not a Square!" << endl;
	else
		cout << "I am a Square!" << endl;
	if (dynamic_cast<Rectangle*>(whatAmIAgain) == nullptr)
		cout << "I am not a Rectangle!" << endl;
	else
		cout << "I am a Rectangle!" << endl;
	if (dynamic_cast<Shape*>(whatAmIAgain) == nullptr)
		cout << "I am not a Shape!" << endl;
	else
		cout << "I am a Shape!" << endl;

	// dynamic_cast<> will not work with a reference
	// A reference can never be nullptr
//	cout << "\nTesting dynamic_cast<> again with a Rectangle reference:" << endl;
//	Shape& shapeRefAgain = rectVarAgain;
//	if (dynamic_cast<Square&>(shapeRefAgain) == nullptr)
//		cout << "I am not a Square!" << endl;

	// Testing typeid() - which you should never normally need to use...
	// Provides different results from the casting test above.
	cout << "\nTesting typeid():" << endl;
	if (typeid(*whatAmIAgain) == typeid(Square))
		cout << "I am a Square!" << endl;
	else
		cout << "I am not a Square!" << endl;
	if (typeid(*whatAmIAgain) == typeid(Rectangle))
		cout << "I am a Rectangle!" << endl;
	else
		cout << "I am not a Rectangle!" << endl;
	if (typeid(*whatAmIAgain) == typeid(Shape))
		cout << "I am a Shape!" << endl;
	else
		cout << "I am not a Shape!" << endl;

	cout << "\nEnd of main." << endl;

	return 0;

} // end main function

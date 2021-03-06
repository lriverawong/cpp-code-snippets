#include <iostream>
#include <string>
#include "myArray.h"

using namespace std;

int main() {
    cout << "---- Start of program ----" << endl;
    MyArray arr1;
    cout << "arr1 obj size = " << arr1.getSize() << endl;
    cout << "--\n";

    MyArray arr2(10);
    MyArray* arr3 = &arr2;
    cout << "arr2 obj size = " << arr2.getSize() << endl;
    cout << "*arr3 size = " << arr3->getSize() << endl;
    try {
        MyArray arrErr(-10);
    } catch (MyArrayBoundsException &e) {
        cout << "Error: " << e.errorMessage() << endl;
    }
    cout << "--\n";

    cout << "Testing overloaded[]" << endl;
    int intArr[2] = {6, 7};
    MyArray arr4(intArr, 2);
    arr4[0] = 100;
    cout << arr4 << endl;
    cout << "--\n";

    cout << "Testing copy constructor"  << endl;
    MyArray arr5(arr4);
    cout << "arr4 = " << arr4 << endl;
    cout << "arr5 = " << arr5 << endl;
    cout << "--\n";

    cout << "Testing overloaded[] again" << endl;
    arr4[0] = 1000;
    arr5[1] = 777;
    cout << "arr4 = " << arr4 << endl;
    cout << "arr5 = " << arr5 << endl;
    cout << "--\n";

    cout << "Testing overloaded+" << endl;
    MyArray arr6 = arr4 + arr5;
    cout << "arr6 = " << arr6 << endl;

    cout << "---- End of program ----" << endl;
    return 0;
};
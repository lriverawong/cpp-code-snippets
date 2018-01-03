#include <iostream>
#include <string>
#include "myArray.h"

using namespace std;

int main() {
    cout << "---- Start of program ----" << endl;
    MyArray arr1;
    cout << arr1.getSize() << endl;
    MyArray arr2(10);
    MyArray* arr3 = &arr2;
    cout << arr2.getSize() << endl;
    //double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    // int regArr[4] = {1,2,3,4};
    // MyArray arr3()
    int intArr[2] = {6, 7};
    MyArray arr4(intArr);
    
    
    cout << "---- End of program ----" << endl;
    return 0;
};
#include "myArray.h"
#include <string>

bool showMessages = true;

MyArrayBoundsException::MyArrayBoundsException(const string& theMessage) : message(theMessage) {}
string& MyArrayBoundsException::errorMessage() { return message; }

int MyArray::getSize(){
    return size;
}

MyArray::MyArray() {
    intArr = unique_ptr<int[]>(new int[0]);
    size = 0;
    if(showMessages) {cout << "MyArray()" << endl;}
}

/*
    Allocate a MyArray wrapper of a specific size all initialized with 0.
*/
MyArray::MyArray(int argSize) {
    if (size < 0) {
        throw MyArrayBoundsException("Size cannot be less than 0.");
    }
    size = argSize;
    intArr = unique_ptr<int[]>(new int[size]);
    for (int i = 0; i < size; i++) {
        intArr[i] = 0;
    }
    if(showMessages) {cout << "MyArray(int size)" << endl;}
}

// template<int N>
// int MyArray::arrSize(int (&argArr)[N]) { 
//     int tempVar = static_cast<int>(N);
//     return tempVar;
// }

// https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part
template<int N>
void fun(string (&s)[N]) {
   for (int i(0); i < N; ++i)
      cout << i << ": " << s[i] << endl;
}

// MyArray::MyArray(int (&argArray)) {
//     int len = 0;
//     len = arrSize(argArray);
//     // intArr = unique_ptr<int[]>(new int[len]);
//     // for (int i = 0; i < len; i++){
//     //     intArr[i] = argArr[i];
//     // }
//     if(showMessages) {cout << "MyArray(const int argArr[])" << endl;}     
// }
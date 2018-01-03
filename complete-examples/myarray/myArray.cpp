#include "myArray.h"
#include <string>

bool showMessages = true;

MyArrayBoundsException::MyArrayBoundsException(const string& theMessage) : message(theMessage) {}
string& MyArrayBoundsException::errorMessage() { return message; }

int MyArray::getSize()
{
    return size;
}

MyArray::MyArray()
{
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

template <int N>
int MyArray::arrSize(int (&argArr)[N])
{
    return N;
}

template <int N>
MyArray::MyArray(int (&argArr)[N])
{
    int len = N;
    cout << "len = " + to_string(len) << endl;
    // intArr = unique_ptr<int[]>(new int[len]);
    // for (int i = 0; i < len; i++){
    //     intArr[i] = argArr[i];
    // }
    if(showMessages) {cout << "MyArray(const int argArr[])" << endl;}     
}
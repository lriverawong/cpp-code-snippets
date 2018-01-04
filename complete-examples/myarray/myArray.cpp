#include "myArray.h"
#include <string>

bool showMessages = true;

/*
MyArray Definitions
*/

MyArrayBoundsException::MyArrayBoundsException(const string& theMessage) : message(theMessage) {}
string& MyArrayBoundsException::errorMessage() { return message; }

int MyArray::getSize() const{
    return size;
}

MyArray::~MyArray() {}

MyArray::MyArray(){
    this->intArr = unique_ptr<int[]>(new int[0]);
    this->size = 0;
    if(showMessages) {cout << "MyArray()" << endl;}
}


// Allocate a MyArray wrapper of a specific size all initialized with 0.
MyArray::MyArray(int argSize) {
    if (argSize < 0) {
        throw MyArrayBoundsException("Size cannot be less than 0.");
    }
    this->size = argSize;
    this->intArr = unique_ptr<int[]>(new int[size]);
    for (int i = 0; i < this->size; i++) {
        this->intArr[i] = 0;
    }
    if(showMessages) {cout << "MyArray(int size)" << endl;}
}


MyArray::MyArray(int argArr[], int argSize) {
    if (argSize < 0){
        throw MyArrayBoundsException("Size cannot be less than 0.");
    }
    this->size = argSize;
    intArr = unique_ptr<int[]>(new int[this->size]);
    for (int i = 0; i < this->size; i++) {
        this->intArr[i] = argArr[i];
    }
    if(showMessages) {cout << "MyArray(int argArr[], int size)" << endl;}     
}

MyArray::MyArray(const MyArray &anArr) {
    this->size = anArr.getSize();
    intArr = unique_ptr<int[]>(new int[this->size]);
    for (int i = 0; i < this->size; i++) {
        this->intArr[i] = anArr[i];
    }
    if (showMessages) {
        cout << "MyArray(int argArr[], int size)" << endl;
    }
}

// Overloading []
int & MyArray::operator[](int index) {
    if (index < 0 || index >= this->size)
        throw MyArrayBoundsException("Index out of bounds!");
    return intArr[index];
}
int MyArray::operator[](int index) const {
    if (index < 0 || index >= this->size)
        throw MyArrayBoundsException("Index out of bounds!");
    return intArr[index];
}

// Overloading + 
// to be able to concatenate MyArray(s), because why not
MyArray operator+(const MyArray &left, const MyArray &right) {
    int newSize = left.getSize() + right.getSize();
    int tempArr[newSize];
    for (int i = 0; i < left.getSize(); i++) {
        tempArr[i] = left[i];
    }
    for (int i = left.getSize(); i < newSize; i++) {
        tempArr[i] = right[i-left.getSize()];
    }
    return MyArray(tempArr, newSize);
}

// For use with cout
ostream &operator<<(ostream &out, const MyArray &anArr) {
    if (anArr.getSize() == 0) {
        out << "(Empty MyArray)";
    }
    else {
        out << "[";
        for (int i = 0; i < anArr.getSize()-1; i++) {
            out << anArr[i] << ",";
        }
        out << anArr[anArr.getSize()-1] << "]";
    }
    return out;
}

/*
DualMyArray Definitions
*/
template<typename T>
int MyArray<T>::getSize() const{
    return size;
}

template<typename T>
DualMyArray<T>::DualMyArray() {
    this->intArr = unique_ptr<int[]>(new int[0]);
    this->size = 0;
    this->tArr = unique_ptr<T[]>(new T[0]);
    this->size2 = 0;
    if (showMessages)
    {
        cout << "MyArray()" << endl;
    }
}

// Overloading []
int &MyArray::operator[][](int index)
{
    if (index < 0 || index >= this->size)
        throw MyArrayBoundsException("Index out of bounds!");
    return intArr[index];
}
int MyArray::operator[](int index) const
{
    if (index < 0 || index >= this->size)
        throw MyArrayBoundsException("Index out of bounds!");
    return intArr[index];
}

// For use with cout
template<typename T>
ostream &operator<<(ostream &out, const DualMyArray &anArr) {
    if (anArr.getSize() == 0) {
        out << "(Empty DualMyArray #1)";
    }
    else {
        out << "DualMyArray #1 = [";
        for (int i = 0; i < anArr.getSize() - 1; i++) {
            out << anArr[i] << ",";
        }
        out << anArr[anArr.getSize() - 1] << "]\n";
    }
    if (anArr.getSize2() == 0) {
        out << "(Empty DualMyArray #2)";
    }
    else {
        out << "DualMyArray #1 = [";
        for (int i = 0; i < anArr.getSize2() - 1; i++)
        {
            out << anArr[1] << ",";
        }
        out << anArr[anArr.getSize2() - 1] << "]\n";
    }
    return out;
}
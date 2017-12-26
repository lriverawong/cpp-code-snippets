bool showMessages(false);

MyArrayBoundsException::MyArrayBoundsException(const string& theMessage) : message(theMessage) {}
string& MyArrayBoundsException::errorMessage() { return message; }

MyArray::getSize(){
    return size;
}

MyArray::MyArray() {
    intArr = unique_ptr<int[]>(new int[0]);
    size = 0;
}

/*
    Allocate a MyArray wrapper of a specific size all initialized with 0.
*/
MyArray::MyArray(int size) {
    if ()
}


MyArray::MyArray(const int argArr[]) {
    int len = arrArr.size();
    intArr = unique_ptr<int[]>(new int[len]);
    for (int i = 0; i < len; i++){
        intArr[i] = argArr[i];
    }
    if(showMessages) {cout << "myArray(const int argArr[])" << endl;}     
}



#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>

using namespace std;

/*
Pointers and References: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
*/

template <typename T>
void printArr(T anArr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << " = " << anArr[i] << endl;
    }
}

void changeArrPtr(int anArr[], int size) {
    for (int i = 0; i < size; i++) {
        anArr[i] = 10 + i;
    }
}

void changeArrRef(int (&anArr), int size) {
    for (int i = 0; i < size; i++) {
        anArr[i] = 20 + i;
    }
}

int main() {
    int anArr[] = {1,2,3,4,5,6};
    printArr(anArr, 6);
    cout << typeid(anArr).name() << endl;
    // pointer
    changeArrPtr(anArr, 6);
    printArr(anArr, 6);
    // reference
    changeArrRef(anArr, 6);
    printArr(anArr, 6);
}
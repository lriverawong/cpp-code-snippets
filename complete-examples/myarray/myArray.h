#include <iostream>
#include <memory>

using namespace std;

class MyArrayBoundsException {
    private:
        string message;
    public: 
        MyArrayBoundsException(const string&);
        string errorMessage();
};

class MyArray{
    private:
        unique_ptr<int[]> intArr;
        int size;
    public:
        MyArray(const int[]);
        MyArray(const int[], const int);
        // MyArray(const MyArray&);
        
};
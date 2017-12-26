#include <iostream>
#include <memory>

using namespace std;

class MyArrayException {
    private:
        string message;
    public: 
        MyArrayException(const string&);
        string errorMessage();
};

class MyArray{
    private:
        unique_ptr<int[]> intArr;
    public:
        MyArray(const int[]);
        MyArray(const int[], const int);
        // MyArray(const MyArray&);
        
};
#include <iostream>
#include <memory>

using namespace std;



class MyArrayBoundsException {
    private:
        string message;
    public: 
        MyArrayBoundsException(const string&);
        string& errorMessage();
};

class MyArray{
    
    private:
        unique_ptr<int[]> intArr;
        int size;
        
        // int arrSize(int (&argArr)[N]);
        
    public:
        int getSize();
        MyArray();
        MyArray(int);
        // MyArray(int (&argArr));
        // MyArray(const int[], const int);
        // MyArray(const MyArray&);
        template<int N>
        void fun(string (&s)[N]);
        
};

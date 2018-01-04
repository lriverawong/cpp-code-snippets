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


class MyArray
{

  private:
    unique_ptr<int[]> intArr;
    int size;

  public:
    int getSize() const;
    // defaults to empty container with size=0
    MyArray();
    // specify size of container
    MyArray(int argSize);
    // providing a c-style array
    MyArray(int argArr[], int argSize);
    // destructor
    ~MyArray();
    // Copy constructor
    MyArray(const MyArray &anArr);
    int &operator[](int aVal);
    int operator[](int aVal) const;
};

ostream &operator<<(ostream &out, const MyArray &anArr);
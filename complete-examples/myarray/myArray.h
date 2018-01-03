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
    template <int N>
    int arrSize(int (&argArr)[N]);

  public:
    int getSize();
    MyArray();
    MyArray(int argSize);
    template <int N>
    MyArray(int (&argArr)[N]);
};

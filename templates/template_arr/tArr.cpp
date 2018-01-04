#include <iostream>
// to print a string with cout we need to include <string>
#include <string>

using namespace std;

template<typename T>
class sArr {
private:
  int cap;  // max size of array
  int numOfEl;
  T *arr;
public:
  sArr(int size = 5); // put default in function declaration not definition
  ~sArr();
  int size() const;
  void add(const T &obj);
  T& get(int index);
};

template <typename T>
sArr<T>::sArr(int size) {
  this->cap = size;
  this->numOfEl = 0;
  this->arr = new T[this->cap];
}

template <typename T>
sArr<T>::~sArr() {
  delete[] this->arr;
}

template <typename T>
int sArr<T>::size() const
{
  return this->numOfEl;
}

template <typename T>
void sArr<T>::add(const T &obj)
{
  if(this->numOfEl < this->cap) {
    this->arr[this->numOfEl++] = obj; //post-increment after operation done
  }
  else {
    cout << "Array is at its max" << endl;
  }
}

template <typename T>
T& sArr<T>::get(int index)
{
  if (index < 0 || index >= this->numOfEl)
    throw "Bad index!";
  return this->arr[index];
}

template <typename T>
void playPtrRef(T *&intArr) {
  delete[] intArr;
  intArr = new int[20];
  for (size_t i = 0; i < 20; i++) {
    intArr[i] = 10;
  }
}

int main() {
  system("PAUSE");

  sArr<int> mia;
  sArr<string> msa;

  for (size_t i = 0; i < 5; i++) {
    mia.add(10);
    msa.add("HELLO");
  }

  for (size_t i = 0; i < 5; i++) {
    cout << mia.get(i) << endl;
    cout << msa.get(i) << endl;
  }

  int *intArr = new int[10];
  playPtrRef(intArr); //changing array of size 10 to 20 and deletes original array
  for (size_t i = 0; i < 20; i++) {
    cout << i << ": " << intArr[i] << endl;
  }

  delete[] intArr;

  cout << "--- End of program --- " << endl;
};

/*
Some References:
http://www.cplusplus.com/doc/oldtutorial/templates/
  - when we define a function member outside the declaration of the class template
    we must always precede that definition with the template <...> prefix.
*/
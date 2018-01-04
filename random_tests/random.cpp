#include <iostream>
#include <string>

using namespace std;

// template<int N>
// void fun(int (&anInt)[N])
// {
//    for (int i(0); i < N; ++i)
//       cout << i << ": " << anInt[i] << endl;
// }
// template<int N>
// int fun2(int (&anInt)[N])
// {
//    int j(0);
//    for (int i(0); i < N; ++i)
//       j++;
//    cout << "j = " + to_string(j) << endl;
//    return N;
// }

class Exchange {
    public:
      int randInt;
      template<int N>
      int retSize(int (&anArr)[N]);
};

template<int N>
int Exchange::retSize(int (&anArr)[N]) {
      return N;
}

int main()
{
    int s[2] = {10,20};
//    fun(s);
//    cout << fun2(s) << endl;
    Exchange someVar;
    int aVar = someVar.retSize(s);
    cout << aVar << endl;
}

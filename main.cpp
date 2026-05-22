#include <iostream>
using namespace std;

int main() {

    const int n = 5;
  
    // Pointer to a const int
    const int* ptr = &n;

    // int* nonConstPtr = ptr; if we use this
    // instead of without using const_cast
    // we will get error of invalid conversion
    int* nonConstPtr = const_cast<int*>(ptr);
    *nonConstPtr = 10;

    cout << *nonConstPtr;

    return 0;
}
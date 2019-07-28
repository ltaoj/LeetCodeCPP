#include <iostream>
#include<vector>
using namespace std;


class A {
public:
    bool test() {
        vector<int> a;
        a[0] = 1;
        test2(a);
    }

    bool test2(vector<int> a) {
    cout << a[0] << endl;
    }
};

int main() {

    cout << "Hello World";
    A a;
    a.test;
    return 0;
}
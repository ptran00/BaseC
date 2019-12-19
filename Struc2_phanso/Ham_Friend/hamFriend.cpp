#include <iostream>
using namespace std;
class B; // khai bao lop B
class A {

    int x;
 
public:
    void setdata(int i) {
        x = i;
    }
    friend void min(A, B); // ham friend
};
class B {
    int y;
 
public:
    void setdata(int i) {
        y = i;
    }
    friend void min(A, B); // ham friend
};
 
void min(A a, B b) {
    if (a.x <= b.y)
        cout << a.x << endl;
    else
        cout << b.y << endl;
}
int main() {
    A a;
    B b;
    a.setdata(50);
    b.setdata(20);
    min(a, b);

	system("pause");
    return 0;
}
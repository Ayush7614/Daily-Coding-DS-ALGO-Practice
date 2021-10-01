// In the below code, Single Inheritance concept is implemented.
// Class B also known as child class inherits data
// So we get inherited printed as output.

#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "Inherited";
    }
};
class B : public A
{
};

int main()
{
    B b;
    b.func(); // class B inherited class A
}

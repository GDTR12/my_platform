#include "SoTest.h"
#include "iostream"
using namespace std;

class Test:public SoTest
{
public:
    void func1()
    {
        cout<<"Test virture"<<__func__<<endl;
    }
    void func2()
    {
        cout<<"Test virture"<<__func__<<endl;        
    }
    void func3() override
    {
        cout<<"Test virture"<<__func__<<endl;
    }
};

// int main()
// {
//     Test t;
//     t.func1();
//     t.func2();
//     t.func3();
// }
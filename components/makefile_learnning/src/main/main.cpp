#include "iostream"
#include "../others/add.h"
#include "../others/sub.h"

using namespace std;

int main()
{
    cout<<"["<<__func__<<"]:print"<<endl;

    cout<<"a+b: "<<add(1, 2)<<endl;
    
    cout<<"a-b: "<<sub(1, 2)<<endl;

    return 0;
}


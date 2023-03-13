#include <iostream>

using namespace std;




/* ------------------------------ class ------------------------------ */



#include "Sales_item.h"
int main()
{
    /* ------------------------------ lambda ------------------------------ */
    // int data = 4;
    // auto func = [data](int value)->int{
    //     return value + data;
    // };
    // cout<<func(3)<<endl;
    // cout<<"------------------------------ cpp_learnning ------------------------------"<<endl;

    /* ------------------------------ const ------------------------------ */
    const int data = 1;
    // data = 2; 错误
    // const int data2; 错误
    // int* pdata = &data; 错误
    extern const int data2;
    // extern const int data2 = 2;错误

    
    /* ------------------------------ typedef decltype ------------------------------ */
    
}

#include <iostream>
#include "Sales_item.h"
#include <fstream>
#include <vector>
using namespace std;




/* ------------------------------ class ------------------------------ */




// int main()
// {
//     /* ------------------------------ lambda ------------------------------ */
//     // int data = 4;
//     // auto func = [data](int value)->int{
//     //     return value + data;
//     // };
//     // cout<<func(3)<<endl;
//     // cout<<"------------------------------ cpp_learnning ------------------------------"<<endl;


    
    
//     /* ------------------------------ typedef decltype ------------------------------ */
//     /* ------------------------------ iostream ------------------------------ */
//     /* method one */
    
//     // ofstream fout("test.txt");
//     // fout<<"Words been written to this file\r\n";
//     // fout.close();

//     // ifstream fin("test.txt");
//     // string s;   
//     // fin>>s;
//     // cout<<s<<endl;  //读单个字符
//     // fin.close();

//     // /* method two */
//     // ofstream fout2;
//     // fout2.open("test.txt");
//     // fout2<<"method two:word has been written to this file"<<endl;
//     // fout2<<"method two:word has been written to this file"<<endl;
//     // fout2.close();

//     // ifstream fin2("test.txt",ios::in);
//     // string tmp,s2;
//     // while(getline(fin2,tmp)){
//     //     cout<<tmp<<endl;
//     // }
//     // cout<<s2<<endl;
//     // fin2.close();

//     /* 二进制读取 */
//     // std::ifstream file("test.txt", std::ios::binary | std::ios::ate);
//     // if (!file) {
//     //     std::cerr << "无法打开文件\n";
//     //     return 1;
//     // }

//     // // 获取文件大小
//     // std::streamsize size = file.tellg();
//     // file.seekg(0, std::ios::beg);

//     // // 创建一个足够大的字符数组
//     // std::vector<char> buffer(size);

//     // // 将文件内容读入到字符数组中
//     // if (file.read(buffer.data(), size))
//     // {
//     //     // 转换为字符串
//     //     std::string content(buffer.begin(), buffer.end());
//     //     // 输出字符串
//     //     std::cout << content << "\n";
//     // }
    
//     // // 关闭文件
//     // file.close();

//     // ifstream fs("test.txt",ios::binary|ios::ate);
//     // if (!fs.is_open()){
//     //     cout<<"file does not exist!"<<endl;
//     //     return -1;
//     // }

//     // streamsize size = fs.tellg();
//     // fs.seekg(0, ios_base::beg);
//     // vector<char> buffer(size);
//     // if (fs.read(buffer.data(), size)) 
//     // {
//     //     string content(buffer.begin(), buffer.end());   
//     //     string content(buffer.data(),size);
//     //     cout<<content<<endl; 
//     // }
//     // fs.close();

    

    
// }

/* ------------------------------ 链式编程 科里化 ------------------------------ */
// class Chain
// {
// private:
//     int sum = 0;
// public:
//     Chain(){};
//     ~Chain(){};
//     Chain& operator()(int i)
//     {
//         sum += i;
//         return *this;
//     }
//     operator int(){
//         return this->sum;
//     }
// };

// int main()
// {
//     Chain chain;
//     chain(1)(2)(3);
//     std::cout<< chain + 4 <<std::endl;
// }
#include <functional>
#include <iostream>
/* ------------------------------ std::bind ------------------------------ */
// using  namespace std::placeholders;
// int foo(int x,int y)
// {
//     std::cout<<"x:"<<x<<std::endl<<"y:"<<y<<std::endl;
//     return x+y;
// }


// #include <array>
// template<typename Arr>
// void print_arr(Arr& arr)
// {
//     for (auto &arr_ : arr)
//     {
//         cout<<arr_<<",";
//     }
//     cout<<endl;
// }
// int main()
// {

//     auto func = std::bind(foo,_2,_1);
//     func(1,2);
    
//     std::array arr = {2,4,1,3,5};
//     std::sort(arr.begin(),arr.end());
//     print_arr(arr);

//     // std::sort(arr.begin(),arr.end(),std::greater<decltype(*arr.data())>{});
//     // print_arr(arr);

//     auto sort_inverse = std::bind(std::sort<int *,std::greater<int &>>,_1,_2,std::greater<int&>{});
//     sort_inverse(arr.begin(),arr.end());
//     print_arr(arr);

// }


/* ------------------------------ is_reference ------------------------------ */
// #include <iostream>

// void func2(int& a){
//     std::cout<<"left reference:"<<std::is_lvalue_reference_v<decltype(a)><<std::endl; 
//     std::cout<<"right reference:"<<std::is_rvalue_reference_v<decltype(a)><<std::endl; 
// }

// void func2(int&& a){
//     std::cout<<"left reference:"<<std::is_lvalue_reference_v<decltype(a)><<std::endl; 
//     std::cout<<"right reference:"<<std::is_rvalue_reference_v<decltype(a)><<std::endl; 
// }

// template<typename T>
// void func(T&& a)
// {
//     std::cout<<"left reference:"<<std::is_lvalue_reference_v<decltype(a)><<std::endl; 
//     std::cout<<"right reference:"<<std::is_rvalue_reference_v<decltype(a)><<std::endl; 
//     func2(a);
// }

// const int cdata = 10;

// int main()
// {
//     int a = 10;
//     int& b = a;
//     int&& c = std::move(a);

//     auto&& e = 10;
//     e = 8;
//     int& f = b;
//     int& g = c;
//     func2(10);
//     const int& rdata = cdata;

//     return 0;
// }

/* ------------------------------ const ------------------------------ */

class Gameplayer{
public:
    static const int num = 2;   
    int scors[num];
    void game_play()
    {
        const int& data = num;
    }
};

int main()
{
    
    const int data = 1;
    // data = 2; 错误
    // const int data2; 错误
    // int* pdata = &data; 错误
    extern const int data2;
    // extern const int data2 = 2;错误
    constexpr int mf = 2;
    int a;
    // constexpr int mf2 = a; 验证失败
    /* constexpr是顶层级别修饰，涉及到指针时，只修饰指针，而不能作用于指针指向的对象 */

    const int num = 7;
    int scores[num];
    Gameplayer game();
    
    

}

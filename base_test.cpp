# include <iostream>
# include <functional>
# include <algorithm>
# include "base_test.h"
# include "toos.h"

using namespace std;

void func1(int &p)
{
    print(p);
}

void func2(int x, int y) 
{
    std::cout << x << " " << y << std::endl;
}

void func3(std::ostream& os, int value) 
{
    os << value << std::endl;
}

void base_test()
{
    cout << "开始基础测试" << endl;

/*
    int a = 3;
    int &b = a;
    int &c = b;
    c = 100;
    print(a, b, c);     // 100 100 100
    print(&a, &b, &c);  // 0x7fff52b24e44 0x7fff52b24e44 0x7fff52b24e44

    print("==========");

    double d = 23.33;
    double &a = d;
    print("==========");

    int a = 3;
    print(std::ref(a));

    int value = 42;
    auto bound_print = std::bind(func1, std::ref(value));
    bound_print();
    print("==========");


    // 新对象bound_print的第一个参数传递给func2的第二个参数
    auto bound_print = std::bind(func2, 10, std::placeholders::_1); 
    bound_print(123);   // 10 123
    

    std::ostream& os = std::cout;
    auto bound_print = bind(func3, ref(os), 42);
    bound_print();
    print("==========");
*/

    cout << "完成基础测试" << endl;
}
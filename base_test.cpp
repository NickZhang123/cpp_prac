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
    cout << "base_test start" << endl;

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

    double d = 3.14;
    int i = static_cast<int>(d);  
    print(i);

    class Base {};
    class Derived : public Base {};
    Base* b = new Derived();
    Derived* d1 = static_cast<Derived*>(b);     // 向下转换
*/

    cout << "base_test end" << endl;
}


class Base {
public:
    virtual ~Base() = default;  // 启用 RTTI
};

class Derived : public Base {};

void func4(const int* ptr) 
{
    int* non_const_ptr = const_cast<int*>(ptr); // 去除 const 限定符
    *non_const_ptr = 20;                        // 修改值
}

int base_test2() 
{
    cout << "base_test2 start" << endl;
    Base* basePtr = new Derived;
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr != nullptr) {
        std::cout << "Conversion successful\n";     // here
        delete basePtr;
    } else {
        std::cout << "Conversion failed\n";
    }
    
    Base* basePtr2 = new Base();
    Derived* derivedPtr2 = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr2 != nullptr) {
        std::cout << "Conversion successful\n";
        delete derivedPtr2;
    } else {
        std::cout << "Conversion failed\n";         // here
    }
    

    const int a = 10;
    func4(&a);                      // 警告：修改了常量对象
    std::cout << a << std::endl;    // 输出 20 (未定义行为)

    cout << "base_test2 end" << endl;
    return 0;
}
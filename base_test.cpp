# include <iostream>
# include <functional>
# include <algorithm>
# include <vector>
# include <cstdarg>
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

void base_test2() 
{
    cout << "base_test2 start" << endl;
/*
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
*/
    cout << "base_test2 end" << endl;
}

void func5(int a)
{
    cout << a << " ";
}

void base_test3() 
{
    cout << "base_test3 start" << endl;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), func5);
    cout << endl;

    for_each(vec.begin(), vec.end(), [](int a){ cout << a << " ";});
    cout << endl;

    print(sizeof(int), sizeof(short), sizeof(long), sizeof(long long));
    print(sizeof(unsigned int), sizeof(unsigned short), sizeof(unsigned long), sizeof(unsigned long long));

    print(sizeof(float), sizeof(double), sizeof(long double)); // 4 8 16
    print(sizeof(char), sizeof(wchar_t));
    cout << "base_test3 end" << endl;
}

void func6(int a = 1, int b = 2)
{
    cout << a << " " << b << endl;
}

void func7(int b, int a = 1)
{
    cout << a << " " << b << endl;
}

void print_var(const char* format, ...) {
    va_list args;               // 1. va_list用于存储参数列表
    va_start(args, format);     // 2. va_start初始化va_list
    
    const char* ptr = format;
    while (*ptr) {
        if (*ptr == '%') {      // 解析格式化参数
            ++ptr;
            if (*ptr == 'd') {  
                int i = va_arg(args, int);                      // 3. va_arg 访问参数
                std::cout << i << " ";
            } else if (*ptr == 'f') {
                double d = va_arg(args, double);                // va_arg 访问参数
                std::cout << d << " ";
            } else if (*ptr == 's') {
                const char* s = va_arg(args, const char*);      // va_arg 访问参数
                std::cout << s << " ";
            }
        }

        ++ptr;
    }
    
    va_end(args);           // 4. va_end 结束处理。
    std::cout << std::endl;
}

void func9(int value, void (*func)(int));

void func9(int value, void (*func)(int)) 
{
    func(value);
}

void func8(int x) {
    std::cout << x << std::endl;
}


template<typename T>
void print_var2(T t)        // 相当于递归的退出条件
{
    cout << t << endl;
}

// 第一个参数类型为T，后续参数类型形成可变模版ARGS
template<typename T, typename... ARGS>      // 变长模版格式 typename... ARGS
void print_var2(T first, ARGS... args)      // 可变参数格式 ARGS... args
{
    cout << first << " ";
    print_var2(args...);                    // 可变参数被使用的格式 args...
}

// 模板函数，接受任意数量的参数
template <typename... Args>
void print_var3(Args... args) {
    // 折叠表达式(将args中的元素逐个引用cout，即输出，中间没有空格)
    // (std::cout << ... << args) << std::endl; 

    // 输出空格, 这种格式是将args中的参数逐个引用在表达式 cout << " " << args中
    // ((std::cout << " " << args), ...) << std::endl; // 折叠表达式

    // 输出空格，且第一个元素不输出空格
    //  (first ? (first = false, "") : " ")  三元运算处理第一个输出"", 后续元素输出空格
    bool first = true;
    ((std::cout << (first ? (first = false, "") : " ") << args), ...) << endl;
}

void func10(int a, int b)  
{
}
int func11(int a)
{
    cout << a << " ";
    return a;
}

void base_test4()
{
    // 默认参数测试
    func6();            // 1 2
    func6(10);          // 10 2
    func6(10, 20);      // 10 20
    
    // 函数作为参数
    func9(100, func8);  // 100
    func9(101, [] (int val) { cout << val << endl;});   // 101

    // 可变参数测试
    print_var("%d, %f, %s", 4, 3.3, "stringTest");
    print_var("%d, %f, %s", 4, 3.3, "stringTest", 3, 4);
    print_var2(4, 3.3, "stringTest");
    print_var3(4, 3.3, "stringTest", 'c', "test");  // 4 3.3 stringTest c test201703
    
    // 参数构造顺序
    func10(func11(1), func11(12));  // 12 1 
    cout << endl;
    // c++版本
    auto VER = __cplusplus;
    print(VER);

}


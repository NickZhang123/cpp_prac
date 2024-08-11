# include <iostream>
# include <cstring> 
# include "toos.h"
# include "class_test.h"

using namespace std;

MyClass::MyClass() : len(10)
{
    cout << "MyClass()" << endl;
    p_data = new int[len];
}

MyClass::~MyClass()
{
    cout << "~MyClass()" << endl;
    delete []p_data;
}

MyClass::MyClass(const MyClass &cls)
{
    cout << "MyClass(const MyClass &)" << endl;
    len = cls.len;
    p_data = new int[len];
    memcpy(p_data, cls.p_data, len);
}

MyClass& MyClass::operator=(const MyClass &cls)
{
    cout << "MyClass::operator=(const MyClass &cls)" << endl;
    // 1. 自我赋值检查
    if (this == &cls) {
        return *this;
    }

    // 2. 释放旧资源
    if (p_data != nullptr) {
        delete []p_data;
    }

    // 3. 进行深拷贝(c++11以后可以进行move)
    p_data = new int[len];
    memcpy(p_data, cls.p_data, len);

    // 4. 返回对象自身，提供链式赋值
    return *this;

}

void MyClass2::AccessCls(const MyClass &cls)
{
    cout << cls.len << endl; 
}

void friend_func(const MyClass &cls)
{
    cout << cls.len << endl;    // 友元函数访问类中私有变量
}

void test_cls()
{    
    MyClass cls;                    // 构造
    MyClass cls2 = cls;             // 拷贝构造
    MyClass cls3;                   // 构造
    cls3 = cls;                     // 赋值拷贝

    friend_func(cls);
    MyClass2().AccessCls(cls2);


    MyPair<int, int> p1(1, 2);
    print(p1.getFirst(), p1.getSecond(), p1.add(3, 4));
    MyPair<int, string> p2(222, "str");
    print(p2.getFirst(), p2.getSecond(), p2.add(3, 4));
}


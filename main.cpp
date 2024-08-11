#include <iostream>
#include <vector>
#include <cstdio>
#include "base_test.h"
#include "class_test.h"
#include "inherit_test.h"

using namespace std;

int main()
{
    // cout << "hello world" << endl;

    // 基础测试
    //base_test();        // 引用，指针，bind
    //base_test2();       // 结构控制，类型转化，运算符
    //base_test3();       // 数据类型
    //base_test4();       // 函数参数
    //base_test5();       // 函数返回值，重载

    // 类相关
    //test_cls();

    // 继承相关
    test_inherit();     // 继承，多重继承，菱形继承，虚继承

    return 0;
}

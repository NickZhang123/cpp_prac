#include <iostream>
#include <vector>
#include <cstdio>
#include "base_test.h"

using namespace std;

int main()
{
    cout << "hello world" << endl;

    vector<int> vi;
    vi.push_back(1);

    void *p = NULL;
    printf("%p\n", p);

    base_test();        // 引用，指针，bind
    base_test2();       // 结构控制，类型转化，运算符
    base_test3();

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdio>
#include "base_test.h"
#include "class_test.h"
#include "inherit_test.h"
#include "cpp11_test.h"
#include "cpp14_test.h"
#include "cpp17_test.h"
#include <unistd.h>
#include <sys/wait.h>
#include <deque>

using namespace std;

static int testval;

void test_fork()
{
    pid_t pid = fork();
    if(pid == 0) {          // 子进程
        printf("I am child, my pid = %d, my parent pid = %d\n", getpid(), getppid());
    } else if(pid > 0) {    // 父进程
        printf("I am parent, my pid = %d, my child pid = %d\n", getpid(), pid);
        wait(NULL);         // 等待子进程退出
    } else {
       perror("fork error!\n");
    }
}

void test_deque()
{
    deque<int> de = {1,2,3,4,5,6,7,8,9,10};
    cout << "de.front: " << de.front() << endl;
    for (auto &&i : de) {
        cout << i << endl;
    }

}

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
    //test_inherit();     // 继承，多重继承，菱形继承，虚继承

    // cpp11测试
    // cpp11_test();
    // cpp11_concurrent();

    // 异步测试
    //test_async();

    //cpp14_test();
    cpp17_test();

    //test_fork();
    //test_deque();

    //cout << testval << endl;

    return 0;
}

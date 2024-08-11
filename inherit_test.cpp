# include <iostream>
# include "inherit_test.h"
# include <memory>


void test_memalloc()
{
    allocator<Base> alloc;
    int cnt = 5;
    Base *p = alloc.allocate(cnt);          // 分配内存，指定对应模版数量即可
    
    for (int i = 0; i < cnt; i++) {
        if (i > 3) {
            alloc.construct(p + i);         // 使用默认无参构造函数
        } else {
            alloc.construct(p + i, 666);    // 使用参数333作为构造函数入参，则会调用有参的构造函数
        }
    }

    for (int i = 0; i < cnt; i++) {
        alloc.destroy(p + i);               // 调用对象的析构函数
    }

    alloc.deallocate(p, cnt);               // 释放内存
}

void test_inherit()
{   
    // 构造顺序测试
    //base2 b;
    // base2 b(2);

    // 内存分配测试
    //test_memalloc();
    //Derived dev;

    // 虚函数表测试
    
}

# include <iostream>
# include "inherit_test.h"
# include <memory>
# include "toos.h"


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
    //Base *p = new Derived();
    //p->Print();

    // print(sizeof(Base));

    using Fn = void(*)();

    Base b(333);
    cout << sizeof(Base) << endl;       // 16，包含一个虚汗是表指针8， 一个int成员4， 然后8对齐，形成16
    cout << sizeof(Derived) << endl;    // 24, 包含一个虚汗是表指针8， 一个基类int4， 两个子类int8， 对齐后24
/*
    // 将b地址转化为int指针类型并取值，目的是要取出虚函数表地址
    // 因为地址是指针，可能占用8字节空间，这里使用int4字节不一定正确
    int addr = *(int *)(&b);
    
    // 取虚函数表的第一个指针偏移，即第一个函数 
    Fn f1 = (Fn)(*(int *)addr);  
    f1();                                       // Base::Print
    f1 = (Fn)(*(int *)(*(int *)(&b)));          // 直接转换，Base::Print
    f1(); 


    // 取虚函数表第二个指针偏移，因为指针大小是8，这里偏移两个int
    Fn f2 = (Fn)(*((int *)addr + 2));  
    f2();                                       // Base::Print2
    f2 = (Fn)(*((int *)(*(int *)(&b)) + 2));    // Base::Print2
    f2(); 
*/
    // 先将对象转化为三级指针（第一级指针的解引用取虚函数表地址，后面两级指针形成虚函数表的数组表达形式）
    // 好处：1. 对三级指针的解引用获取指针数组格式的二级指针； 
    //      2. 解引用大小取决于解引用的类型，这里类型是void**, void**的大小依然是指针大小，这里是8字节，
    //          相当于对内存中第一个8字节进行解析，即内存中虚函数表指针的解析
    void **table = *(void ***)&b;

    // 直接利用指针数组格式的方式将元素转化为函数指针进行访问
    Fn f3 = (Fn)table[0];   
    f3();
    Fn f4 = (Fn)table[1];
    f4();





}

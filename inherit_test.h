# include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "Base" << endl; }
    Base(int data) { cout << "Base" << " " << data << endl; }
    virtual ~Base() { cout << "~Base" << endl; }

    virtual void Print() { cout << "Base::Print" << endl; } 
private:
    int data;
};

class Derived : public Base {
public:
    Derived() { cout << "Derived" << endl; }
    ~Derived() { cout << "~Derived" << endl; }

    void Print() override { cout << "Base::Print" << endl; } 
};


class b {
public:
    b() { cout << "b" << endl; }
    b(int a) { cout << "b int" << endl; }
    ~b() { cout << "~b" << endl; }
};

class base {
public:
    base() {cout << "base" << endl; }
    base(const base &b) { cout << "base&" << endl; }  
    base(int a) { cout << "base int" << endl; }
    ~base() { cout << "~~base" << endl; }
    base &operator=(const base&b) { cout << "operator" << endl; return *this; }
};

class base2 : public b {
public:
    base2() { cout << "base2" << endl; }
    base2(int a) : b(a) 
    {
        cout << "base2 int" << endl;
        b = a;
    }
    ~base2() { cout << "~~base2" << endl; }
    base b;
};



void test_inherit();
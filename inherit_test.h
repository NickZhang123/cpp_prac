# include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "Base" << endl; }
    Base(int data): _data(data) { cout << "Base" << " " << data << endl; }
    
    virtual void Print() { cout << "Base::Print" << endl; } 
    virtual void Print2() { cout << "Base::Print2" << endl; } 

    virtual ~Base() { cout << "~Base" << endl; }
    
private:
    int _data;
};

class Derived : public Base {
public:
    Derived() { cout << "Derived" << endl; }
    ~Derived() { cout << "~Derived" << endl; }

    void Print() override { cout << "Derived::Print" << endl; } 
private:
    int _data_de;
    int _data_de2;
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
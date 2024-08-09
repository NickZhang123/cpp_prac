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

    base_test();

    return 0;
}

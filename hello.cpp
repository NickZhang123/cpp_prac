#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    cout << "hello world" << endl;

    vector<int> vi;
    vi.push_back(1);

    void *p = NULL;
    printf("%p\n", p);

    return 0;
}

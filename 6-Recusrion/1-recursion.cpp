// Printing from n till 1
#include <iostream>
using namespace std;

void printNum(int n)
{
    if (n == 1)
    {
        cout << "1" << " ";
        return;
    }
    cout << n << " ";

    printNum(n - 1);
}

int main()
{
    printNum(4);
    return 0;
}
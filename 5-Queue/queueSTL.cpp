#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    queue<int> q;
    stack<int> s;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<"->";
        q.pop();
    }
    // for (int val : q)                                        
    // {
    //     cout << val << " ";
    // }
    // You cannot iterate over std::queue using a range-based for loop std::queue does not support iterators because it is based on a FIFO (First-In-First-Out) structure, and it does not expose its internal container.

    cout << "NULL" << endl;
    return 0;
}
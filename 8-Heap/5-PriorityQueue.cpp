#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int>p;           //max heap


    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout<<p.top()<<" ";

    //Delete
    p.pop();

    cout<<"\nAfter Poping\n";
    cout<<p.top()<<" "; 

    cout<<"SIE: ";
    cout<<p.size()<<endl;

    //FOR PRINTING
    while(!p.empty())             
    {
        cout<<p.top()<<" ";
        p.pop();
    }


    cout<<"---FOR MIN HEAP---"<<endl;
    priority_queue<int, vector<int> , greater<int>> pm;          //just this part different all other same as MAX HEAP

    
    pm.push(10);
    pm.push(20);
    pm.push(11);
    pm.push(18);
    pm.push(15);

    cout<<pm.top()<<" ";

    //Delete
    pm.pop();

    cout<<"\nAfter Poping\n";
    cout<<pm.top()<<" "; 

    cout<<"SIE: ";
    cout<<pm.size()<<endl;

    //FOR PRINTING
    while(!pm.empty())             
    {
        cout<<pm.top()<<" ";
        pm.pop();
    }

}


#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int main()
{

 vector<int> arr={6,8,0,1,3};

 stack<int> s;
 vector<int> ans(arr.size(),0);

 for(int i=arr.size()-1;i>=0;i--){
while (s.size()>0 && s.top()<=arr[i])
{
    s.pop();
}
if(s.empty()){
    ans[i]=-1;
}
else{
    ans[i]=s.top();
}

s.push(arr[i]);

 };

 for(int val:ans){
    cout<<val<<" ";
 }
 cout<<endl;
 return 0;

};
// We start from the rightmost element and move left.
// For each arr[i]:
// Remove all elements from the stack that are ≤ arr[i] (since they are useless for finding NGE).

// The stack only keeps elements that could be the next greater element for upcoming values.
// It removes smaller elements (since they can never be the next greater element).
// So, after removing smaller elements, the top of the stack (s.top()) is always the nearest greater element for arr[i].
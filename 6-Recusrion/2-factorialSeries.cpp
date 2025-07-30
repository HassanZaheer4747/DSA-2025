#include<iostream>
using namespace std;
int factorial(int n){

    if(n==0 || n==1){                           //base case:already known answer
        return 1;
    }

    return n*factorial(n-1);
}

int main(){
    cout<<factorial(4)<<endl;
    return 0;
}

// _________________________TIME COMPLEXITY_____________________________
// 1-Recursion relation
// 2-TC(time complexity)=total no of recursion call * Work in each call  [prefered]

//---Fro Factorial---
// TC=n[rec call=n+1 but in o() we ignore constant(1)]*o(1)[operations like +,-,*./ are constant time o(1)]
// TC=n*o(1)=o(n)


// _______________________SPACE COMPLEXITY______________________________
// 1-SC=Depth of recursion tree*memory in each call
// 2-SC=height of CallStack*memory in each call

// ---For Factorial---
// SC=n*k
// SC=o(n)---->depends upon depth of stack         (no extra var used in fun so that why)
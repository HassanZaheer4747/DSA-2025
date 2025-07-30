//    To Calculate the nth term in Fibonachi Series
#include <iostream>
using namespace std;
// 0 1 1 2 3 5 8 13        sixth fibonachi term:8          FORMULA(to calculate nth fibonachi term) : tn=tn-1+tn-2
int fibonachi(int n)
{
    if(n==1 || n==0){                //base case: for n=1,n=0 the fibonachi term 
        return n;
    }
   
   return fibonachi(n-1)+fibonachi(n-2);
}

int main()
{
    cout<<fibonachi(6);
    return 0;
}

// ______________Time Complexity_________________
// TC=total no of calls *  work done in each call
// TC=(2power(n) -1)*K    ==>o(2power(n))                         :This is exponential time complexity

// we can use dynamic programing for optimum Time complexity [o(n)]


#include<iostream>
using namespace std;
int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

int main(){
    cout<<sum(5)<<endl;              //for 4:4+3+2+1=10
    return 0;
}
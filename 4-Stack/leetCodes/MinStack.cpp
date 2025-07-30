#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class MinStack
{
    public:
    stack<pair<int,int>> s;

    void push(int val){
        if(s.empty()){
       s.push({val,val});
        }
        else{
            int minval=min(val,s.top().second);
            s.push({val,minval});
        }
    }

    void pop(){
if(!s.empty()){
    s.pop();
}
    }

    int top(){
   return s.top().first;
    }

    int getmin(){
       return s.top().second;
    }

    void prnt(){
    //    for(int i=0;i<=s.size()-1;i++){
    //         cout<<"value:"<<s.top().first<<"MinStack:"<<s.top().second<<endl;
    //     }   
//     Stacks do not work like arrays.
// s.top() always returns the same top element unless you pop(), so your loop keeps printing the same element over and over. 

stack<pair<int,int>> copy=s;
while(!copy.empty()){
    cout<<"value:"<<copy.top().first<<" MinStack:"<<copy.top().second<<endl;
    copy.pop();   // Remove the top element from the copy
}
    }
};

int main(){
    MinStack st;
    st.push(4);
    st.push(2);
    st.push(1);

    st.pop();

    st.prnt();

    cout<<"min value :"<<st.getmin()<<endl;
}



#include<iostream>
#include<vector>
using namespace std;
vector<char> alphabets={'a','b','c','d','e'};
void prntVector(){
    for(char val:alphabets){                                        //foreach:i stors values of each element in vector
        cout<<val<<endl;
    }
}
int main(){
   prntVector();   cout<<endl;

    cout<<"size="<<alphabets.size()<<endl;

    alphabets.push_back('f');
  prntVector();   cout<<endl;
  
    alphabets.pop_back();
   prntVector();    cout<<endl;

   cout<<alphabets.front()<<endl;
   cout<<alphabets.back()<<endl;

   cout<<alphabets.at(3);             //to find at particular indx

}


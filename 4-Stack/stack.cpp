#include <iostream>
#include <vector>
using namespace std;

// class Stack
// {
//     vector<int> v;

// public:
//     void push(int val)
//     {
//         v.push_back(val);
//     }

//     void pop()
//     {
//         v.pop_back();
//     }

//     int top()
//     {
//         return v[v.size() - 1];
//     }

//     bool empty()
//     {
//         return v.size() == 0;
//     };

// };

// int main()
// {
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     while (!s.empty())
//     {
//      cout<<s.top()<<" ";
//      s.pop();
//     }
//     cout<<endl;  //30 20 10
//     return 0;
// }

// class StackTwo{

//     public:
//   int Stack[5];
//   int top=-1;

//   void pushtop(int x){
//     if(top==4){
//        cout<<"overflow condition";
//     }
//     else{
//         top++;
//         Stack[top]=x;
//     }
//   }

//   void poptop(){
//         int item;
//         if(top==-1){
//             cout<<"underflow";
//         }
//         else{
//             item=Stack[top];                             //for storing element if you want before doing top-- because then it will be lost (garbage value)
//             top--;
//             cout<<"the poped item is: "<<item;
//         }
//   }

//   void Top(){
//        if(top==-1 || top==4){
//         cout<<"underflow or Stackis full";
//        }
//        else{
//                 cout<<"the top most element in stacck is:"<<Stack[top];
//        }
//   }

//   void print(){
//     if(top==-1 || top==4){
//         cout<<"Not inside stack";
//     }
//     // cout<<Stack[top];
//     // top--;
//     for(int i=top;i>=0;i--){
//         cout<<Stack[i]<<" ";
//     }

//   }

// };
// int main(){
//     StackTwo e;
//     e.pushtop(1);
//     e.pushtop(2);
//     e.pushtop(3);

//     e.print();

//     e.Top();

//     return 0;
// }

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class StackLL
{
    Node *head;
    Node *tail;

public:
    StackLL()
    {
        head = tail = NULL;
    }

    void Push(int val){
        Node* newNode=new Node(val);
           if(head==NULL){
            head=tail=newNode;
           }
           else{
            newNode->next=head;
            head=newNode;
           }
    }

    void Pop(){
        if(head==NULL){
            cout<<"Stack is empty";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void top(){
        if(head==NULL){
            cout<<"Stack is empty NO top to return";
            return;
        }
        else{
            cout<<"THE top of stack is"<<head->data;
        }
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    StackLL Stack;
    Stack.Push(1);
    Stack.Push(2);
    Stack.Push(3);
    Stack.print();
    cout<<endl;

    Stack.Pop();
    Stack.print();
    cout<<endl;

    Stack.top();

}

#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;

    Node(int val){
         data=val;
         next=NULL;
    }
};
class QueueLL{
     Node* head;
     Node* tail;
public:
     QueueLL(){
        head=tail=NULL;
     }

     void push(int val){
            Node* newnode=new Node(val);
            if(head==NULL){
                head=tail=newnode;
            }
            else{
                Node*temp =head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newnode;
                tail=newnode;
            }
     }

     void pop(){
        if(head==NULL){
            cout<<"nothing to delete"<<endl;
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
        Node* temp=head;
        head=head->next;
        delete temp;}
     }
     void  top(){
        if(head==NULL){
            cout<<"empty Queue"<<endl;
            return;
        }
        else{
            cout<<"The TOP of our QUEUE IS: "<< head->data<<endl;;
        }
     }
     void print(){
        if(head==NULL){
            cout<<"empty"<<endl;
        }
        else{
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        }
     }


};

int main(){
QueueLL queue;
queue.push(1);
queue.push(2);
queue.push(3);
queue.print();

queue.pop();
queue.print();

queue.top();
};
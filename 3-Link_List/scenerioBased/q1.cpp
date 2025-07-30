#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node* prev;
    int Orderid;
    string customerName;

    Node(int id, string name)
    {
        prev=NULL;
        next = NULL;
        Orderid = id;
        customerName = name;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void addOrder(int id, string name)
    {
        Node *newnode = new Node(id, name);

        if (head == NULL)
        {
            head=tail=newnode;
        }
        // else{
        //     Node *temp=head;
        //     while(temp->next!=NULL){
        //         temp=temp->next;
        //     }
        //     temp->next=newnode;
        // }
        tail->next = newnode;
        tail = newnode;
    }

    void delOrder(int id)
    {
        if (head == NULL)
        {
            cout << "No order till now to delete" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            Node *tempprev = NULL;
            while ( temp!=NULL && temp->Orderid != id )
            {
                tempprev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            { // order not found
                cout << "Order ID " << id << " not found." << endl;
                return;
            }
            if (tempprev == NULL)
            { // if node to del is head
                head = head->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }
            delete temp;
        }
    }

    void displayOrder(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<"order ID:"<<temp->Orderid<<" Customer Name:"<<temp->customerName<<endl;
            temp=temp->next;
        }
    }

    void coutorder(){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        cout<<"the total no of active orders are :"<<count<<endl;
    }

    void insertMiddle(int id,string name,int pos){
       
        if(pos<0){
            cout<<"Invalid Position";
            return;
        }
        if(pos=0){
            Node* newnode=new Node(id,name);
            newnode->next=head;
            head=newnode;
        }
        
        Node* newnode=new Node(id,name);
        Node* temp=head;
       for(int i=0;i<pos-1;i++){
        if(temp==NULL){
            cout<<"INVALID POSITION!!!"<<endl;
        }
        temp=temp->next;
       }
       newnode->next=temp->next;
    }
};

int main()
{
   List FoodDeliveryApp;
   FoodDeliveryApp.addOrder(1, "Hassan");
   FoodDeliveryApp.addOrder(2, "Ahmad");
   FoodDeliveryApp.addOrder(3, "Ali");
   
   FoodDeliveryApp.displayOrder();
   FoodDeliveryApp.delOrder(2);
   FoodDeliveryApp.displayOrder();
   FoodDeliveryApp.coutorder();

   FoodDeliveryApp.displayOrder();
    return 0;
}
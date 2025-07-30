// _______________________________________LEET_CODE 876_______________________________________ 
// Find Middle of Even and Odd LL
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    public:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // ---------------------REverse LIST-------------------
    void ReverseList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
       head=prev;
    }
// ---------------------------------------------------------
    void Print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<< temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};

int main()
{
    List Li;
    Li.push_front(2);
    Li.push_front(3);
    Li.push_front(4);
    Li.Print();
    cout<<endl;

    Li.ReverseList();
    Li.Print();

    
    return 0;
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLL {
    Node *head;
    Node *tail;

public:
    DoublyLL() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;  
        head = newNode;
    }

 
    void push_back(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // -----BY using head-----
        Node* temp=head;
        while (temp->next != NULL) {  
            temp = temp->next;
        }
        
        temp->next = newNode;  
        newNode->prev = temp;  
        tail = newNode; 
        
        //-----BY using tail-----  
        // tail->next = newNode;
        // newNode->prev = tail;
        // tail = newNode;
    }

    void insertMiddle(int val,int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){            //0(temp)-->newNode-->1(temp2)--->2-->3-->4        insertMiddle(4747,int 1) 
            temp=temp->next;
        }
       Node* temp2=temp->next;
       temp->next=newNode;
       newNode->prev=temp;
    //    newNode->next=temp2;             //if use this for inserting at last position will give errors
    //    temp2->prev=newNode;
       if (temp2 != NULL) {         //If temp2 is NOT NULL, that means there is another node after newNode. If temp2 IS NULL, that means newNode is the last node in the list.
        newNode->next = temp2;
        temp2->prev = newNode;
    } else {
        tail = newNode;  // If inserting at last position, update tail
    }
   }

   void pop_back() {
    if (head == NULL) return;  // If the list is empty, do nothing

    if (head->next == NULL) {  // If only one node is present
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {  // ✅ Traverse until last node
        temp = temp->next;
    }

    Node* temp2 = temp->prev;  // Store second last node
    temp2->next = NULL;  // Disconnect last node
    delete temp;  // Delete last node
}


    void printLL() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLL Dll;
    Dll.push_front(1);
    Dll.push_front(0);
    Dll.push_front(-1);
    Dll.push_back(2);
    Dll.printLL();
    cout<<endl;
    Dll.insertMiddle(3,4);
    Dll.printLL();
    cout<<endl;

    // Dll.pop_back();
    // Dll.printLL();

    return 0;
}


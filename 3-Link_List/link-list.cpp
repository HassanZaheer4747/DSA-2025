// ------push_front, push_back,pop_front,pop_back,inser_middel,Search(key),deleteNode(indx),printLL-------
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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // new Node(10):creates a node on the heap   newNode:this pointer holds the memory address of the newly created node.
        // Node newNode(val);                  //This creates the node on the stack, not the heap.
        // The node gets destroyed automatically when the function ends.
        // If push_front ends, the newNode will disappear, and head will point to an invalid memory location.
        //  CONCLUSISON:we dont want static implimentation so we use NEW keyword
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; //->this dereference the newNode pointer  so we can acess its attributes(next)
            // next is pointer and head is pointer we give newNode next pointer the address of head pointer that was previously 1st pointer.so now newNode contain address of previous 1st pointer
            //  (*newNode).next=head;       same as above internal implimentation is like that but we write in short form
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }

        //    BY using head pointer only
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode; // due to while loop temp->next will be at last node as we have given codition to run till null is achived and new node is node we have created
            tail = newNode;
        }
        // We don’t want temp to become NULL (we can’t access NULL->next).
        // Instead, we want temp to stop right before the last node, so we can attach newNode.

        // by using tail
        // else{
        //     tail->next=newNode;
        //     tail=newNode;
        // }
    }

    void pop_front()
    {

        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {

        if (head == NULL)
        {
            cout << "LL is empty\n";
            return;
        }

        Node *temp = head;
        //  BY USING HEAD ONLY
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;

        //       BY USING TAIL AND HEAD
        //      while(temp->next!=tail){
        //         temp=temp->next;
        //      }
        //      temp->next=NULL;
        //      delete tail;
        //      tail=temp;
        // }
    }

    void inser_middel(int val, int pos)
    {

        if (pos < 0)
        {
            cout << "Invalid Position!!\n";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp = NULL)
            {
                cout << "Invalid Position!!\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int Search(int key)
    {
        if (head = NULL)
        {
            cout << "LL isempty\n";
        }
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }
            // else{                                        // // Problem: This prints "Node not found" every time key is not found at current node
            //     cout<<"Node not Found\n";
            // }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void deleteNode(int indx)
    {
        if (head == NULL)
        {
            cout << "LL is empty \n";
            return;
        }
    
        if (indx == 0)
        {
            Node *temp = head;
            head = head->next;
            if (head == NULL) // If we deleted the last node, update tail
            {
                tail = NULL;
            }
            delete temp;
            return;
        }
    
        Node *temp = head;
        for (int i = 0; i < indx - 1; i++)
        {
            if (temp == NULL || temp->next == NULL)
            {
                cout << "Invalid index!\n";
                return;
            }
            temp = temp->next;
        }
    
        Node *tempdel = temp->next;
        if (tempdel == NULL) // Edge case: If deleting a non-existent node
        {
            cout << "Invalid index!\n";
            return;
        }
    
        temp->next = tempdel->next;
    
        if (tempdel == tail) // If deleting last node, update tail
        {
            tail = temp;
            tail->next = NULL;
        }
    
        delete tempdel;
    }
    


    // void deleteNode(int indx)
    // {
    //     if (head == NULL)
    //     {
    //         cout << "LL is emty \n";
    //         return;
    //     }
    //     if (indx == 0)
    //     {
    //         if(head==NULL){
    //             tail==NULL;
    //         }
    //         Node *temp = head;
    //         if(head==NULL){
    //             tail==NULL;
    //         }
    //         head = head->next;
    //         delete temp;
    //         return;
    //     }

    //     Node *temp = head;
    //     for (int i = 0; i <indx - 1; i++)
    //     {
    //         if (temp == NULL || temp->next == NULL)
    //         { // Check if index is out of bounds
    //             cout << "Invalid index!\n";
    //             return;
    //         }
    //         temp = temp->next;
    //     }
    //     Node *tempdel = temp->next;
    //     temp->next = tempdel->next;
    //     delete tempdel;
    // }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    List li;

    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.printLL();
    cout << endl;

    li.push_back(4);
    li.push_back(5);
    li.printLL();
    cout << endl;

    li.pop_front();
    li.printLL();
    cout << endl;

    // li.inser_middel(6, 2);
    // li.inser_middel(8, 0);          //******MEMORY ERROR*****
    // li.printLL();

    cout << li.Search(8);
    cout << endl;

    li.deleteNode(2);
    li.printLL();

    // li.pop_back();
    // li.printLL();
    return 0;
};
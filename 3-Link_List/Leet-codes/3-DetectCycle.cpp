// _______________________________________LEET_CODE 141,142_______________________________________
// (1) Find if there is any Cycle(Loop) in LL      (2)find Node where Cycle begin
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

    // ---------------------Detect Cycle in LL-------------------
    bool DetectCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    // ---------------------------------------------------------


     // ---------------------Return Node where Cycle begin-------------------
    Node *NodewhereCycleBegin()
    {
        Node *slow = head;
        Node *fast = head;
        bool iscycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                iscycle = true;
                break; // Stop the loop as we already confirmed the cycle.No break, loop keeps running
            }
        }

        if (!iscycle)
        {
            return NULL;
        }
        // A → B → C → D → E → C (Cycle Starts from C again 🔄)
      // head   cycleStart
        // The distance from the head to cycle start (C) is the same distance as from the meeting point (E) back to C.
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    // ---------------------------------------------------------

     // ---------------------Remove Node where Cycle begin-------------------
     Node *RemoveCycle()
     {
         Node *slow = head;
         Node *fast = head;
         bool iscycle = false;
         while (fast != NULL && fast->next != NULL)
         {
             slow = slow->next;
             fast = fast->next->next;
             if (slow == fast)
             {
                 iscycle = true;
                 break;                      // Stop the loop as we already confirmed the cycle.No break, loop keeps running
             }
         }
 
         if (!iscycle)
         {
             return NULL;
         }
         slow = head;
         Node* prev=NULL;
         while (slow != fast)
         {
             slow = slow->next;
             prev=fast;                     //prev stors NOde before starting point 
             fast = fast->next;
         }
         prev->next=NULL;     //remove the cycle as lst node-next beacomes NULL
     }
    //  Yes! To remove a cycle in a linked list, you first need to find the node where the cycle begins.
    //  Once you find the starting node of the cycle, you can set the next pointer of the last node in the cycle to NULL, breaking the cycle.
     // ---------------------------------------------------------
 
    void Print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    List Li;
    Li.push_front(2);
    Li.push_front(3);
    Li.push_front(4);
    Li.push_front(5);
    Li.push_front(6);

    Li.Print();
    cout << endl;

    // Creating a cycle for testing
    // Li.head->next->next->next = Li.head;  // Manually create a cycle
    cout << (Li.DetectCycle() ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}

// Yes, a cycle will never exist in your linked list unless you explicitly create one manually. Just adding more nodes using push_front() does not introduce a cycle because each new node always points to the previous head, and the last node still points to NULL.
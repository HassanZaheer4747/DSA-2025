#include <iostream>
#include <vector>
using namespace std;


class Node
{
public:
    Node *next;
    char data;

    Node(char val)
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

    void Push(char val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void Pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    char top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty NO top to return";
        }
        else
        {
            return head->data;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isvalid(string str)     //({)   first two will be added
    {
        StackLL Stack;
        for (char val : str)
        {
            if (val == '(' || val == '{' || val == '[')
            {
                Stack.Push(val);
            }
            else
            {
                if (Stack.isEmpty())
                {
                    return false;
                }

                if( (Stack.top() == '(' && val == ')')||
                        (Stack.top() == '{' && val == '}') ||
                        (Stack.top() == '[' && val == ']') )
                    {

                        Stack.Pop();
                    }
                    else{
return false;
                    }
            };
        }
        return Stack.isEmpty();                    //If the stack is empty, it means all opening brackets had a matching closing bracket → ✅ Valid parentheses → return true.
                                                   // If the stack still has elements, it means some opening brackets were not closed → ❌ Invalid parentheses → return false.
        
    }
};


int main()
{
    StackLL Stack;

   string test;
   cout<<"Enter a String of parentheses: ";
   cin>>test;

   if(Stack.isvalid(test)){
    cout << "Valid Parentheses\n";
} else {
    cout << "Invalid Parentheses\n";
}

return 0;

}

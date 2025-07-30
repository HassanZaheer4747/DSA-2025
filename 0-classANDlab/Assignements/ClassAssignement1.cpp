#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int id_data;
    string name_data;
    int execution_time_data;

    Node(int id, string name, int time)
    {
        id_data = id;
        name_data = name;
        execution_time_data = time;
        next = NULL;
    }
};

class CircularLL
{
    Node *head;
    Node *tail;

public:
    CircularLL()
    {
        head = tail = NULL;
    }

    void addJob(int id, string name, int time)
    {
        Node *newNode = new Node(id, name, time);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void deleteJob(int id)
    {
        if (head == NULL)
        { 
            cout << "NO Job to delete\n";
            return;
        }

        Node *temp = head;
        Node *tempprev = NULL;


        if (head->id_data == id)
        {
            if (head->next == head)
            { 
                delete head;
                head = NULL;
            }
            else
            {
                Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                last->next = head->next;
                temp = head;
                head = head->next; 
                delete temp;
            }
            cout << "Job " << id << " deleted\n";
            return;
        }

      
        temp = head->next;
        tempprev = head;

        while (temp != head)
        {
            if (temp->id_data == id)
            {
                tempprev->next = temp->next;
                delete temp;
                cout << "Job " << id << " deleted\n";
                return;
            }
            tempprev = temp;
            temp = temp->next;
        }

        // If the function reaches here, the node was not found
        cout << "JOB ID : " << id << " Not found!\n";
    }

    void manualDelay(int seconds) {
        for (long long i = 0; i < seconds * 1000000000; i++);  
    }
    
    void executeJob()
    {
        int cyclecount=0;
        if (head == NULL)
        {
            cout << "No jobs in the queue.\n";
            return;
        }

        Node *temp = head;
        do
        {
            cout << "Executing Job ID: " << temp->id_data << " (" << temp->name_data
                 << ") for " << temp->execution_time_data << " seconds...\n";

                 manualDelay(temp->execution_time_data);
            temp = temp->next;
            if(temp==head){
                cyclecount++;
            }
        } while (cyclecount<2);
    }

    void printCLL()
    {
        if (head == NULL)
        {
            cout << "No jobs in the queue.\n";
            return;
        }

        Node *temp = head;
        do
        {
            cout << "Executing Job ID: " << temp->id_data << " (" << temp->name_data
                 << ") for " << temp->execution_time_data << " seconds...\n";

                 manualDelay(temp->execution_time_data);
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularLL cll;
    cll.addJob(1, "one", 1);
    cll.addJob(2, "two", 2);
    cll.executeJob();

    cll.deleteJob(1);
    cout << " CLL after deleting\n";
    cll.printCLL();
};

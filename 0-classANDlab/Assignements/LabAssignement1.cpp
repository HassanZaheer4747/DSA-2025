// Scenario:
// You are designing a Task Scheduling System for a software development team working on multiple projects. The system should allow
// team members to add, update, remove, and prioritize tasks. Each task has a unique ID, description, deadline, priority level, and
// assigned team member. Tasks can be in various statuses such as "Pending," "In Progress," or "Completed."
#include <iostream>
using namespace std;
class Task
{
    public:
    Task *next;
    Task *prev;
    int id;
    string description;
    string deadline;
    int priority;
    string assignedTo;
    string status;

    Task(int _id, string _desc, string _deadline, int _priority, string _assigned, string _status)
    {
        id = _id;
        description = _desc;
        deadline = _deadline;
        priority = _priority;
        assignedTo = _assigned;
        status = _status;
        next = nullptr;
        prev = nullptr;
    }
};

class taskManager
{
    Task *head;
    Task *tail;

    void addTask(int id,string description,string deadline,int priority, string assignedTo, string status)
    {
        Task *newtask = new Task(id,description,deadline,priority,assignedTo,status);

        if(head==NULL || head->priority<priority){          //condition if the priority of newtask is highest
            newtask->next=head;
            head=newtask;
        }
        else{                                                             //2->1   add 2
            Task* temp=head;
            while (temp!=NULL && temp->next->priority>=priority)
            {
                temp=temp->next;

            }
            newtask->next=temp->next;
                temp->next=newtask;
        }
        cout<<"Task added Sucessfully!"<<endl;
    }

    void removeTask(int id){
        if(head==NULL){
               cout<<"THE LIST IS EMPTY"<<endl;
               return;
        };
        Task* temp=head;
        Task* temp2=NULL;
         // Special case: Removing the head
    if (head->id == id) {                                        //If the task to be removed is at the head, temp2 will be NULL, causing temp2->next = temp->next; to crash.
        head = head->next;
        delete temp;
        cout << "Task removed successfully." << endl;
        return;
    }

       while (temp!=NULL && temp->id!=id)
       {
        temp2=temp;
        temp=temp->next;
       }
        // If task not found
    if (temp == NULL) {
        cout << "Task not found." << endl;                          //f we reach the end of the list without finding the task,  temp->next will eventually be NULL, causing temp = temp->next to make temp = NULL.
        return;
    }
       temp2->next=temp->next;
       delete temp;
       cout<<"TASK DELETED SUCESSFULLY!"<<endl;
 }

 void updateTask(int id,int newpriority,string newdescription){
    if(head==NULL){
        cout<<"THE LIST IS EMPTY"<<endl;
        return;
 };
 Task* temp=head;


while (temp!=NULL && temp->id!=id)
{
 temp=temp->next;
}
 // If task not found
if (temp == NULL) {
 cout << "Task not found." << endl;                          //f we reach the end of the list without finding the task,  temp->next will eventually be NULL, causing temp = temp->next to make temp = NULL.
 return;
}
temp->priority=newpriority;
temp->description=newdescription;

cout<<"TASK Updated SUCESSFULLY!"<<endl;

 }

 void searchTask(int id,string description,string assignedto){
 
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Task* temp=head;
    bool found=true;
    while(temp!=NULL){
        if(temp->id==id||temp->description==description||temp->assignedTo==assignedto){
            cout << "Task Found: " << endl;
            cout << "ID: " << temp->id << ", Description: " << temp->description
                 << ", Deadline: " << temp->deadline << ", Priority: " << temp->priority
                 << ", Assigned To: " << temp->assignedTo << ", Status: " << temp->status << endl;
            found = true;  // Mark that we found a task
        }
        temp=temp->next;
    }
    if(!found){
        cout<<"TASK NOT FOUND!"<<endl;
    }
    
 }
};



int main()
{

    return 0;
}
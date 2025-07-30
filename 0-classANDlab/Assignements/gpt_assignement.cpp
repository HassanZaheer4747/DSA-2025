#include <iostream>
using namespace std;

class Task {
    public:
    Task *next;
    Task *prev;
    int id;
    string description;
    string deadline;
    int priority;
    string assignedTo;
    string status;

    Task(int _id, string _desc, string _deadline, int _priority, string _assigned, string _status) {
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

class TaskScheduler {
    private:
        Task* head;
    
    public:
        TaskScheduler() {  
            head = nullptr;
        }
    
        void addTask(int id, string desc, string deadline, int priority, string assignedTo, string status) {
            Task* newTask = new Task(id, desc, deadline, priority, assignedTo, status);
    
            if (head == nullptr) {
                head = newTask;
                return;
            }
    
            Task* temp = head;
            Task* prev = nullptr;
    
            while (temp != nullptr && temp->priority >= priority) {
                prev = temp;
                temp = temp->next;
            }
    
            if (prev == nullptr) {
                newTask->next = head;
                head->prev = newTask;
                head = newTask;
            } else {
                newTask->next = prev->next;
                newTask->prev = prev;
                if (prev->next != nullptr) {
                    prev->next->prev = newTask;
                }
                prev->next = newTask;
            }
        }
    
        void removeTask(int id) {
            Task* temp = head;
    
            while (temp != nullptr && temp->id != id) {
                temp = temp->next;
            }
    
            if (temp == nullptr) {
                cout << "Task not found.\n";
                return;
            }
    
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
    
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Task removed successfully.\n";
        }
    
        void updateTask(int id, string newDesc, int newPriority, string newStatus) {
            Task* temp = head;
            while (temp != nullptr && temp->id != id) {
                temp = temp->next;
            }
    
            if (temp == nullptr) {
                cout << "Task not found.\n";
                return;
            }

            temp->description = newDesc;
            temp->priority = newPriority;
            temp->status = newStatus;
            cout << "Task updated successfully.\n";
        }

        void searchTask(int id) {
            Task* temp = head;
            while (temp != nullptr && temp->id != id) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Task not found.\n";
                return;
            }

            cout << "Task Found - ID: " << temp->id << ", Description: " << temp->description
                 << ", Priority: " << temp->priority << ", Status: " << temp->status << endl;
        }

        void displayTasks() {
            if (head == nullptr) {
                cout << "No tasks available.\n";
                return;
            }

            Task* temp = head;
            while (temp != nullptr) {
                cout << "ID: " << temp->id << ", Description: " << temp->description
                     << ", Priority: " << temp->priority << ", Status: " << temp->status << endl;
                temp = temp->next;
            }
        }
    
        void display
        
        (string currentDate) {
            Task* temp = head;
            while (temp != nullptr) {
                if (temp->status == "In Progress" && temp->deadline < currentDate) {
                    cout << "Overdue Task - ID: " << temp->id << ", Description: " << temp->description
                         << ", Deadline: " << temp->deadline << endl;
                }
                temp = temp->next;
            }
        }
    
        void markCompleted(int id) {
            Task* temp = head;
            while (temp != nullptr && temp->id != id) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Task not found.\n";
                return;
            }

            temp->status = "Completed";
            cout << "Task marked as completed.\n";
        }
};

int main() {
    TaskScheduler manager;

    manager.addTask(101, "Resolve Backend Issue", "2024-03-25", 2, "Alice", "Pending");
    manager.addTask(102, "Implement New Feature", "2024-03-30", 5, "Bob", "In Progress");
    manager.addTask(103, "Review Codebase", "2024-03-28", 3, "Charlie", "Pending");

    cout << "Task List (Ordered by Priority):\n";
    manager.displayTasks();

    cout << "\nModifying Task 101...\n";
    manager.updateTask(101, "Fix Major Backend Issue", 4, "In Progress");

    cout << "\nLooking for Task 102...\n";
    manager.searchTask(102);

    return 0;
}

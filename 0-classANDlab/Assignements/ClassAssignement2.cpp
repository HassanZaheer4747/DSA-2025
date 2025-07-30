#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int priority; // 1 = Critical, 2 = Non-Critical
    int arrivalOrder;

    Patient(string n, int p, int a) {
        name = n;
        priority = p;
        arrivalOrder = a;
    }
};

class HospitalQueue {
private:
    vector<Patient> queue;
    int orderCounter = 0; // To track FIFO order for same priority

public:
    void addPatient(string name, string type) {
        int priority = (type == "Critical" || type == "critical") ? 1 : 2;
        Patient newPatient(name, priority, orderCounter++);

        // Insert patient in sorted position
        auto it = queue.begin();
        while (it != queue.end()) {
            if (it->priority > newPatient.priority) break;
            if (it->priority == newPatient.priority && it->arrivalOrder > newPatient.arrivalOrder) break;
            ++it;
        }
        queue.insert(it, newPatient);

        cout << "Patient " << name << " (" << type << ") added to the queue.\n";
    }

    void treatPatient() {
        if (queue.empty()) {
            cout << "No patients to treat.\n";
            return;
        }

        Patient next = queue.front();
        queue.erase(queue.begin());
        cout << "Treating patient: " << next.name
             << " (" << (next.priority == 1 ? "Critical" : "Non-Critical") << ")\n";
    }

    void showQueue() {
        if (queue.empty()) {
            cout << "The queue is empty.\n";
            return;
        }

        cout << "\nCurrent Queue:\n";
        for (Patient p : queue) {
            cout << "- " << p.name << " (" << (p.priority == 1 ? "Critical" : "Non-Critical") << ")\n";
        }
    }
};

int main() {
    HospitalQueue hq;
    int choice;
    string name, type;

    do {
        cout << "\n=== Hospital Queue Management ===\n";
        cout << "1. Add Patient\n2. Treat Patient\n3. Show Queue\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter type (Critical/Non-Critical): ";
                cin >> type;
                hq.addPatient(name, type);
                break;

            case 2:
                hq.treatPatient();
                break;

            case 3:
                hq.showQueue();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}

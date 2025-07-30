// #include<iostream>
// using namespace std;
// #include <iostream>
// using namespace std;



// struct Driver {
//     int driverID;
//     string name;
//     Driver* next;
//     Driver(int id, string n) {
//         driverID = id; name = n;
//         next = nullptr;
//     }
// };

// Driver* driverTop = nullptr;


// struct Passenger {
//     int passengerID;
//     string name;
//     Passenger* next;
//     Passenger(int id, string n) {
//         passengerID = id; name = n;
//         next = nullptr;
//     }
// };

// Passenger *passFront = nullptr, *passRear = nullptr;


// class Node
// {
// public:
//     int riderId;
//     string From;
//     string To;
//     float Fare;
//     Node *next;
//     Node(int id,string to,string from,float fare)
//     {
//         To=to;
//         From=from;
//         Fare=fare;
//         riderId = id;
//         next = NULL;
//     }
// };

// class List
// {
//     Node *head;
//     Node *tail;

// public:
//     List()
//     {
//         head = tail = NULL;
//     }


//     void push_back(int id,string to,string from,float fare)
//     {
//         Node *newNode = new Node(id,to,from,fare);

//         if (head == NULL)
//         {
//             head = tail = newNode;
//         }

    
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//             tail = newNode;
//         }
     
//     }

//     void removeRide(int id) {
//         Node *temp = head, *prev = nullptr;
//         while (temp && temp->riderId != id) {
//             prev = temp;
//             temp = temp->next;
//         }
//         if (!temp) {
//             cout << "Ride not found.\n";
//             return;
//         }
//         if (!prev) head = temp->next;         //first node to remove
//         else prev->next = temp->next;
//         delete temp;
//         cout << "Ride removed.\n";
//     }
    
//     void printLL()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout <<"ride no"<< temp->riderId <<"Details:"<<"RIDE BOOKED FOR:"<<temp->To<<" from :"<<temp->From<<" with fare :"<<temp->Fare <<endl;
//             temp = temp->next;
//         }
        
//     }

//     // FIFO
//     void addPassenger(int id, string n) {
//         Passenger* p = new Passenger(id, n);
//         if (!passRear) passFront = passRear = p;   //if the queue is empty
//         else {
//             passRear->next = p;
//             passRear = p;
//         }
//         cout << "Passenger added to queue.\n";
//     }
    
//     void viewPassengers() {
//         Passenger* temp = passFront;
//         while (temp!=NULL) {
//             cout << "ID: " << temp->passengerID << " | Name: " << temp->name << endl;
//             temp = temp->next;
//         }
//     }

//     void addDriver(int id, string name) {
//         Driver* d = new Driver(id, name);
//         d->next = driverTop;
//         driverTop = d;

//         cout << "Driver added to stack.\n";
//     }
    
// };

// int main(){
//      List smartRider;
//      smartRider.push_back(1,"hassan","ali",200);    
//      smartRider.push_back(2,"ahmad","Khan",100);
//      smartRider.printLL();
//      smartRider.removeRide(1);
//      smartRider.printLL();

//      cout<<endl;
//      smartRider.addPassenger(1,"hassan");
//      smartRider.viewPassengers();

//      cout<<endl;
// }


#include <iostream>
using namespace std;

// Driver structure (used as a stack)
struct Driver {
    int driverID;
    string name;
    Driver* next;

    Driver(int id, string n) : driverID(id), name(n), next(nullptr) {}
};

Driver* driverTop = nullptr; // Stack top for drivers

// Ride structure (Linked List node)
struct Ride {
    int rideID;
    string from, to;
    float fare;
    Ride* next;

    Ride(int id, string f, string t, float fa) : rideID(id), from(f), to(t), fare(fa), next(nullptr) {}
};

Ride* rideHead = nullptr; // Head of the ride linked list
int rideCounter = 1;

// Passenger structure (used as a queue)
struct Passenger {
    int passengerID;
    string name;
    Passenger* next;

    Passenger(int id, string n) : passengerID(id), name(n), next(nullptr) {}
};

Passenger *passFront = nullptr, *passRear = nullptr;

// Ride History structure
struct RideHistory {
    int rideID, passengerID, driverID;
    string passengerName, driverName;
    RideHistory* next;

    RideHistory(int rid, int pid, string pname, int did, string dname) {
        rideID = rid;
        passengerID = pid;
        passengerName = pname;
        driverID = did;
        driverName = dname;
        next = nullptr;
    }
};

RideHistory* historyTop = nullptr; // History stack top

// Linked List for storing rides
class RideList {
    struct Node {
        int rideID;
        string from, to;
        float fare;
        Node* next;

        Node(int id, string f, string t, float fa) : rideID(id), from(f), to(t), fare(fa), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    RideList() : head(nullptr), tail(nullptr) {}

    void addRide(int id, string from, string to, float fare) {
        Node* newRide = new Node(id, from, to, fare);
        if (!head) head = tail = newRide;
        else tail = tail->next = newRide;

        // Also add to global ride list
        Ride* r = new Ride(id, from, to, fare);
        r->next = rideHead;
        rideHead = r;

        cout << "Ride #" << id << " added successfully.\n";
    }

    void removeRide(int id) {
        Node *temp = head, *prev = nullptr;

        while (temp && temp->rideID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Ride not found.\n";
            return;
        }

        if (!prev) head = temp->next;
        else prev->next = temp->next;

        delete temp;
        cout << "Ride #" << id << " removed.\n";
    }

    void printRides() const {
        Node* temp = head;
        while (temp) {
            cout << "Ride #" << temp->rideID << ": From " << temp->from
                 << " to " << temp->to << " | Fare: " << temp->fare << endl;
            temp = temp->next;
        }
    }

    // Queue functions
    void addPassenger(int id, string name) {
        Passenger* p = new Passenger(id, name);
        if (!passRear) passFront = passRear = p;
        else {
            passRear->next = p;
            passRear = p;
        }
        cout << "Passenger " << name << " added to queue.\n";
    }

    void viewPassengers() const {
        Passenger* temp = passFront;
        while (temp) {
            cout << "Passenger ID: " << temp->passengerID << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Stack functions
    void addDriver(int id, string name) {
        Driver* d = new Driver(id, name);
        d->next = driverTop;
        driverTop = d;
        cout << "Driver " << name << " added to stack.\n";
    }

    // Ride assignment
    void assignRide() {
        if (!passFront || !driverTop || !rideHead) {
            cout << "Cannot assign ride: Missing passenger, driver, or ride.\n";
            return;
        }

        // Get passenger from queue
        Passenger* p = passFront;
        passFront = passFront->next;
        if (!passFront) passRear = nullptr;

        // Get driver from stack
        Driver* d = driverTop;
        driverTop = driverTop->next;

        // Get ride from head
        Ride* r = rideHead;
        rideHead = rideHead->next;

        // Log the ride history
        RideHistory* h = new RideHistory(r->rideID, p->passengerID, p->name, d->driverID, d->name);
        h->next = historyTop;
        historyTop = h;

        cout << "Assigned Ride #" << r->rideID
             << " | Passenger: " << p->name
             << " | Driver: " << d->name << endl;

        delete p;
        delete d;
        delete r;
    }

    void viewHistory() const {
        RideHistory* temp = historyTop;
        while (temp) {
            cout << "Ride #" << temp->rideID
                 << " | Passenger: " << temp->passengerName
                 << " | Driver: " << temp->driverName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    RideList system;

    // Add rides
    system.addRide(1, "Ali Town", "Hassan Abad", 200);
    system.addRide(2, "Khan Market", "Ahmad Town", 100);
    cout << "\n--- Available Rides ---\n";
    system.printRides();

    // Remove one ride
    system.removeRide(1);
    cout << "\n--- Rides After Removal ---\n";
    system.printRides();

    // Add passenger
    system.addPassenger(1, "Hassan");

    // View passengers
    cout << "\n--- Passenger Queue ---\n";
    system.viewPassengers();

    // Add driver
    system.addDriver(1, "Zain");

    // Assign a ride
    cout << "\n--- Assigning Ride ---\n";
    system.assignRide();

    // View ride history
    cout << "\n--- Ride History ---\n";
    system.viewHistory();

    return 0;
}




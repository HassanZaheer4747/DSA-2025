#include <iostream>
#include <climits>
using namespace std;

int search(int arr[],int target,int size);          //function prototype (defination in end)
void reverse(int arr[], int size);

int main()
{
    int indx;
    int size = 5;
    int arr[size];

    // initalization
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Printing
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    // find the smallest number in an array
    int smallest = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest) // 1<132123   1<23     1<3
        {
            smallest = arr[i];
            indx = i;

            // smallest=min(arr[i],smallest);     //this fun could be used in place of if-statment it find the minimum number between 2 numbers
        }
    }
    cout << "The smallest Number is " << smallest << " at index " << indx << endl;

    // find the maximum  Umber in an array
    int maximum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
            indx = i;
        }

        // maximum=max(arr[i],smallest);     //this fun could be used in place of if-statment it find the naximum number between 2 numbers
    }
    cout << "the maximum Number is " << maximum << " at index " << indx << endl;

    // Linear Search
    cout << search(arr, 3, size) << endl;

    // reverse an array
    reverse(arr, size);
}

int search(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // index at which our target is found.
        }
    }
    return -1;
}

void reverse(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]); // Swap elements
        start++;
        end--;
    }
    // Print the reversed array
    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}


// #include <iostream>
// using namespace std;

// // Driver structure (used as a stack)
// struct Driver {
//     int driverID;
//     string name;
//     Driver* next;

//     Driver(int id, string n) : driverID(id), name(n), next(nullptr) {}
// };

// Driver* driverTop = nullptr; // Stack top for drivers

// // Ride structure (Linked List node)
// struct Ride {
//     int rideID;
//     string from, to;
//     float fare;
//     Ride* next;

//     Ride(int id, string f, string t, float fa) : rideID(id), from(f), to(t), fare(fa), next(nullptr) {}
// };

// Ride* rideHead = nullptr; // Head of the ride linked list
// int rideCounter = 1;

// // Passenger structure (used as a queue)
// struct Passenger {
//     int passengerID;
//     string name;
//     Passenger* next;

//     Passenger(int id, string n) : passengerID(id), name(n), next(nullptr) {}
// };

// Passenger *passFront = nullptr, *passRear = nullptr;

// // Ride History structure
// struct RideHistory {
//     int rideID, passengerID, driverID;
//     string passengerName, driverName;
//     RideHistory* next;

//     RideHistory(int rid, int pid, string pname, int did, string dname) {
//         rideID = rid;
//         passengerID = pid;
//         passengerName = pname;
//         driverID = did;
//         driverName = dname;
//         next = nullptr;
//     }
// };

// RideHistory* historyTop = nullptr; // History stack top

// // Linked List for storing rides
// class RideList {
//     struct Node {
//         int rideID;
//         string from, to;
//         float fare;
//         Node* next;

//         Node(int id, string f, string t, float fa) : rideID(id), from(f), to(t), fare(fa), next(nullptr) {}
//     };

//     Node* head;
//     Node* tail;

// public:
//     RideList() : head(nullptr), tail(nullptr) {}

//     void addRide(int id, string from, string to, float fare) {
//         Node* newRide = new Node(id, from, to, fare);
//         if (!head) head = tail = newRide;
//         else tail = tail->next = newRide;

//         // Also add to global ride list
//         Ride* r = new Ride(id, from, to, fare);
//         r->next = rideHead;
//         rideHead = r;

//         cout << "Ride #" << id << " added successfully.\n";
//     }

//     void removeRide(int id) {
//         Node *temp = head, *prev = nullptr;

//         while (temp && temp->rideID != id) {
//             prev = temp;
//             temp = temp->next;
//         }

//         if (!temp) {
//             cout << "Ride not found.\n";
//             return;
//         }

//         if (!prev) head = temp->next;
//         else prev->next = temp->next;

//         delete temp;
//         cout << "Ride #" << id << " removed.\n";
//     }

//     void printRides() const {
//         Node* temp = head;
//         while (temp) {
//             cout << "Ride #" << temp->rideID << ": From " << temp->from
//                  << " to " << temp->to << " | Fare: " << temp->fare << endl;
//             temp = temp->next;
//         }
//     }

//     // Queue functions
//     void addPassenger(int id, string name) {
//         Passenger* p = new Passenger(id, name);
//         if (!passRear) passFront = passRear = p;
//         else {
//             passRear->next = p;
//             passRear = p;
//         }
//         cout << "Passenger " << name << " added to queue.\n";
//     }

//     void viewPassengers() const {
//         Passenger* temp = passFront;
//         while (temp) {
//             cout << "Passenger ID: " << temp->passengerID << " | Name: " << temp->name << endl;
//             temp = temp->next;
//         }
//     }

//     // Stack functions
//     void addDriver(int id, string name) {
//         Driver* d = new Driver(id, name);
//         d->next = driverTop;
//         driverTop = d;
//         cout << "Driver " << name << " added to stack.\n";
//     }

//     // Ride assignment
//     void assignRide() {
//         if (!passFront || !driverTop || !rideHead) {
//             cout << "Cannot assign ride: Missing passenger, driver, or ride.\n";
//             return;
//         }

//         // Get passenger from queue
//         Passenger* p = passFront;
//         passFront = passFront->next;
//         if (!passFront) passRear = nullptr;

//         // Get driver from stack
//         Driver* d = driverTop;
//         driverTop = driverTop->next;

//         // Get ride from head
//         Ride* r = rideHead;
//         rideHead = rideHead->next;

//         // Log the ride history
//         RideHistory* h = new RideHistory(r->rideID, p->passengerID, p->name, d->driverID, d->name);
//         h->next = historyTop;
//         historyTop = h;

//         cout << "Assigned Ride #" << r->rideID
//              << " | Passenger: " << p->name
//              << " | Driver: " << d->name << endl;

//         delete p;
//         delete d;
//         delete r;
//     }

//     void viewHistory() const {
//         RideHistory* temp = historyTop;
//         while (temp) {
//             cout << "Ride #" << temp->rideID
//                  << " | Passenger: " << temp->passengerName
//                  << " | Driver: " << temp->driverName << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main() {
//     RideList system;

//     // Add rides
//     system.addRide(1, "Ali Town", "Hassan Abad", 200);
//     system.addRide(2, "Khan Market", "Ahmad Town", 100);
//     cout << "\n--- Available Rides ---\n";
//     system.printRides();

//     // Remove one ride
//     system.removeRide(1);
//     cout << "\n--- Rides After Removal ---\n";
//     system.printRides();

//     // Add passenger
//     system.addPassenger(1, "Hassan");

//     // View passengers
//     cout << "\n--- Passenger Queue ---\n";
//     system.viewPassengers();

//     // Add driver
//     system.addDriver(1, "Zain");

//     // Assign a ride
//     cout << "\n--- Assigning Ride ---\n";
//     system.assignRide();

//     // View ride history
//     cout << "\n--- Ride History ---\n";
//     system.viewHistory();

//     return 0;
// }

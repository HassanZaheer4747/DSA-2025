// // You’re working on a software system for a supermarket. The system maintains an array representing the stock quantity of 10 different products. Your task is to write code that:
// // 🎯 Tasks:
// // Input the stock of 10 products.
// // Find the product with the lowest and highest stock, and print their index and quantity.
// // Check if any product is out of stock (i.e., stock == 0), and print the index of all such products.
// // Restock all items that have stock less than 5 by adding 10 to their current value.
// // Print the final updated stock list.

// #include <iostream>
// #include <climits>
// using namespace std;

// int main()
// {

//     int size = 10;
//     int stock[size];

//     cout << "Enter the stock of 10 products:";
//     for (int i = 0; i < size; i++)
//     {
//         cin >> stock[i];
//     }

//     for (int i = 0; i < size; i++)
//     {
//         cout << stock[i] << endl;
//     }


//     int minStock = INT_MAX, maxStock = INT_MIN;
//     int minIndex = -1, maxIndex = -1;

//     for (int i = 0; i < size; i++)
//     {
//         if (stock[i] < minStock)
//         {
//             minStock = stock[i];
//             minIndex = i;
//         }
//         if (stock[i] > maxStock)
//         {
//             maxStock = stock[i];
//             maxIndex = i;
//         }
//     }
//     cout << "\nLowest Stock: " << minStock << " at index " << minIndex << endl;
//     cout << "Highest Stock: " << maxStock << " at index " << maxIndex << endl;

//     bool foundoutofstock = false;
//     for (int i = 0; i < size; i++)
//     {
//         if (stock[i] == 0)
//         {
//             cout <<"Out of Stock Products at indices"<< i <<" "<< endl;
//             foundoutofstock = true;
//         }
//     }
//     if (!foundoutofstock)
//     {
//         cout << "None";
//     }
//     cout << endl;

//     for (int i = 0; i < size; i++)
//     {
//         if (stock[i] < 5)
//         {
//             stock[i] = stock[i] + 10;
//         }
//     }

//     cout << "\nUpdated Stock:\n";
//     for (int i = 0; i < size; i++)
//     {
//         cout << stock[i] << " ";
//     }
//     cout << endl;
// }

#include <iostream>
#include <string>
using namespace std;

// ======= Ride (Linked List Node) =======
struct Ride {
    int rideID;
    string from, to;
    float fare;
    Ride* next;
    Ride(int id, string f, string t, float fa) {
        rideID = id; from = f; to = t; fare = fa;
        next = nullptr;
    }
};

Ride* rideHead = nullptr;
int rideCounter = 1;

// ======= Passenger (Queue Node) =======
struct Passenger {
    int passengerID;
    string name;
    Passenger* next;
    Passenger(int id, string n) {
        passengerID = id; name = n;
        next = nullptr;
    }
};

Passenger *passFront = nullptr, *passRear = nullptr;

// ======= Driver (Stack Node) =======
struct Driver {
    int driverID;
    string name;
    Driver* next;
    Driver(int id, string n) {
        driverID = id; name = n;
        next = nullptr;
    }
};

Driver* driverTop = nullptr;

// ======= Ride History (Stack Node) =======
struct RideHistory {
    int rideID, passengerID, driverID;
    string passengerName, driverName;
    RideHistory* next;
    RideHistory(int rid, int pid, string pname, int did, string dname) {
        rideID = rid; passengerID = pid; passengerName = pname;
        driverID = did; driverName = dname;
        next = nullptr;
    }
};

RideHistory* historyTop = nullptr;

// ======= Functions =======

void addRide(string from, string to, float fare) {
    Ride* newRide = new Ride(rideCounter++, from, to, fare);
    if (!rideHead) rideHead = newRide;
    else {
        Ride* temp = rideHead;
        while (temp->next) temp = temp->next;
        temp->next = newRide;
    }
    cout << "Ride added successfully.\n";
}

void removeRide(int id) {
    Ride *temp = rideHead, *prev = nullptr;
    while (temp && temp->rideID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Ride not found.\n";
        return;
    }
    if (!prev) rideHead = temp->next;
    else prev->next = temp->next;
    delete temp;
    cout << "Ride removed.\n";
}

void viewRides() {
    Ride* temp = rideHead;
    while (temp) {
        cout << "ID: " << temp->rideID << " | From: " << temp->from
             << " | To: " << temp->to << " | Fare: " << temp->fare << endl;
        temp = temp->next;
    }
}

void addPassenger(int id, string name) {
    Passenger* p = new Passenger(id, name);
    if (!passRear) passFront = passRear = p;
    else {
        passRear->next = p;
        passRear = p;
    }
    cout << "Passenger added to queue.\n";
}

void viewPassengers() {
    Passenger* temp = passFront;
    while (temp) {
        cout << "ID: " << temp->passengerID << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

void addDriver(int id, string name) {
    Driver* d = new Driver(id, name);
    d->next = driverTop;
    driverTop = d;
    cout << "Driver added to stack.\n";
}

void assignRide() {
    if (!passFront || !driverTop || !rideHead) {
        cout << "Not enough resources to assign ride.\n";
        return;
    }
    // Dequeue passenger
    Passenger* p = passFront;
    passFront = passFront->next;
    if (!passFront) passRear = nullptr;

    // Pop driver
    Driver* d = driverTop;
    driverTop = driverTop->next;

    // Use first ride
    Ride* r = rideHead;

    // Add to history
    RideHistory* h = new RideHistory(r->rideID, p->passengerID, p->name, d->driverID, d->name);
    h->next = historyTop;
    historyTop = h;

    cout << "Ride Assigned:\nRide ID: " << r->rideID
         << " | Passenger: " << p->name
         << " | Driver: " << d->name << endl;

    delete p;
    delete d;
}

void viewHistory() {
    RideHistory* temp = historyTop;
    while (temp) {
        cout << "RideID: " << temp->rideID
             << " | Passenger: " << temp->passengerName
             << " | Driver: " << temp->driverName << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Ride Queue Management Menu ---\n";
        cout << "1. Add New Ride\n2. Remove Ride\n3. View Rides\n";
        cout << "4. Add Passenger\n5. View Passenger Queue\n";
        cout << "6. Add Driver\n7. Assign Ride\n8. View Ride History\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string f, t; float fa;
            cout << "From: "; cin >> f;
            cout << "To: "; cin >> t;
            cout << "Fare: "; cin >> fa;
            addRide(f, t, fa);
        } else if (choice == 2) {
            int id; cout << "Enter Ride ID to remove: ";
            cin >> id;
            removeRide(id);
        } else if (choice == 3) {
            viewRides();
        } else if (choice == 4) {
            int id; string n;
            cout << "Passenger ID: "; cin >> id;
            cout << "Name: "; cin >> n;
            addPassenger(id, n);
        } else if (choice == 5) {
            viewPassengers();
        } else if (choice == 6) {
            int id; string n;
            cout << "Driver ID: "; cin >> id;
            cout << "Name: "; cin >> n;
            addDriver(id, n);
        } else if (choice == 7) {
            assignRide();
        } else if (choice == 8) {
            viewHistory();
        } else if (choice == 9) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}


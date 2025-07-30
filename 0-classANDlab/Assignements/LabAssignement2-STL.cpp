#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Structure to store call details
struct Call {
    int id;
    string callerName;

    Call(int i, string name) : id(i), callerName(name) {}
};

// Call Center Management System
class CallCenter {
private:
    queue<Call> callQueue;  // Queue for incoming calls
    stack<Call> callHistory; // Stack for call history
    int callID; // Unique call ID tracker

public:
    CallCenter() : callID(1) {}

    // Add a call to the queue
    void addCall(string callerName) {
        Call newCall(callID++, callerName);
        callQueue.push(newCall);
        cout << "Call from " << callerName << " added to the queue.\n";
    }

    // Process a call (move from queue to stack)
    void processCall() {
        if (callQueue.empty()) {
            cout << "No calls to process.\n";
            return;
        }
        
        Call currentCall = callQueue.front();
        callQueue.pop();
        callHistory.push(currentCall);

        cout << "Processing call from " << currentCall.callerName << " (ID: " << currentCall.id << ").\n";
    }

    // Display all calls in the queue
    void displayQueue() {
        if (callQueue.empty()) {
            cout << "No pending calls in the queue.\n";
            return;
        }

        queue<Call> tempQueue = callQueue;
        cout << "Current Call Queue:\n";
        while (!tempQueue.empty()) {
            Call c = tempQueue.front();
            tempQueue.pop();
            cout << "Call ID: " << c.id << ", Caller: " << c.callerName << "\n";
        }
    }

    // Pop the most recent call from the history stack
    void popCallHistory() {
        if (callHistory.empty()) {
            cout << "No call history available.\n";
            return;
        }

        Call lastCall = callHistory.top();
        callHistory.pop();
        cout << "Removed call from history: " << lastCall.callerName << " (ID: " << lastCall.id << ").\n";
    }

    // Display call history (most recent first)
    void displayCallHistory() {
        if (callHistory.empty()) {
            cout << "Call history is empty.\n";
            return;
        }

        stack<Call> tempStack = callHistory;
        cout << "Call History (Most recent first):\n";
        while (!tempStack.empty()) {
            Call c = tempStack.top();
            tempStack.pop();
            cout << "Call ID: " << c.id << ", Caller: " << c.callerName << "\n";
        }
    }
};

// Main function to test the system
int main() {
    CallCenter callCenter;

    // Simulating incoming calls
    callCenter.addCall("Alice");
    callCenter.addCall("Bob");
    callCenter.addCall("Charlie");

    // Display queue before processing
    callCenter.displayQueue();

    // Process some calls
    callCenter.processCall();
    callCenter.processCall();

    // Display queue after processing
    callCenter.displayQueue();

    // Display call history
    callCenter.displayCallHistory();

    // Remove the most recent call from history
    callCenter.popCallHistory();

    // Display updated call history
    callCenter.displayCallHistory();

    return 0;
}

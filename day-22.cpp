#include <iostream>
#include <queue>
using namespace std;

class RideQueue {
private:
    queue<string> vipQueue;
    queue<string> normalQueue;

public:
    void joinQueue(string name, bool vip = false) {
        if (vip) {
            vipQueue.push(name);
            cout << name << " joined VIP Queue" << endl;
        } else {
            normalQueue.push(name);
            cout << name << " joined Normal Queue" << endl;
        }
    }

    void processVisitor() {
        if (!vipQueue.empty()) {
            cout << "Processing VIP Visitor: "
                 << vipQueue.front() << endl;
            vipQueue.pop();
        }
        else if (!normalQueue.empty()) {
            cout << "Processing Normal Visitor: "
                 << normalQueue.front() << endl;
            normalQueue.pop();
        }
        else {
            cout << "No visitors in queue" << endl;
        }
    }

    void displayQueues() {
        cout << "\nCurrent Queue Status\n";
        cout << "-----------\n";

        queue<string> tempVIP = vipQueue;
        cout << "VIP Queue: ";
        while (!tempVIP.empty()) {
            cout << tempVIP.front() << " ";
            tempVIP.pop();
        }
        cout << endl;

        queue<string> tempNormal = normalQueue;
        cout << "Normal Queue: ";
        while (!tempNormal.empty()) {
            cout << tempNormal.front() << " ";
            tempNormal.pop();
        }
        cout << endl << endl;
    }
};

int main() {
    RideQueue ride;

    ride.joinQueue("Alice");
    ride.joinQueue("Bob");
    ride.joinQueue("Charlie", true);
    ride.joinQueue("David");
    ride.joinQueue("Emma", true);

    ride.displayQueues();

    ride.processVisitor();
    ride.displayQueues();

    ride.processVisitor();
    ride.displayQueues();

    ride.processVisitor();
    ride.displayQueues();

    ride.processVisitor();
    ride.displayQueues();

    ride.processVisitor();
    ride.displayQueues();

    return 0;
}
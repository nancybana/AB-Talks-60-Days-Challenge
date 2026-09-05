#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "Maze 1: ";
    if (detectCycle(head1))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);

    head2->next->next->next->next = head2->next;

    cout << "Maze 2: ";
    if (detectCycle(head2))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
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

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;

    delete nodeToDelete;

    return dummy.next;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original Message Chain:" << endl;
    display(head);

    int n = 2;

    head = removeNthFromEnd(head, n);

    cout << "\nAfter Removing " << n << "th Node From End:" << endl;
    display(head);

    return 0;
}
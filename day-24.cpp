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

void insertAtTail(Node* &head, int val) {
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

Node* mergeSortedLists(Node* list1, Node* list2) {

    Node dummy(0);
    Node* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    }

    if (list2 != NULL) {
        tail->next = list2;
    }
    return dummy.next;
}

int main() {

    Node* list1 = NULL;
    Node* list2 = NULL;

    insertAtTail(list1, 1);
    insertAtTail(list1, 3);
    insertAtTail(list1, 5);
    insertAtTail(list1, 7);

    insertAtTail(list2, 2);
    insertAtTail(list2, 3);
    insertAtTail(list2, 6);
    insertAtTail(list2, 8);

    cout << "List 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    Node* mergedList = mergeSortedLists(list1, list2);

    cout << "Merged Sorted List: ";
    display(mergedList);

    return 0;
}
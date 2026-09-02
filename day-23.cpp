```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

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
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main() {
    Node* train = NULL;

    insert(train, 1);
    insert(train, 2);
    insert(train, 3);
    insert(train, 4);
    insert(train, 5);

    cout << "Original Train Order:" << endl;
    display(train);

    train = reverseList(train);

    cout << "Reversed Train Order:" << endl;
    display(train);

    return 0;
}
```

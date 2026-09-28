#include <iostream>
#include <vector>
using namespace std;

class User {
public:
    int id;
    string name;

    User(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

class Restaurant {
public:
    int id;
    string name;

    Restaurant(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

class DeliveryPartner {
public:
    int id;
    string name;
    bool available;

    DeliveryPartner(int id, string name) {
        this->id = id;
        this->name = name;
        available = true;
    }
};

class Order {
public:
    int orderId;
    User* user;
    Restaurant* restaurant;
    DeliveryPartner* partner;
    string status;

    Order(int id, User* u, Restaurant* r) {
        orderId = id;
        user = u;
        restaurant = r;
        partner = nullptr;
        status = "Placed";
    }

    void assignPartner(DeliveryPartner* p) {
        partner = p;
        p->available = false;
        status = "Out For Delivery";
    }

    void deliverOrder() {
        status = "Delivered";
        if(partner)
            partner->available = true;
    }

    void display() {
        cout << "\nOrder ID: " << orderId << endl;
        cout << "User: " << user->name << endl;
        cout << "Restaurant: " << restaurant->name << endl;

        if(partner)
            cout << "Delivery Partner: " << partner->name << endl;

        cout << "Status: " << status << endl;
    }
};

int main() {

    User u1(1, "Nancy");

    Restaurant r1(101, "Pizza Hub");

    DeliveryPartner d1(201, "Rahul");

    Order order1(1001, &u1, &r1);

    cout << "Order Placed Successfully\n";

    order1.status = "Preparing";

    order1.assignPartner(&d1);

    order1.display();

    order1.deliverOrder();

    cout << "\nAfter Delivery:\n";

    order1.display();

    return 0;
}
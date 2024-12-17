#include <iostream>
using namespace std;

#define size 5  // Maximum size of the pizza order queue

class pizza {
    int porder[size];  // Array to hold orders
    int front, rear;  // Front and rear pointers of the queue

public:
    // Constructor to initialize queue pointers
    pizza() {
        front = rear = -1;
    }

    // Function to check if the queue is full
    int qfull() {
        return (front == (rear + 1) % size);
    }

    // Function to check if the queue is empty
    int qempty() {
        return (front == -1);
    }

    // Function to accept a new order
    void accept_order(int item) {
        if (qfull()) {
            cout << "\nVery Sorry !!!! No more orders....\n";
        } else {
            if (front == -1) {  // If queue is empty, initialize front and rear
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;  // Circular increment
            }
            porder[rear] = item;  // Add the order to the queue
            cout << "\nOrder accepted: " << item << endl;
        }
    }

    // Function to process and make payment for orders
    void make_payment() {
        int item, n;
        if (qempty()) {
            cout << "\nSorry !!! No orders to serve...\n";
        } else {
            cout << "\nPending orders:\n";
            int temp = front, ct = 0;
            // Count the number of orders in the queue
            while (temp != rear) {
                ct++;
                temp = (temp + 1) % size;
            }
            ct++;  // Counting the last order
            cout << "There are " << ct << " orders in the queue.\n";
            cout << "\nHow many pizzas would you like to order for delivery? ";
            cin >> n;

            if (n > ct) {
                cout << "Sorry, there are not enough orders to fulfill your request.\n";
                return;
            }

            cout << "\nDelivering the orders...\n";
            for (int i = 0; i < n; i++) {
                item = porder[front];  // Get the next order
                cout << "\tPizza " << item << endl;
                // Move front pointer to the next order
                if (front == rear) {  // If there was only one order
                    front = rear = -1;
                } else {
                    front = (front + 1) % size;  // Circular increment
                }
            }
            cout << "\nTotal amount to pay: " << n * 100 << " INR\n";
            cout << "\nThank you for visiting again....\n";
        }
    }

    // Function to display pending orders in the queue
    void order_in_queue() {
        if (qempty()) {
            cout << "\nSorry !! There are no pending orders...\n";
        } else {
            cout << "\nPending orders:\n";
            int temp = front;
            while (temp != rear) {
                cout << "\tPizza " << porder[temp] << endl;
                temp = (temp + 1) % size;
            }
            cout << "\tPizza " << porder[temp] << endl;  // Display last order
        }
    }
};

int main() {
    pizza p1;
    int ch, k;
    do {
        cout << "\n\t***** Welcome To Pizza Parlor *******\n";
        cout << "\n1. Accept order\n2. Make payment\n3. Pending Orders\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nWhich pizza would you like to order?\n";
                cout << "\n1. Veg Soya Pizza\n2. Veg Butter Pizza\n3. Egg Pizza\n";
                cout << "\nPlease enter your order (1/2/3): ";
                cin >> k;
                p1.accept_order(k);
                break;

            case 2:
                p1.make_payment();
                break;

            case 3:
                p1.order_in_queue();
                break;

            case 4:
                cout << "Thank you for visiting. Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (ch != 4);

    return 0;
}
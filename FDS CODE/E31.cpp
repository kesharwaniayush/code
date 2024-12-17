#include <iostream>
using namespace std;

#define SIZE 10

class DEQUE {
    int a[SIZE];
    int front, rear, count;

public:
    DEQUE() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Add an element at the beginning of the deque
    void addBegin(int item) {
        if (count == SIZE) {
            cout << "\nInsertion is not possible, overflow!" << endl;
            return;
        }
        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;  // Circular decrement of front
        }
        a[front] = item;
        count++;
    }

    // Add an element at the end of the deque
    void addEnd(int item) {
        if (count == SIZE) {
            cout << "\nInsertion is not possible, overflow!" << endl;
            return;
        }
        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;  // Circular increment of rear
        }
        a[rear] = item;
        count++;
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (front == -1) {  // Deque is empty
            cout << "Deletion is not possible: DEQUE is empty" << endl;
            return;
        }
        cout << "The deleted element is " << a[front] << endl;
        if (front == rear) {  // Only one element is present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Circular increment of front
        }
        count--;
    }

    // Delete an element from the end of the deque
    void deleteEnd() {
        if (front == -1) {  // Deque is empty
            cout << "Deletion is not possible: DEQUE is empty" << endl;
            return;
        }
        cout << "The deleted element is " << a[rear] << endl;
        if (front == rear) {  // Only one element is present
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;  // Circular decrement of rear
        }
        count--;
    }

    // Display the elements of the deque
    void display() {
        if (front == -1) {  // Deque is empty
            cout << "DEQUE is empty" << endl;
            return;
        }
        int i = front;
        cout << "DEQUE elements are: ";
        while (i != rear) {
            cout << a[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << a[rear] << endl;  // Display the rear element
    }
};

int main() {
    int choice, item;
    DEQUE d1;

    do {
        cout << "\n\n*DEQUE OPERATION*\n";
        cout << "1-Insert at beginning\n";
        cout << "2-Insert at end\n";
        cout << "3-Display\n";
        cout << "4-Deletion from front\n";
        cout << "5-Deletion from rear\n";
        cout << "6-Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.addBegin(item);
                break;
            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.addEnd(item);
                break;
            case 3:
                d1.display();
                break;
            case 4:
                d1.deleteFront();
                break;
            case 5:
                d1.deleteEnd();
                break;
            case 6:
                cout << "Exiting the program\n";
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 6);
    return 0;
}
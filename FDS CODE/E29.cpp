#include <iostream>
using namespace std;

class queue {
    int data[20];
    int f, r;

public:
    queue() {
        f = -1;
        r = -1;
    }

    // Check if the queue is empty
    int isempty() {
        return (f == -1); // Queue is empty if front is -1
    }

    // Check if the queue is full
    int isfull() {
        return ((r + 1) % 20 == f); // Queue is full if (r+1) wraps around to f
    }

    // Add a job to the queue
    void enqueue(int x) {
        if (isfull()) {
            cout << "Job queue is full!" << endl;
        } else {
            if (f == -1) // If the queue is empty, set front to 0
                f = 0;
            r = (r + 1) % 20; // Circular increment
            data[r] = x;
            cout << "Job added: " << x << endl;
        }
    }

    // Remove a job from the queue
    void dequeue() {
        if (isempty()) {
            cout << "Job queue is empty!" << endl;
        } else {
            int x = data[f];
            cout << x << " Job deleted" << endl;
            if (f == r) {
                f = r = -1; // If only one job was in the queue, reset to empty
            } else {
                f = (f + 1) % 20; // Circular increment
            }
        }
    }

    // Display the current jobs in the queue
    void disp() {
        if (isempty()) {
            cout << "Job queue is empty!" << endl;
            return;
        }
        cout << "Job queue is as follows: ";
        int i = f;
        while (i != r) {
            cout << data[i] << " ";
            i = (i + 1) % 20; // Circular increment
        }
        cout << data[r] << endl; // Print the last element
    }
};

int main() {
    int ch, n, x, d;
    queue q;
    cout << "Enter the number of jobs in the queue: ";
    cin >> n;

    cout << "Enter jobs: ";
    for (int i = 0; i < n; i++) {
        cin >> d;
        q.enqueue(d);
    }

    do {
        cout << "********** MENU **********" << endl;
        cout << "1) Add job" << endl;
        cout << "2) Delete job" << endl;
        cout << "3) Display job queue" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the job to be added: ";
                cin >> d;
                q.enqueue(d);
                q.disp();
                break;
            case 2:
                q.dequeue();
                q.disp();
                break;
            case 3:
                q.disp();
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Do you want to continue?" << endl;
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        cin >> x;

    } while (x == 1);

    return 0;
}
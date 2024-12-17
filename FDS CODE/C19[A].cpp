#include <iostream>
#include <string>
using namespace std;

// Node structure
struct node {
    int prn;
    string name;
    node* next;
};

// Linked List Class
class list {
    node* head;
    node* temp;

public:
    list() { head = NULL; }

    // Create a new node
    node* create(int val, string n);

    // Add members
    void insertEnd();
    void insertBeg();
    void insertAt(int i);
    
    // Delete members
    void deleteAt(int i);
    
    // Display and Count members
    void display();
    int count();
    
    // Concatenate two lists
    void concatenate(list &A, list &B);
    
    // Operations menu
    void op();
};

// Create a new node
node* list::create(int val, string n) {
    temp = new node;
    if (temp == NULL) {
        cout << "Memory Allocation Failed!" << endl;
        return NULL;
    } else {
        temp->prn = val;
        temp->name = n;
        temp->next = NULL;
        return temp;
    }
}

// Insert at the end (Secretary)
void list::insertEnd() {
    int val;
    string n;
    cout << "Enter PRN: ";
    cin >> val;
    cout << "Enter Name: ";
    cin >> n;
    
    node* t = head;
    temp = create(val, n);
    
    if (head == NULL) {
        head = temp;
    } else {
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }
    cout << "Element Inserted at the End" << endl;
}

// Insert at the beginning (President)
void list::insertBeg() {
    int val;
    string n;
    cout << "Enter PRN: ";
    cin >> val;
    cout << "Enter Name: ";
    cin >> n;
    
    temp = create(val, n);
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    cout << "New President Added!" << endl;
}

// Insert at a specific position
void list::insertAt(int i) {
    int val, pos = i - 1, counter = 1;
    string n;
    node* ptr;
    node* t = head;

    while (t->next != NULL) {
        t = t->next;
        counter++;
    }
    t = head;
    
    if (i == 1) {
        insertBeg();
    } else if (pos > counter || i <= 0) {
        cout << "Entered position is out of scope." << endl;
    } else {
        cout << "Enter PRN: ";
        cin >> val;
        cout << "Enter Name: ";
        cin >> n;
        
        temp = create(val, n);
        while (pos--) {
            ptr = t;
            t = t->next;
        }
        temp->next = t;
        ptr->next = temp;
        cout << "Member Inserted at Position: " << i << endl;
    }
}

// Delete at a specific position
void list::deleteAt(int i) {
    int pos = i - 1, counter = 1;
    node *ptrl, *ptrr;
    node* t = head;

    while (t->next != NULL) {
        t = t->next;
        counter++;
    }
    t = head;

    if (i == 1) {
        ptrl = head;
        head = head->next;
        delete ptrl;
    } else if (pos > counter || i <= 0) {
        cout << "Entered position doesn't exist." << endl;
    } else {
        while (pos--) {
            ptrl = t;
            t = t->next;
            ptrr = t->next;
        }
        ptrl->next = ptrr;
        delete t;
        cout << "Member Deleted at Position: " << i << endl;
    }
}

// Display the list
void list::display() {
    node* t = head;
    if (t == NULL) {
        cout << "No members in the club." << endl;
    } else {
        cout << "President: " << t->prn << " : " << t->name << " -> ";
        t = t->next;
        
        while (t != NULL) {
            cout << t->prn << " : " << t->name << " -> ";
            t = t->next;
        }
        cout << "Secretary: " << t->prn << " : " << t->name << " -> ";
        cout << "NULL" << endl;
    }
}

// Count the number of members
int list::count() {
    node* t = head;
    int ct = 0;
    while (t != NULL) {
        ct++;
        t = t->next;
    }
    return ct;
}

// Concatenate two lists
void list::concatenate(list &A, list &B) {
    node* t = A.head;
    node* last;
    while (t != NULL) {
        temp = create(t->prn, t->name);
        if (head == NULL) {
            head = temp;
            last = head;
        } else {
            last->next = temp;
            last = temp;
        }
        t = t->next;
    }
    
    t = B.head;
    while (t != NULL) {
        temp = create(t->prn, t->name);
        last->next = temp;
        last = temp;
        t = t->next;
    }
    last->next = NULL;
}

// Operations menu
void list::op() {
    while (1) {
        int choice;
        cout << "\nEnter: \n1. Add \n2. Delete \n3. Member's Count \n4. Display \n0. Prev Menu\nEnter Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                char c;
                cout << "\nEnter: \nA. Add President \nB. Add Secretary \nC. Add Member\nEnter Choice: ";
                cin >> c;
                switch (c) {
                    case 'A':
                    case 'a': {
                        insertBeg();
                        break;
                    }
                    case 'B':
                    case 'b': {
                        insertEnd();
                        break;
                    }
                    case 'C':
                    case 'c': {
                        insertAt(2);
                        break;
                    }
                }
                break;
            }
            case 2: {
                char c;
                cout << "\nEnter: \nA. Delete President \nB. Delete Secretary \nC. Delete Member\nEnter Choice: ";
                cin >> c;
                switch (c) {
                    case 'A': {
                        deleteAt(1);
                        cout << "Club must have a President. Enter Details" << endl;
                        insertBeg();
                        break;
                    }
                    case 'B': {
                        deleteAt(count());
                        cout << "Club must have a Secretary. Enter Details" << endl;
                        insertEnd();
                        break;
                    }
                    case 'C': {
                        int j;
                        cout << "Enter Position for Deletion" << endl;
                        cin >> j;
                        deleteAt(j);
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "Total Members: " << count() << endl;
                break;
            }
            case 4: {
                display();
                break;
            }
            case 0: {
                return;
            }
        }
    }
}

// Main
int main() {
    list L, X, Y;
    int c;
    while (1) {
        cout << "Enter: \n1. List A \n2. List B \n3. Concatenate\n0. Exit\nEnter Choice: ";
        cin >> c;
        switch (c) {
            case 1: cout << "\nList A:"; X.op(); break;
            case 2: cout << "\nList B:"; Y.op(); break;
            case 3: L.concatenate(X, Y); L.display(); break;
            case 0: return 0;
        }
    }
}
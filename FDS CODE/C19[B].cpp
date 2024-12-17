#include <iostream>
#include <string>
using namespace std;

// Node structure to hold PRN and Name
struct node {
    int prn;
    string name;
    struct node *next;
};

// Class to manage the singly linked list of club members
class Club {
    node *head, *tail, *temp;

public:
    Club() {
        head = nullptr;   // Initially, the list is empty
        tail = nullptr;
    }

    node* create(int val, string n);  // Create a new node
    void addPresident();               // Add President
    void addSecretary();               // Add Secretary
    void addMember();                  // Add a regular member
    void deletePresident();            // Delete the President
    void deleteSecretary();            // Delete the Secretary
    void deleteMember(int position);  // Delete a member at specific position
    void display();                    // Display all members
    int totalMembers();                // Calculate total number of members
    void concatenate(Club &other);     // Concatenate two lists
};

// Create a new node with given PRN and Name
node* Club::create(int val, string n) {
    temp = new node;
    if (temp == nullptr) {
        cout << "Memory Allocation Failed!" << endl;
        return nullptr;
    } else {
        temp->prn = val;
        temp->name = n;
        temp->next = nullptr;
        return temp;
    }
}

// Add President to the club (at the beginning of the list)
void Club::addPresident() {
    int val;
    string n;
    cout << "Enter President PRN: ";
    cin >> val;
    cout << "Enter President Name: ";
    cin >> n;
    temp = create(val, n);
    if (head == nullptr) {
        head = tail = temp;  // If list is empty, head and tail are the same
    } else {
        temp->next = head;
        head = temp;  // Add at the beginning
    }
    cout << "President added successfully!" << endl;
}

// Add Secretary to the club (at the end of the list)
void Club::addSecretary() {
    int val;
    string n;
    cout << "Enter Secretary PRN: ";
    cin >> val;
    cout << "Enter Secretary Name: ";
    cin >> n;
    temp = create(val, n);
    if (head == nullptr) {
        head = tail = temp;  // If list is empty, head and tail are the same
    } else {
        tail->next = temp;
        tail = temp;  // Add at the end
    }
    cout << "Secretary added successfully!" << endl;
}

// Add regular member at the end of the list
void Club::addMember() {
    int val;
    string n;
    cout << "Enter Member PRN: ";
    cin >> val;
    cout << "Enter Member Name: ";
    cin >> n;
    temp = create(val, n);
    if (head == nullptr) {
        head = tail = temp;  // If list is empty, head and tail are the same
    } else {
        tail->next = temp;
        tail = temp;  // Add at the end
    }
    cout << "Member added successfully!" << endl;
}

// Delete the President (first node in the list)
void Club::deletePresident() {
    if (head == nullptr) {
        cout << "No members in the club!" << endl;
        return;
    }
    node* temp = head;
    head = head->next;  // Move the head to the next member
    delete temp;  // Delete the old president node
    cout << "President deleted successfully!" << endl;
}

// Delete the Secretary (last node in the list)
void Club::deleteSecretary() {
    if (head == nullptr) {
        cout << "No members in the club!" << endl;
        return;
    }
    if (head == tail) {
        delete head;  // If only one node, delete it
        head = tail = nullptr;
    } else {
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;  // Traverse to second last node
        }
        delete tail;  // Delete the last node (Secretary)
        tail = temp;   // Update tail to second last node
        tail->next = nullptr;
    }
    cout << "Secretary deleted successfully!" << endl;
}

// Delete a member at a specific position
void Club::deleteMember(int position) {
    if (head == nullptr) {
        cout << "No members in the club!" << endl;
        return;
    }
    if (position == 1) {
        deletePresident();  // Delete the President
        return;
    }
    node* temp = head;
    node* prev = nullptr;
    int count = 1;
    while (temp != nullptr && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << "No member at the given position!" << endl;
    } else {
        prev->next = temp->next;  // Unlink the node
        delete temp;  // Delete the member
        cout << "Member deleted successfully!" << endl;
    }
}

// Display all the members of the club
void Club::display() {
    if (head == nullptr) {
        cout << "No members in the club!" << endl;
        return;
    }
    node* temp = head;
    cout << "Club Members:\n";
    while (temp != nullptr) {
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// Compute total number of members in the club
int Club::totalMembers() {
    int count = 0;
    node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Concatenate two clubs (two linked lists)
void Club::concatenate(Club &other) {
    if (head == nullptr) {
        head = other.head;
        tail = other.tail;
    } else {
        tail->next = other.head;
        tail = other.tail;
    }
    cout << "Clubs concatenated successfully!" << endl;
}

// Main function to interact with the user
int main() {
    Club A, B;
    int choice;
    while (true) {
        cout << "\n1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n5. Delete Secretary\n6. Delete Member\n7. Display Members\n8. Total Members\n9. Concatenate Two Clubs\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                A.addPresident();
                break;
            case 2:
                A.addSecretary();
                break;
            case 3:
                A.addMember();
                break;
            case 4:
                A.deletePresident();
                break;
            case 5:
                A.deleteSecretary();
                break;
            case 6:
                int pos;
                cout << "Enter position to delete member: ";
                cin >> pos;
                A.deleteMember(pos);
                break;
            case 7:
                A.display();
                break;
            case 8:
                cout << "Total members: " << A.totalMembers() << endl;
                break;
            case 9:
                A.concatenate(B);
                A.display();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
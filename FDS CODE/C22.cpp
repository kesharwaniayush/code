#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Node structure for linked list
struct node {
    int prn;  // Unique student PRN
    struct node* next;
};

// Class to manage the linked list of students
class Set {
    node* head;
public:
    Set() {
        head = nullptr;  // Initialize an empty list
    }

    node* createNode(int prn);    // Create a new node
    void insert(int prn);         // Insert student PRN to the list
    void display();               // Display all student PRNs in the list
    unordered_set<int> toSet();   // Convert linked list to unordered set for set operations
};

// Create a new node
node* Set::createNode(int prn) {
    node* newNode = new node;
    newNode->prn = prn;
    newNode->next = nullptr;
    return newNode;
}

// Insert a student PRN into the set (linked list)
void Set::insert(int prn) {
    node* newNode = createNode(prn);
    if (head == nullptr) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display the students in the set
void Set::display() {
    node* temp = head;
    if (temp == nullptr) {
        cout << "No students in the set." << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "PRN: " << temp->prn << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Convert the linked list to an unordered set for set operations
unordered_set<int> Set::toSet() {
    unordered_set<int> resultSet;
    node* temp = head;
    while (temp != nullptr) {
        resultSet.insert(temp->prn);
        temp = temp->next;
    }
    return resultSet;
}

// Main function
int main() {
    Set vanillaSet, butterscotchSet;

    int n, prn;
    cout << "Enter number of students who like Vanilla Ice-Cream: ";
    cin >> n;
    cout << "Enter PRNs of students who like Vanilla Ice-Cream:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> prn;
        vanillaSet.insert(prn);
    }

    cout << "Enter number of students who like Butterscotch Ice-Cream: ";
    cin >> n;
    cout << "Enter PRNs of students who like Butterscotch Ice-Cream:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> prn;
        butterscotchSet.insert(prn);
    }

    // Display the students in each set
    cout << "\nStudents who like Vanilla Ice-Cream:" << endl;
    vanillaSet.display();
    cout << "\nStudents who like Butterscotch Ice-Cream:" << endl;
    butterscotchSet.display();

    // Convert the linked lists to unordered sets
    unordered_set<int> vanilla = vanillaSet.toSet();
    unordered_set<int> butterscotch = butterscotchSet.toSet();

    // a) Set of students who like both vanilla and butterscotch (Intersection of sets)
    unordered_set<int> intersection;
    for (int prn : vanilla) {
        if (butterscotch.find(prn) != butterscotch.end()) {
            intersection.insert(prn);
        }
    }

    cout << "\nStudents who like both Vanilla and Butterscotch Ice-Cream:" << endl;
    for (int prn : intersection) {
        cout << "PRN: " << prn << " ";
    }
    cout << endl;

    // b) Set of students who like either vanilla or butterscotch, but not both (Symmetric difference)
    unordered_set<int> symmetricDifference;
    for (int prn : vanilla) {
        if (butterscotch.find(prn) == butterscotch.end()) {
            symmetricDifference.insert(prn);
        }
    }
    for (int prn : butterscotch) {
        if (vanilla.find(prn) == vanilla.end()) {
            symmetricDifference.insert(prn);
        }
    }

    cout << "\nStudents who like either Vanilla or Butterscotch, but not both:" << endl;
    for (int prn : symmetricDifference) {
        cout << "PRN: " << prn << " ";
    }
    cout << endl;

    // c) Number of students who like neither vanilla nor butterscotch (Complement of union)
    unordered_set<int> unionSet = vanilla;
    for (int prn : butterscotch) {
        unionSet.insert(prn);
    }

    cout << "\nNumber of students who like neither Vanilla nor Butterscotch Ice-Cream: ";
    int totalStudents;
    cout << "Enter total number of students in the class: ";
    cin >> totalStudents;
    int studentsNeitherLike = totalStudents - unionSet.size();
    cout << studentsNeitherLike << endl;

    return 0;
}
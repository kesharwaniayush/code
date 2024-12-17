#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Function to merge two sub-arrays
void merge(vector<float>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<float> leftArr(n1), rightArr(n2);
    
    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<float>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Mid point
        mergeSort(arr, left, mid);  // Recursively sort the first half
        mergeSort(arr, mid + 1, right);  // Recursively sort the second half
        merge(arr, left, mid, right);  // Merge the two halves
    }
}

// Function to display the top 5 scores
void displayTopScores(const vector<float>& arr) {
    cout << "\nTop 5 Scores: ";
    int count = 0;
    for (int i = arr.size() - 1; i >= 0 && count < 5; i--) {
        cout << arr[i] << " ";
        count++;
    }
    cout << endl;
}

int main() {
    vector<float> percentages;
    int n;

    cout << "Enter the total number of students: ";
    cin >> n;

    // Accept percentages of students
    for (int i = 0; i < n; i++) {
        float percentage;
        cout << "Enter percentage of student " << i + 1 << ": ";
        cin >> percentage;
        percentages.push_back(percentage);
    }

    // Sorting percentages in ascending order using Merge Sort
    mergeSort(percentages, 0, n - 1);

    // Display sorted percentages
    cout << "\nSorted Percentages in Ascending Order: ";
    for (float percentage : percentages) {
        cout << percentage << " ";
    }
    cout << endl;

    // Display top 5 scores
    displayTopScores(percentages);

    return 0;
}
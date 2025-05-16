#include <iostream>

using namespace std;

// Linear Search Function
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

// Binary Search Function (Assuming the array is sorted)
int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] == target) {
            return mid;  // Element found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Element not found
}

int main() {
    const int size = 10;
    int arr[size] = {2, 4, 7, 11, 13, 16, 19, 22, 25, 29};

    int choice, target, result;

    do {
        // Display Menu
        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Linear Search
                cout << "Enter the target element: ";
                cin >> target;
                result = linearSearch(arr, size, target);
                if (result != -1) {
                    cout << "Element " << target << " found at index " << result << endl;
                } else {
                    cout << "Element " << target << " not found in the array." << endl;
                }
                break;

            case 2:
                // Binary Search
                cout << "Enter the target element: ";
                cin >> target;
                result = binarySearch(arr, size, target);
                if (result != -1) {
                    cout << "Element " << target << " found at index " << result << endl;
                } else {
                    cout << "Element " << target << " not found in the array." << endl;
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}

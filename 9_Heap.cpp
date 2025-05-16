#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    // Helper function to heapify a subtree rooted at given index
    void heapify(int index) {
        int largest = index; // Initialize largest as root
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // If left child is larger than root
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // If right child is larger than largest so far
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If largest is not the root, swap and recursively heapify the affected subtree
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor to initialize an empty heap
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }

    // Destructor to free the dynamic memory
    ~MaxHeap() {
        delete[] heap;
    }

    // Function to insert a new element into the heap
    void insert(int value) {
        if (size == capacity) {
            cerr << "Heap is full. Cannot insert element.\n";
            return;
        }

        int index = size;
        heap[size++] = value;

        // Fix the max heap property if it is violated
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Function to extract the maximum element from the heap
    int extractMax() {
        if (size == 0) {
            cerr << "Heap is empty. Cannot extract maximum.\n";
            return -1; // indicating an error
        }

        int maxElement = heap[0];
        heap[0] = heap[--size];

        // Heapify the root to maintain the max heap property
        heapify(0);

        return maxElement;
    }

    // Function to display the elements of the heap
    void display() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the heap: ";
    cin >> capacity;

    MaxHeap maxHeap(capacity);

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Extract Maximum Element\n";
        cout << "3. Display Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
                maxHeap.insert(value);
                cout << "Element inserted into the heap.\n";
                break;

            case 2:
                {
                    int maxElement = maxHeap.extractMax();
                    if (maxElement != -1) {
                        cout << "Extracted Maximum Element: " << maxElement << endl;
                    }
                }
                break;

            case 3:
                maxHeap.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}

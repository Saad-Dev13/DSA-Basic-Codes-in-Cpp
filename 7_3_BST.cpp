#include <iostream>
#include <queue> // for level order traversal
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}

    // toString method to display node information
    string toString() const {
        return "Data: " + to_string(data);
    }
};

// Function to insert a node into the BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node in a BST
Node* findMax(Node* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to search for a node in the BST
bool searchNode(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to perform pre-order traversal of the BST
void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the BST
void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Function to perform level order traversal of the BST
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    Node* root = nullptr;

    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                if (searchNode(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Node deleted.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value)) {
                    cout << "Node found.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;

            case 4:
                cout << "\nDisplay Options:\n";
                cout << "1. In-order Traversal\n";
                cout << "2. Pre-order Traversal\n";
                cout << "3. Post-order Traversal\n";
                cout << "4. Level Order Traversal\n";
                cout << "Enter display choice: ";
                int displayChoice;
                cin >> displayChoice;

                switch (displayChoice) {
                    case 1:
                        cout << "BST (In-order Traversal): ";
                        inOrderTraversal(root);
                        cout << endl;
                        break;

                    case 2:
                        cout << "BST (Pre-order Traversal): ";
                        preOrderTraversal(root);
                        cout << endl;
                        break;

                    case 3:
                        cout << "BST (Post-order Traversal): ";
                        postOrderTraversal(root);
                        cout << endl;
                        break;

                    case 4:
                        cout << "BST (Level Order Traversal): ";
                        levelOrderTraversal(root);
                        cout << endl;
                        break;

                    default:
                        cout << "Invalid display choice. Please enter a valid option.\n";
                }
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

class Graph {
private:
    int** adjacencyMatrix;
    int vertexCount;

public:
    // Constructor
    Graph(int vertices) : vertexCount(vertices) {
        // Initialize adjacency matrix with arrays
        adjacencyMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjacencyMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j) {
                adjacencyMatrix[i][j] = 0;  // Initialize with 0 (no edge)
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int vertex1, int vertex2) {
        adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
        adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1;
    }

    // Function to display the graph
    void display() {
        cout << "Graph:\n";
        for (int i = 0; i < vertexCount; ++i) {
            cout << (i + 1) << " -> ";
            for (int j = 0; j < vertexCount; ++j) {
                if (adjacencyMatrix[i][j] == 1) {
                    cout << (j + 1) << " ";
                }
            }
            cout << endl;
        }
    }

    // Function to perform BFS traversal
    void bfs(int startVertex) {
        bool* visited = new bool[vertexCount];
        for (int i = 0; i < vertexCount; ++i) {
            visited[i] = false;
        }

        int* bfsQueue = new int[vertexCount];
        int front = 0, rear = 0;

        visited[startVertex - 1] = true;
        bfsQueue[rear++] = startVertex;

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (front != rear) {
            int currentVertex = bfsQueue[front++];
            cout << currentVertex << " ";

            for (int i = 0; i < vertexCount; ++i) {
                if (adjacencyMatrix[currentVertex - 1][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    bfsQueue[rear++] = i + 1;
                }
            }
        }

        cout << endl;

        delete[] visited;
        delete[] bfsQueue;
    }

    // Function to perform DFS traversal
    void dfs(int startVertex) {
        bool* visited = new bool[vertexCount];
        for (int i = 0; i < vertexCount; ++i) {
            visited[i] = false;
        }

        int* dfsStack = new int[vertexCount];
        int top = -1;

        visited[startVertex - 1] = true;
        dfsStack[++top] = startVertex;

        cout << "DFS Traversal starting from vertex " << startVertex << ": ";

        while (top != -1) {
            int currentVertex = dfsStack[top--];
            cout << currentVertex << " ";

            for (int i = 0; i < vertexCount; ++i) {
                if (adjacencyMatrix[currentVertex - 1][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    dfsStack[++top] = i + 1;
                }
            }
        }

        cout << endl;

        delete[] visited;
        delete[] dfsStack;
    }

    // Destructor to free dynamic memory
    ~Graph() {
        for (int i = 0; i < vertexCount; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    int choice, vertex1, vertex2, startVertex;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vertices of the edge (space-separated): ";
                cin >> vertex1 >> vertex2;
                graph.addEdge(vertex1, vertex2);
                cout << "Edge added to the graph.\n";
                break;

            case 2:
                graph.display();
                break;

            case 3:
                cout << "Enter the starting vertex for BFS traversal: ";
                cin >> startVertex;
                graph.bfs(startVertex);
                break;

            case 4:
                cout << "Enter the starting vertex for DFS traversal: ";
                cin >> startVertex;
                graph.dfs(startVertex);
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

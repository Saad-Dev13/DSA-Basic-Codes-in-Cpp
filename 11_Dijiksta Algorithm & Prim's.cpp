#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;
const int INF = 1e9;

class MyGraph {
public:
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];

    MyGraph(int vertices) : V(vertices) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adj[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    void addMyEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void myDijkstra(int start) {
        int dist[MAX_VERTICES];
        bool visited[MAX_VERTICES] = {false};

        for (int i = 0; i < V; ++i) {
            dist[i] = (i == start) ? 0 : INF;
        }

        for (int count = 0; count < V - 1; ++count) {
            int u = myMinDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        // Display the shortest distances
        cout << "Shortest distances from my start node " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";
        }
    }

    void myPrim() {
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        bool inMST[MAX_VERTICES] = {false};

        int start = 0; // Choose any starting vertex
        key[start] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = myMinKey(key, inMST);
            inMST[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && adj[u][v] && adj[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        // Display the edges of the MST
        cout << "Edges of my Minimum Spanning Tree (MST):\n";
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << "\n";
        }
    }

private:
    int myMinDistance(const int dist[], const bool visited[]) {
        int minDist = INF, minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    int myMinKey(const int key[], const bool inMST[]) {
        int minKey = INF, minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main() {
    MyGraph myGraph(6);
    myGraph.addMyEdge(0, 1, 5);
    myGraph.addMyEdge(0, 2, 3);
    myGraph.addMyEdge(1, 3, 6);
    myGraph.addMyEdge(1, 2, 2);
    myGraph.addMyEdge(2, 4, 4);
    myGraph.addMyEdge(2, 5, 2);
    myGraph.addMyEdge(2, 3, 7);
    myGraph.addMyEdge(3, 5, 1);
    myGraph.addMyEdge(3, 4, -1);
    myGraph.addMyEdge(4, 5, -2);

    // Use Dijkstra's algorithm
    int myStartNode = 0;
    myGraph.myDijkstra(myStartNode);

    // Use Prim's algorithm
    myGraph.myPrim();

    return 0;
}

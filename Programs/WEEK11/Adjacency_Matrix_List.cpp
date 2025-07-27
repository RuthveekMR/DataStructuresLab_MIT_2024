#include <iostream>
#include <vector>
using namespace std;

// Function to display adjacency matrix
void displayAdjacencyMatrix(const vector<vector<int>>& matrix, int vertices) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to display adjacency list
void displayAdjacencyList(const vector<vector<int>>& adjList, int vertices) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;

    // User input: number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize the adjacency matrix and list
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    vector<vector<int>> adjList(vertices);

    // Input edges
    cout << "Enter the edges (as pairs of vertices):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // For adjacency matrix (mark both directions if undirected graph)
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove this line if directed graph

        // For adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line if directed graph
    }

    // Display the adjacency matrix
    displayAdjacencyMatrix(adjMatrix, vertices);

    // Display the adjacency list
    displayAdjacencyList(adjList, vertices);

    return 0;
}

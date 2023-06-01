#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX // Infinity

using namespace std;

// Structure to represent a vertex and its time from the source
struct Vertex {
    int index;
    int distance;

    Vertex(int i, int d) : index(i), distance(d) {}
};

// Comparison operator for the priority queue (min-heap)
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Function to initialize the single-source
void initializeSingleSource(vector<int>& distances, int source) {
    distances[source] = 0; // Distance from source to itself is 0
}

// Function to relax an edge
void relax(int u, int v, int weight, vector<int>& distances, priority_queue<Vertex, vector<Vertex>, CompareVertex>& pq) {
    if (distances[u] != INF && distances[u] + weight < distances[v]) {
        distances[v] = distances[u] + weight;
        pq.push(Vertex(v, distances[v]));
    }
}

// Dijkstra's algorithm for finding shortest paths
void dijkstraShortestPaths(vector<vector<int>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    vector<int> distances(V, INF); // Array to store the shortest time values
    vector<bool> visited(V, false); // Array to track visited vertices

    initializeSingleSource(distances, source);

    // Priority queue (min-heap) to store vertices with their time
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();

        // Skip if the vertex has already been visited
        if (visited[u])
            continue;

        visited[u] = true;

        // Iterate through all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update the distance if there is a shorter path
            if (!visited[v] && graph[u][v] != INF) {
                relax(u, v, graph[u][v], distances, pq);
            }
        }
    }

    // Print the shortest distance values
    cout << "Shortest time taken to reach from the Source city:\n";
    for (int v = 0; v < V; v++) {
        cout << "City " << v << ": " << distances[v] << "\n";
    }

    // Calculate the average of all distances
    int sum = 0;
    int count = 0;
    for (int v = 0; v < V; v++) {
        if (distances[v] != INF) {
            sum += distances[v];
            count++;
        }
    }

    // Print the average distance
    if (count > 0) {
        double average = static_cast<double>(sum) / (count-1);
        cout << "Average time taken to reach, from the Source city: " << average << "\n";
    } else {
        cout << "No reachable cities from the source.\n";
    }
}

int main() {
    // Example graph represented by the adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, INF, INF, 15, 5},
        {10, 0, 10, 30, INF, INF},
        {INF, 10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };

    int source;
    cout << "Enter the source city: ";
    cin >> source;

    dijkstraShortestPaths(graph, source);

    return 0;
}

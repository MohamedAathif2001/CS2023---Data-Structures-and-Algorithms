#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6 // Number of vertices in the graph

void primMST(const vector<vector<int>>& graph, int startNode) {
    vector<int> parent(V, -1); // Array to store constructed MST
    vector<int> key(V, INT_MAX);    // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    // Including the startNode in MST
    key[startNode] = 0;

    for (int count = 0; count < V - 1; ++count) {
        // Picking the minimum key vertex from the set of vertices not yet included in MST
        int minKey = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST set
        int u = minIndex;
        mstSet[u] = true;

        // Update key values and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight" << endl;
    for (int i = 0; i < V; ++i) {
        if (i != startNode) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode = 0; 

    primMST(graph, startNode);

    return 0;
}

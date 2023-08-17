#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to add an edge to the graph
void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to color the graph using the greedy algorithm
void greedy_coloring(vector<int> adj[], int V)
{
    // Initialize all vertices as unassigned
    vector<int> color(V, -1);

    // Assign the first color to the first vertex
    color[0] = 0;

    // A temporary array to store the used colors
    vector<bool> used(V, false);

    // Assign colors to the remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Mark all adjacent vertices as used
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (color[v] != -1)
                used[color[v]] = true;
        }

        // Find the first unused color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (used[cr] == false)
                break;

        // Assign the found color
        color[u] = cr;

        // Reset the used colors
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (color[v] != -1)
                used[color[v]] = false;
        }
    }

    // Print the coloring
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " ---> Color "
             << color[u] << endl;
}

// Driver code
int main()
{
    // Create a graph with 5 vertices
    int V = 5;
    vector<int> adj[V];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 3);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 4);

    // Color the graph using the greedy algorithm
    greedy_coloring(adj, V);

    return 0;
}

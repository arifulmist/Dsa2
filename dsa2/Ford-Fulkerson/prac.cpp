#include <bits/stdc++.h>
using namespace std;

#define V 6  // Change this if the number of vertices varies

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < V; i++) {
            if (!visited[i] && rGraph[u][i] > 0) {
                if (i == t) {
                    parent[i] = u;
                    return true;
                }
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int i = t; i != s;i = parent[i]) {
            int u = parent[i];
            path_flow = min(path_flow, rGraph[u][i]);
        }

        for (int i = t; i != s; i = parent[i]) {
            int u = parent[i];
            rGraph[u][i] -= path_flow;
            rGraph[i][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    vector<vector<int>> graph(V, vector<int>(V, 0));

    int edges;
   // cout << "Enter the number of edges: ";
    cin >> edges;

    //cout << "Enter the edges in format (u v capacity):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    int source, sink;
    //cout << "Enter the source and sink nodes: ";
    cin >> source >> sink;

    cout << "The maximum possible flow is " << fordFulkerson(graph,source,sink) << endl;

    return 0;
}
/*
8
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5

*/
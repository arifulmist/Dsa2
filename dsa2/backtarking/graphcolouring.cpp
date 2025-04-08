#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
    for (int i = 0; i < graph.size(); i++)
        if (graph[node][i] && colors[i] == color)
            return false;
    return true;
}

bool graphColoring(vector<vector<int>>& graph, vector<int>& colors, int node, int m) {
    if (node == graph.size()) {
        for (int color : colors) cout << color << " ";
        cout << "\n";
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, colors, node, c)) {
            colors[node] = c;
            if (graphColoring(graph, colors, node + 1, m)) return true;
            colors[node] = 0;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors: ";
    cin >> m;

    vector<int> colors(n, 0);
    graphColoring(graph, colors, 0, m);
    return 0;
}

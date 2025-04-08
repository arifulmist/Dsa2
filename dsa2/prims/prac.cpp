#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5; // Maximum number of nodes
vector<pair<ll, ll>> adj[N]; // Adjacency list for the graph
vector<bool> vis(N, false); // To track visited vertices

void prims(ll s, ll v) {
    ll ans = 0;
    // Priority queue to store pairs of {weight, vertex}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    // Initialize key values for each vertex and parent array
    vector<ll> key(v, INT_MAX), par(v, -1);
    key[s] = 0; // Start from the source vertex
    pq.push({0, s}); // Push the starting vertex with weight 0

    while (!pq.empty()) {
        ll u = pq.top().second; // Get the vertex with the minimum key
        pq.pop(); // Pop the top element

        if (vis[u]) continue; // Skip if already visited

        vis[u] = true; // Mark the vertex as visited
        ans += key[u]; // Add its key value to the total MST weight

        // Explore all the adjacent vertices
        for (auto ed : adj[u]) {
            ll v = ed.first;
            ll ww = ed.second;
            if (!vis[v] && ww < key[v]) { // If not visited and a smaller weight edge
                key[v] = ww; // Update the key for the adjacent vertex
                pq.push({key[v], v}); // Push the updated key to the priority queue
                par[v] = u; // Set the parent of the vertex
            }
        }
    }
    cout << ans << "\n"; // Output the MST weight
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input the edges
    while (m--) {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    prims(0, n); // Start the Prim's algorithm from vertex 0

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1000;
vector<pair<ll, ll>> vp[N];
ll dis[N], par[N];
bool vis[N];
ll n, m;

void dij(ll s) {
    for (ll i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    dis[s] = 0;
    par[s] = -1;
    priority_queue<pair<ll, ll>> pq;
    pq.push({-dis[s], s});
    while (!pq.empty()) {
        pair<ll, ll> pr = pq.top();
        pq.pop();
        ll u = pr.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i : vp[u]) {
            ll child = i.first;
            ll cost = i.second;
            if (dis[child] > cost + dis[u]) {
                dis[child] = cost + dis[u];
                par[child] = u;
                pq.push({-dis[child], child});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    while (m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        vp[a].push_back({b, w});
    }

    dij(1); // Run Dijkstra's algorithm from the source node (1)

    for (ll i = 1; i <= n; i++) {
        cout << "Node->" << i << " is at distance " << dis[i] << "\n";
    }

    cout << "Shortest paths from node 1:\n";
    for (ll i = 1; i <= n; i++) {
        if (dis[i] == INT_MAX) {
            cout << "Path to node " << i << ": No path exists\n";
        } else {
            cout << "Path to node " << i << ": ";
            vector<ll> p;
            ll xx = i; // Start from the current node
            while (xx != -1) {
                p.push_back(xx);
                xx = par[xx];
            }
            reverse(p.begin(), p.end());
            for (auto j : p) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

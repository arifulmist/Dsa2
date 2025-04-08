#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

struct Edge {
    ll to, weight, toll;
};

vector<Edge> graph[1005];
ll dist[1005][105]; // Distance array: dist[node][toll_spent]
ll n, m, K;

void dijkstra(ll start) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= K; j++) {
            dist[i][j] = INF;
        }
    }

    dist[start][0] = 0;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<>> pq; 
    pq.push({0, {start, 0}}); // {distance, {node, toll_spent}}

    while (!pq.empty()) {
        auto info = pq.top();
        pq.pop();
        ll u = info.first;
        ll toll_spent = info.second.second;

        if (u > dist[u][toll_spent]) continue;

        for (auto &edge : graph[u]) {
            ll v = edge.to;
            ll weight = edge.weight;
            ll toll = edge.toll;

            if (toll_spent + toll <= K) {
                if (dist[v][toll_spent + toll] > u + weight) {
                    dist[v][toll_spent + toll] = u + weight;
                    pq.push({dist[v][toll_spent + toll], {v, toll_spent + toll}});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> K;

    for (ll i = 0; i < m; i++) {
        ll uu, v, w, t;
        cin >> uu >> v >> w >> t;
        graph[uu].push_back({v, w, t});
    }

    dijkstra(1);

    ll result = INF;
    for (ll i = 0; i <= K; i++) {
        result = min(result, dist[n][i]);
    }

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}

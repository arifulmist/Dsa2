#include <bits/stdc++.h>
using namespace std;

#define granite_state ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define line cout << "\n"

class edge {
public:
    int u, v, w;
    edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

ll par[1000];
vector<ll> level(10000);

void make(int x) {
    par[x] = x;
}

int find(int x) {
    if (x == par[x]) {
        return x;
    }
    return par[x] = find(par[x]);
}

void union_byrank(int a, int b) {
    ll la = find(a);
    ll lb = find(b);
    if (level[la] > level[lb]) {
        par[lb] = la;
    } else if (level[lb] > level[la]) {
        par[la] = lb;
    } else {
        par[la] = lb;
        level[lb]++;
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

signed main() {
    granite_state

    int n, e;
    cin >> n >> e;
    vector<edge> edges;

    // Read edges
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(edge(a, b, c));
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Initialize DSU
    for (int i = 0; i < n; ++i) {
        make(i);
    }

    vector<edge> mst_edges; // Store edges in the MST
    int mst_cost = 0;

    // Kruskal's algorithm
    for (auto e : edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (find(u) != find(v)) {
            union_byrank(u, v);
            mst_cost += w;
            mst_edges.push_back(e);
        }
    }

    cout << "The MST total cost: " << mst_cost << endl;
    line;
    cout << "Edges in the MST: " << endl;
    for (auto e : mst_edges) {
        cout << e.u << " -- " << e.v << " with weight " << e.w << endl;
    }
    line;

    // Count the number of possible MSTs
    map<int, vector<pair<int, int>>> weight_groups;
    for (auto e : mst_edges) {
        int u = e.u, v = e.v, w = e.w;
        weight_groups[w].push_back({u, v});
    }

    int total_msts = 1;
    for (const auto& group : weight_groups) {
        total_msts *= group.second.size(); // Number of ways to form the MST using these edges
    }

    cout << "Total number of possible MSTs: " << total_msts << endl;

    return 0;
}

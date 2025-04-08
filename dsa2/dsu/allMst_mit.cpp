#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1e5 + 5;
vector<int> parent;
vector<int> level;

class Edge
{
public:
    int u;
    int v;
    int w;

    Edge() {}
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int find_(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = find_(parent[node]);
}

void union_(int node1, int node2)
{
    int leader1 = find_(node1);
    int leader2 = find_(node2);

    if (leader1 == leader2)
        return;

    if (level[leader1] > level[leader2])
    {
        parent[leader2] = leader1;
    }
    else if (level[leader2] > level[leader1])
    {
        parent[leader1] = leader2;
    }
    else
    {
        parent[leader2] = leader1;
        level[leader1]++;
    }
}

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

bool isValidMst(vector<Edge> &edges, int n, vector<Edge> &mst, int &cost)
{
    parent.assign(n + 1, -1);
    level.assign(n + 1, 0);

    int edgeCount = 0;
    cost = 0;

    for (auto &edge : edges)
    {
        int leaderU = find_(edge.u);
        int leaderV = find_(edge.v);

        if (leaderU != leaderV)
        {
            union_(edge.u, edge.v);
            cost += edge.w;
            mst.push_back(edge);
            edgeCount++;
        }
    }
    return edgeCount == n - 1;
}

void findAllMSTs(vector<Edge> &edges, int n, int mstCost, vector<Edge> &current, int index, vector<vector<Edge>> &allMSTs)
{
    if (index == edges.size())
    {
        if (current.size() == n - 1)
        {
            vector<Edge> mst;
            int cost = 0;

            if (isValidMst(current, n, mst, cost) && cost == mstCost)
            {
                allMSTs.push_back(mst);
            }
        }
        return;
    }

    findAllMSTs(edges, n, mstCost, current, index + 1, allMSTs);

    current.push_back(edges[index]);
    findAllMSTs(edges, n, mstCost, current, index + 1, allMSTs);
    current.pop_back();
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), compare);

    vector<Edge> mst;
    int totalCost = 0;

    parent.assign(n + 1, -1);
    level.assign(n + 1, 0);

    for (auto edge : edges)
    {
        int leaderU = find_(edge.u);
        int leaderV = find_(edge.v);

        if (leaderU != leaderV)
        {
            totalCost += edge.w;
            mst.push_back(edge);
            union_(edge.u, edge.v);
        }
    }

    cout << "Original MST cost: " << totalCost << endl;

    vector<vector<Edge>> allMSTs;
    vector<Edge> current;
    findAllMSTs(edges, n, totalCost, current, 0, allMSTs);

    for (auto &mst : allMSTs)
    {
        cout << "MST:" << endl;
        for (auto &edge : mst)
        {
            cout << edge.u << " --- " << edge.v << " cost " << edge.w << endl;
        }
        cout << endl;
    }

    cout << "Total MSTs: " << allMSTs.size() << endl;

    return 0;
}

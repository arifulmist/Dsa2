#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6;
vector<pair<ll,ll>>adj[N];
ll dis[N],par[N];
bool vis[N];
ll n,e;
void dijkstra(ll src)
{
    for(ll i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
        vis[i]=false;
    }
    dis[src]=0;
    priority_queue<pair<ll,ll>>pp;
    pp.push({-dis[src],src});
    while(!pp.empty())
    {
        auto pr=pp.top();
        pp.pop();
        ll nn=pr.second;
        if(vis[nn]) continue;
        vis[nn]=true;
        for(auto ch:adj[nn])
        {
            ll child=ch.first;
            ll cost=ch.second;
            if(dis[child]>cost+dis[nn])
            {
                dis[child]=cost+dis[nn];
                pp.push({-dis[child],child});
            }
        }
    }
}
int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++) {
        cout << "Node->" << i << " is at distance " << dis[i] << "\n";
    }
     
}
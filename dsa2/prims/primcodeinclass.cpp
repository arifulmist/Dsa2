#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll v,e;
    cin>>v>>e;
    vector<pair<ll,ll>>g[v];
    for(ll i=0;i<e;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    } 
    int key[v],par[v],mst[v];
    for(ll i=0;i<v;i++)
    {
        key[i]=INT_MAX;
        par[i]=-1;
        mst[i]=0;
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    key[0] = 0;
    par[0]=-1;
    pq.push({0, 0}); // {weight, vertex}
    

    
    //for(ll i=0;i<v;i++) 
    while(!pq.empty()){
        ll u = pq.top().second;//vertex
        pq.pop();
        mst[u] = 1;//visit
        
        for(auto it : g[u]) {
            ll v = it.first;
            ll weight = it.second;
            if(mst[v] == 0 && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                par[v] = u;
            }
        }
    }
    ll cost=0;
    for(ll i=0;i<v;i++)
    {
        cost+=key[i];
    }
    cout<<cost<<"\n";
    // for(ll i = 1; i < v; i++) {
    //     cout << par[i] << " - " << i << "\n";
    // }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
#define V 6
bool bfs(vector<vector<int>>&rgrp,int s,int t,vector<int>&par)
{
    vector<bool>vis(V,false);
    queue<int>p;
    p.push(s);
    par[s]=-1;
    vis[s]=true;
    while(!p.empty())
    {
        int u=p.front();
        p.pop();
        for(ll i=0;i<V;i++)
        {
            if(!vis[i]&& rgrp[u][i]>0)
            {
                if(i==t)
                {
                    par[i]=u;
                    return true;
                }
                p.push(i);
                par[i]=u;
                vis[i]=true;
            }
        }
    }
return false;
}
int ford(vector<vector<int>>&grp,int s,int t)
{
    vector<vector<int>>rgrp=grp;
    vector<int>par(V);
    int mxflow=0;
    while(bfs(rgrp,s,t,par))
    {
    ///Finding the Minimum Capacity in the Path
      int pathmx=INT_MAX;

      for(ll i=t;i!=s;i=par[i])
      {
        int u=par[i];
        pathmx=min(pathmx,rgrp[u][i]);
      }
      /// resudal graph
      for(ll i=t;i!=s;i=par[i])
      {
        int u=par[i];
        rgrp[u][i]-=pathmx;
        rgrp[i][u]+=pathmx;
      }
      mxflow+=pathmx;
    }
    return  mxflow;
}
int main()
{
    vector<vector<int>>grp(V,vector<int>(V,0));///2D vector
    int e;
    cin>>e;
    while(e--)
    {
    int u,v,ca;
    cin>>u>>v>>ca;
    grp[u][v]=ca;
    }
    int s,ss;//source sink
    cin>>s>>ss;
    cout<<ford(grp,s,ss);

     
}
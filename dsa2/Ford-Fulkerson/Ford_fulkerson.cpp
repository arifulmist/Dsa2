#include <bits/stdc++.h>
using namespace std;
#define granite_state ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define line cout << "\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define vsb (v).begin(),(v).end()
#define vse (v).rbegin(),(v).rend()
#define spc " "
#define pb push_back
#define pf push_front;

bool bfs(int s,int e,vector<int>&par,vector<vector<int>>&rgrp,int n)
{
      vector<int>vis(n,0);
      queue<int>q;
      q.push(s);
      vis[s] = true;
      par[s] = -1;
      while(!q.empty())
      {
           int tp = q.front();
           q.pop();
           for(int i=0;i<n;i++)
           {
                if(!vis[i] && rgrp[tp][i]>0)
                {
                     if(i==e)
                     {
                         par[i] = tp;
                         return true;
                     }
                     q.push(i);
                     vis[i] = true;
                     par[i] = tp;
                }
           }
      }
      return false;
}
int Ford_Fulkerson(int s,int e,vector<vector<int>>&grp,int n)
{
     vector<vector<int>>rgrp(n,vector<int>(n));
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
             rgrp[i][j] = grp[i][j];
        }
     }
     vector<int>par(n);
     int mx_flow = 0;
     while(bfs(s,e,par,rgrp,n))
     {
          int path_flow = INT_MAX;
          int tmp;
          for(int i=e;i!=s;i=par[i])
          {
              tmp = par[i];
              path_flow = min(path_flow,rgrp[tmp][i]);
          }
          for(int i=e;i!=s;i=par[i])
          {
               tmp = par[i];
               rgrp[tmp][i] -= path_flow;
               rgrp[i][tmp] += path_flow;
          }
          mx_flow+=path_flow;
     }
     return mx_flow;
}
signed main()
 {
    granite_state
    int n,e;
    cin>>n>>e;
    vector<pair<int,pair<int,int>>>edg(e);
    for(int i=0;i<e;i++)
    {
         int a,b,c;
         cin>>a>>b>>c;
         edg[i] = {a,{b,c}};
    }
    vector<vector<int>>grp(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
         grp[edg[i].first][edg[i].second.first] = edg[i].second.second;
         grp[edg[i].second.first][edg[i].first] = edg[i].second.second;
    }
    cout<<Ford_Fulkerson(0,n-1,grp,n)<<endl;
}

    ////////////////////////////////////////////////////
    //                                                 //
    //                 A                               //
    //                                                 //
    //                 L                               //
    //                                                 //
    //                 I                               //
    //                                                 //
    //                 F                               //
    /////////////////////////////////////////////////////
//think simply, it's always easier than it seems at first
    //PEN AND PAPER instead of ms paint
    //keep at it even if it feels exhausting(we're not doing this for fun anymore)
    //2 GHONTAR AGER EDITORIAL DHORBI NA
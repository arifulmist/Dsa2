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

signed main()
 {
    granite_state
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<e;i++)
    {
         int a,b,c;
         cin>>a>>b>>c;
         adj[a].push_back({b,c});
         adj[b].push_back({a,c});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>par(1,vector<int>(n));
    vector<vector<int>>key(1,vector<int>(n,INT_MAX));
    vector<bool>mst(n,false);
    par[0][0] = 0;
    key[0][0] = 0;
    pq.push({0,{0,0}});
    while(!pq.empty())
    {
        auto tp = pq.top();
        int wt = tp.first;
        int u = tp.second.first;
        int i = tp.second.second;
        pq.pop();
        if(mst[u]) continue;
        mst[u] = true;
        for(auto x:adj[u])
        {
             int b = x.first;
             int a = x.second;
              if (!mst[b] && key[i][b] > a) 
              {
                key[i][b] = a;
                par[i][b] = u;
                pq.push({a, {b, i}});
            }
            else if (!mst[b] && key[i][b] == a) 
            {
                int j = i + 1;
                key.push_back(key[i]);
                par.push_back(par[i]); 
                key[j][b] = a;
                par[j][b] = u;
                pq.push({a, {b, j}});
            }
        }
    }
    int s = 0;
    for(int i=0;i<key[0].size();i++)
    {
         s+=key[0][i];
    }
    cout<<"The mst total cost : "<<s<<endl;
    cout<<endl;
    for(int i=0;i<par.size();i++)
    {
        cout<<" MST : "<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
             cout<<j<<" --> "<<par[i][j]<<" ---> "<<key[i][j]<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    
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
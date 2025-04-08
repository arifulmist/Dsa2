#include<bits/stdc++.h>
using namespace std;
#define ll long long
int par[100];
int n,e;
vector<ll>level(10000);
vector<ll>graph[1000];
void make(int x)
{
    par[x]=x;
}
int find(int x)
{
    if(x==par[x])
    {
        return x;
    }
   return par[x] =find(par[x]);
}
void union_a(int a,int b)//connection
{
    int pa=find(a);
    int pb=find(b); 
    if(pa==pb) return;
    par[pb]=pa;// normal union
    //par[max(pa,pb)]=min(pa,pb);// if minimum is always par
    //if(rank(pa)<rank(pb)) par[pa]=pb;
    //else par[pb]=pa;
}
void rank_a(int a,int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    cin>>n>>e;
    for(ll i=1;i<=n;i++)
    {
        make(i);
    }
    
     vector<pair<int,pair<int,int>>edg;
     for(ll i=0;i<e;i++)
     {
        int a,b,w;
        cin>>a>>b>>w;
        edg.push_back({w,{a,b}});
     }
     sort(edg.begin(),edg.end());
     for(auto i:edg)
     {
       cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<" ";
       cout<<endl;
     }
     for(auto v:edg)
     {
        
     }
//     for(ll i=1;i<=e;i++)
//     {
//         cin>>a>>b;
//         rank_a(a,b);

//     }
   
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//       // cout<<i<<" "<<find(i)<<"\n";
//       if(par[i]==i)
//       {
//         cnt++;
//       }
//     }
// cout<<cnt;
    
     
}







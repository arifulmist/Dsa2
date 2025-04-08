#include<bits/stdc++.h>
using namespace std;
#define ll long long
class edge
{
  public:
  int u,v,w;
  edge(int u,int v,int w)
  {
    this->u=u;
    this->v=v;
    this->w=w;
  }
};
ll par[1000];
vector<ll>level(10000);
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
    return par[x]=find(par[x]);
}
void union_byrank(int a,int b)
{
    ll la=find(a);
    ll lb=find(b);
    if(level[la]>level[lb])
    {
        par[lb]=la;
    }
    else if(level[lb]>level[la])
    {
        par[la]=lb;
    }
    else 
    {
        par[la]=lb;
        level[lb]++;
    }

}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
   int n,e;
   cin>>n>>e;
   for(ll i=0;i<n;i++)
   {
    make(i);
   }
   vector<edge>edg;
   while(e--)
   {
    int u,v,w;
    cin>>u>>v>>w;
    edg.push_back(edge(u,v,w));
   }  
   sort(edg.begin(),edg.end(),cmp);
   ll totalcost=0;
   for(auto ed:edg)
   {
       ll la=find(ed.u);
       ll lb=find(ed.v);
       if(la==lb)
       {
        continue;
       }
       else{
        union_byrank(ed.u,ed.v);
        totalcost+=ed.w;
       }
   }
   cout<<totalcost;
   
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class edge{
    public:
    int u,v,w;
    edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
vector<ll>par(1000),level(1000);
void make(ll x)
{
    par[x]=x;
}
ll find(ll a)
{
   if(a==par[a])
   {
    return a;
   }
   return par[a]=find(par[a]);
}
void union_byrank(ll a,ll b )
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
vector<edge>edg,mstedg;
while(e--)
{
    ll a,b,c;
    cin>>a>>b>>c;
    edg.push_back(edge(a,b,c));
}
sort(edg.begin(),edg.end(),cmp);
for(auto i:edg)
{
    cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
}
for(ll i=0;i<n;i++) make(i);
ll mn=0;
for(auto i:edg)
{
    ll u=i.u;
    ll v=i.v;
    ll w=i.w;
    if(find(u)==find(v)) continue;
    
        union_byrank(u,v);
        mn+=w;
       mstedg.push_back(i);
    
}
cout<<mn<<endl;
for(auto i:mstedg)
{
    cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
}
map<ll,vector<pair<ll,ll>>>wedg;// possible mst
for(auto i:mstedg)
{
    ll u=i.u;
    ll v=i.v;
    ll w=i.w;
    wedg[w].push_back({u,v});
}
ll cc=1;
for(auto j:wedg)
{
    cc*=j.second.size();
}
cout<<cc<<endl;
}
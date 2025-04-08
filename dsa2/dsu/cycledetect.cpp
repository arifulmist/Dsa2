#include<bits/stdc++.h>
using namespace std;
#define ll long long 
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
int main()
{

   int n,e;
   cin>>n>>e;
   for(ll i=0;i<n;i++)
    {
        make(i);
    }
     bool cycle=false;
     while(e--)
     {
        ll a,b;
       cin>>a>>b;
       ll la=find(a);
       ll lb=find(b);
       if(la==lb)
       {
        cycle =true;
        break;
       }
        else 
        {
            union_byrank(a,b);
        }
     }
     if(cycle) cout<<"Yes cycle detected\n";
     else 
     {
        cout<<"No cycle\n";
     }

}
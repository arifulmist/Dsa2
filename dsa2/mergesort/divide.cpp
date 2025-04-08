#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"

void divide(int arr[],int l,int r)
{
    if(l<r)
    {
        ll mid=l+(r-l)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
    }
}
int main()
{
    ll m;
    cin>>m;
    ll a[m];
    for(ll i=0;i<m;i++)
    {
        cin>>a[i];
    } 
    divide(a,0,n-1);
    merge(a,0,3,m-1);
    
     for(ll i=0;i<m;i++)
     {
        cout<<a[i]<<" ";
     }
}
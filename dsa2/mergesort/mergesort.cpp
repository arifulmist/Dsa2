#include<bits/stdc++.h>
using namespace std;
#define ll int 
#define pi pair<ll,ll>
#define nl "\n"
void merge(ll arr[],int l,int r,int n)
{
    //int mid = l + (r - l) / 2;
    int leftsize = r - l + 1;//mid-start+1
    int rightsize = n - r;//end-mid
    ll left[leftsize],right[rightsize];
    ll k=0;
    for(ll i=l;i<=r;i++)
    {
        left[k]=arr[i];
        k++;
    }
    k=0;
    for(ll i=r+1;i<=n;i++)
    {
        right[k]=arr[i];
        k++;
    }
     
      ll i=0,j=0,cur=l;
      while(i<leftsize && j<rightsize)
      {
        if(left[i]<right[j])
        {
            arr[cur]=left[i];
            i++;
        }
        else 
        {
            arr[cur]=right[j];
            j++;
        }
        cur++;
      }/// 3 ta case hote pare left ses hbe na  or right ses hbe na or both
     while(i<leftsize)
     {
        arr[cur]=left[i];
        i++;
        cur++;
        
     }
     while(j<rightsize)
     {
        arr[cur]=right[j];
        j++;
        cur++;
        
     }


}
void divide(int arr[],int l,int r)
{
    if(l<r)
    {
        ll mid=l+(r-l)/2;
        divide(arr,l,mid);
        divide(arr,mid+1, r); 
        merge(arr,l,mid,r);
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
    divide(a,0,(m-1));
   // merge(a,0,3,m-1);
    
     for(ll i=0;i<m;i++)
     {
        cout<<a[i]<<" ";
     }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
void merge(ll arr[],int l,int r,int n)
{
    //int mid = l + (r - l) / 2;
    int leftsize = r - l + 1;
    int rightsize = n - r;
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
      while(i<leftsize&& j<rightsize)
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


    // ll left[leftsize], right[rightsize];

    // for (int i = 0; i < leftsize; i++)
    //     left[i] = arr[l + i];
    // for (int i = 0; i < rightsize; i++)
    //     right[i] = arr[mid + 1 + i];

    // int i = 0, j = 0, k = l;
    // while (i < leftsize && j < rightsize) {
    //     if (left[i] <= right[j]) {
    //         arr[k] = left[i];
    //         i++;
    //     } else {
    //         arr[k] = right[j];
    //         j++;
    //     }
    //     k++;
    // }

    // while (i < leftsize) {
    //     arr[k] = left[i];
    //     i++;
    //     k++;
    // }

    // while (j < rightsize) {
    //     arr[k] = right[j];
    //     j++;
    //     k++;
    // }
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
    merge(a,0,3,m-1);
    
     for(ll i=0;i<m;i++)
     {
        cout<<a[i]<<" ";
     }
}
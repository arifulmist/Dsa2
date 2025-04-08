#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
int mcmtable(vector<int>&arr)
{
    int nn;arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(ll i=1;i<n;i+=1)
    {
        dp[i][i]=0;
    }
    for(ll len=2;len<n;i++)
    {
        for(ll i=1;i<=n-len;i++)
        {
            int j=i+len-1;

            dp[i][j]=INT_MAX;
            for(ll k=i;k<j;k++)
            {
                int cost1=dp[i][k];
                int cost2=dp[k+1][j];
                int cur=cost1+cost2+arr[i-1]*(arr[k])*arr[j];
                dp[i][j]=min(dp[i][j],cur);
            }
        }
    }
    return dp[1][n-1];
    for(auto x:dp)
    {
        for(auto y:x)
        {
            cout<<y<<" ";

        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;

      vector<int>arr;
      for(ll i=0;i<n;i++)
        cin>>arr[i];
    cout<<mcmtable(arr);


}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
int main()
{
     
    int n;
    cin>>n;
    vector<int>wei(n+1),val(n+1);
    for(ll i=0;i<n;i++)
    {
        cin>>wei[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            if(wei[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j-wei[i-1]]+val[i-1],dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<< dp[n][w];

}
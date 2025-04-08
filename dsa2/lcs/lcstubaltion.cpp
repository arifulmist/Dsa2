#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
int main()
{
     string s,ss;
     cin>>s>>ss;
     ll n=s.size();
     ll m=ss.size();
     ll dp[n+1][m+1];
     for(ll i=0;i<=n;i++)
     {
        for(ll j=0;j<=m;j++)
        {
            if(i==0|| j==0) dp[i][j]=0;
        }
     }
     for(ll i=1;i<=n;i++)
     {
        for(ll j=1;j<=m;j++)
        {
            if(s[i-1]==ss[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
     }
     cout<<dp[n][m]<<nl;
     for(ll i=0;i<=n;i++)
     {
        for(ll j=0;j<=m;j++)
        {
           cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
     }
     // print lcs
     ll i=n;
     ll j=m;
     string ans;
     while(i!=0&& j!=0)
     {
        if(s[i-1]==ss[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else 
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else 
            {
                i--;

            }
        }
     }
     reverse(ans.begin(),ans.end());
     cout<<ans<<nl;

}
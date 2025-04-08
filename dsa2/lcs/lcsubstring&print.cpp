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
                dp[i][j]=0;            }
        }
     }
     ll mx=0,ci,cj;
     for(ll i=0;i<=n;i++)
     {
        for(ll j=0;j<=m;j++)
        {
         if(dp[i][j]>mx)
         {
            mx=dp[i][j];
            ci=i;
            cj=j;
         }
        }
     }
     // print lcsubstring
     ll i=ci;
     ll j=cj;
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
           break;
        }
     }
     reverse(ans.begin(),ans.end());
     cout<<ans<<nl;

}
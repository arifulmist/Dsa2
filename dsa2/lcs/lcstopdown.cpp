#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
ll dp[1000][100];
ll lcs(string s,string d,int n,int m)
{
   
    if(n==0||m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==s[m-1])
    {
        int ans=lcs(s,d,n-1,m-1);
        return dp[n][m]=ans+1;
    }
    else 
    {
        int ans1=lcs(s,d,n-1,m);
        int ans2=lcs(s,d,n,m-1);
        return dp[n][m]=max(ans1,ans2);
    }
}
int main()
{
     string a,b;
     cin>>a>>b;
     memset(dp,-1,sizeof(dp));
     cout<<lcs(a,b,a.size(),b.size());
}
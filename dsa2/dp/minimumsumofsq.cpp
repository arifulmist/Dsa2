#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
ll n;
 vector<ll> dp(n + 1, INT_MAX);
ll rec(int n)
{
    if(n<=3) return n;
    if(dp[n]!=INT_MAX) return dp[n];
     for (ll j = 1; j * j <= n; ++j)
         {
            ll mx=dp[n-j*j] + 1;
            dp[n] = min(dp[n], mx);
         }
   return dp[n];
}
int main()
{
    
    cin>>n;
    
   cout<<rec(n);
}
/*
recursion :
ll minSquamn(ll n) {
    
    if (n <= 3) return n;

    ll mn = n; 
    for (ll i = 1; i * i <= n; ++i)
     {
         ll xx=1 + minSquamn(n - i * i);
        mn = min(mn,xx );
    }

    return mn;
    }
 */
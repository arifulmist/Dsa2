#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define nl "\n"
vector<vector<int>> memo(50, vector<int>(50, -1));
int lcs1(string &s1, string &s2, int n1, int n2)
{
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    if (memo[n1][n2] != -1)
    {
        return memo[n1][n2];
    }
    if (s1[n1 - 1] == s2[n2 - 1])
    {
        memo[n1][n2] = 1 + lcs1(s1, s2, n1 - 1, n2 - 1);
    }
    else
    {
        memo[n1][n2] = max(lcs1(s1, s2, n1 - 1, n2), lcs1(s1, s2, n1, n2 - 1));
    }
    return memo[n1][n2];
}

int lcs(string &s1, string &s2, int n1, int n2)
{
    cout << "lcs(" << n1 << " ," << n2 << " )" << endl;
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    if (s1[n1 - 1] == s2[n2 - 1])
    {
        return 1 + lcs(s1, s2, n1 - 1, n2 - 1);
    }
    else
    {
        return max(lcs(s1, s2, n1 - 1, n2), lcs(s1, s2, n1, n2 - 1));
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();

    int ans = lcs(s1, s2, n1, n2);
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mcm_table(vector<int> &arr, vector<vector<int>> &bracket)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];
                int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
                if (curr_cost < dp[i][j])
                {
                    dp[i][j] = curr_cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
    for(auto x: dp)
    {
        for(auto y: x)
            cout << y << " ";
        cout << uwu;
    }

    return dp[1][n - 1];
    
}
void print_order(int i , int j , int n , vector<vector<int>> &bracket , char name)
{
    if(i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    print_order(i , bracket[i][j] , n , bracket , name);
    print_order(bracket[i][j] + 1 , j , n , bracket , name);
    cout << ")";
}
int main()
{
    Onii_chan;
    int n;
    cin >> n;
   // vector<int> arr = {1, 2, 3, 4, 3};
    vector<int> arr(n + 1);
    vector<vector<int>> bracket(n, vector<int>(n, 0));
    for(int i = 0; i <= n; i++)
        cin >> arr[i];
    cout << mcm_tabul(arr,bracket) << uwu;
   
   // cout << mcm_table(arr, bracket);
    print_matrix(bracket, 1, n - 1);
   
}
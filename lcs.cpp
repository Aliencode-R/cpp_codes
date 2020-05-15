#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
#define pb push_back

void lcs(string a, string b)
{
    int m = a.size();
    int n = b.size();

    int dp[m+1][n+1] ;
    // memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[m-i] == b[n-j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[m][n];

    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    cin >> a >> b;
    lcs(a,b);
    return 0;
}
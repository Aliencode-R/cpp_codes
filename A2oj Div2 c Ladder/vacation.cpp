#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#include <stdio.h>
#include <string.h>
#define sz(x) (int((x).size()))
// #define int long long

int lcs(string s1, string s2)
{

    int m = s1.size(), n = s2.size();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; 
    // int i = 1; 
    int Case = 0;
    while(getline(cin, s)) {
        if(s == "#") break;
        // cin >> t;
        getline(cin, t);
        // memset(dp, -1, sizeof dp);

        int a =  lcs(s, t);
        // cout << a;
        printf("Case #%d: you can visit at most %d cities.\n", ++Case, a);
        // cout << "Case #" << i++ << ": you can visit at most " << a << " cities." << endl;
    }
    return 0;
}










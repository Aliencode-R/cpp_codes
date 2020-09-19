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
#define sz(x) (int((x).size()))
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; cin >> s >> t;
    int n = s.size(); 
    int m = t.size();
    bool dp[m+1][n+1];
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for(int i = 1; i <= m; i++) {
        dp[i][0] = false;
        if(t[i-1] == '*') {
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            char ct = t[i-1];
            char cs = s[j-1];

            if(ct == '*') {
                dp[i][j] = dp[i-1][j] or dp[i][j-1] or dp[i-1][j-1];
            } else if (ct == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else {
                if(ct == cs and dp[i-1][j-1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

    if(dp[m][n]) {
        cout << "MATCHED";
    } else {
        cout << "NOT MATCHED";
    }



    // for(int i = 0; i <= m; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    return 0;
}
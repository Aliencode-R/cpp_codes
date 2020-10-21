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
#define exp 1e18
#define sz(x) (int((x).size()))
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n ; 
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    string s[n], g[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        g[i] = s[i];
        reverse(all(g[i]));
    }

    int dp[n][2];
    // memset(dp, -1, sizeof dp);
    for(int i = 0; i <n ; i++) dp[i][0] = dp[i][1] = exp;
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(int i = 1; i < n; i++) {
        if(s[i-1] <= s[i]) {
            dp[i][0] = dp[i-1][0];
        }
        if(s[i] >= g[i-1]) {
            dp[i][0] = min(dp[i-1][1], dp[i][0]);
        }
        if(g[i] >= s[i-1]) {
            dp[i][1] = dp[i-1][0] + c[i];
        }
        if(g[i] >= g[i-1]) {
            dp[i][1] = min(dp[i-1][1] + c[i], dp[i][1]);
        }
    }
    int ans = min(dp[n-1][1], dp[n-1][0]);
    if(ans == exp) cout << -1;
    else cout << ans;

    return 0;
}
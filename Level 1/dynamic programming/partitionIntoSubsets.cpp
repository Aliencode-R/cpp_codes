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
    int n, k; cin >> n >> k;
    if(n == 0 or k == 0 or n < k) {
        cout << 0;
        return 0;
    }
    int dp[k+1][n+1];
    memset(dp, 0, sizeof dp);
    for(int t = 1; t <= k; t++) {
        for(int p = 1; p <= n; p++) {
            if(p < t) {
                dp[t][p] = 0;
            }
            else if (p == t) {
                dp[t][p] = 1;
            } 
            else {
                dp[t][p] = dp[t-1][p-1] + t * dp[t][p-1];
            }
        }
    }
    
    cout << dp[k][n]; 
    return 0;
}
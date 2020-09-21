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
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
// #define int long long
#define mod 1000003

int helper(int n, int k, int bit, int dp[101][101][2]) {
    if(n == 1 and k == 0) return 1;
    if(k < 0 or k >= n) return 0;

    if(dp[n][k][bit] != -1) return dp[n][k][bit];

    int ans = 0;
    if(bit == 0) {
        ans += helper(n-1, k, 0, dp);
        ans += helper(n-1, k, 1, dp) ;
    } else {
        ans += helper(n - 1, k, 0, dp) ;
        ans += helper(n - 1, k-1, 1, dp);
    }

    return dp[n][k][bit] = ans % mod;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n, k; cin >> n >> k;
        int dp[101][101][2];
        memset(dp, -1, sizeof dp);
        cout << (helper(n, k, 0, dp)%mod + helper(n, k, 1, dp)%mod) % mod << endl;
    }
    return 0;
}
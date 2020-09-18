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
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k; cin >> k;

    int dp[k+1][n];
    memset(dp, 0, sizeof dp);
    
    for(int t = 1; t <= k; t++) {
        int mx = imin;
        for(int d = 1; d < n; d++) {
            mx = max(mx, dp[t-1][d-1] - arr[d-1]);

            dp[t][d] = max(dp[t][d-1], mx + arr[d]);
        }
    }
    cout << dp[k][n-1];
    return 0;
}
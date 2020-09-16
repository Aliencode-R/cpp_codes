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
    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int dp[n][m] = {0};
    dp[n-1][m-1] = arr[n-1][m-1];

    for(int i = n-2; i >= 0; i--) {
        dp[i][m-1] = arr[i][m-1] + dp[i+1][m-1]; 
    }

    for(int j = m-2; j >= 0; j--) {
        dp[n-1][j] = arr[n-1][j] + dp[n-1][j+1];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = m-2; j >= 0; j--) {
            dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + arr[i][j];
        }
    }
    cout << dp[0][0];

    return 0;
}
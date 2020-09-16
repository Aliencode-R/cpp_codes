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
    for(int i = 0; i < n; i++) {
        dp[i][m-1] = arr[i][m-1];
    }
    for(int j = m-2; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            dp[i][j] = dp[i][j+1];
            if(i-1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
            }
            if(i+1 < n) {
                dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
            }
            dp[i][j] += arr[i][j];
        }
    }
    int ans = -1; 
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i][0]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
    return 0;
}
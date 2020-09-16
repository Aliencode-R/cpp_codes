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
    int vals[n]; 
    for(int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int amt; cin >> amt; 
    int dp[n+1][amt+1];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amt; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= wt[i-1]) {
                dp[i][j] = max(dp[i][j],vals[i-1] + dp[i-1][j-wt[i-1]]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[n][amt];

    // cout << dp[0][0];
    return 0;
}
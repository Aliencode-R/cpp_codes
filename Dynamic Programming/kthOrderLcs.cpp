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
int a[2002] = {};
int b[2002] = {};
int dp[2002][2002][6] ;

int helper(int n, int m, int k) {
    if(k < 0) return imin;
    if(n == 0 or m == 0) return 0;

    if(dp[n][m][k] != -1) return dp[n][m][k];
    int ans = imin;
    if(a[n-1] == b[m-1]) {
        ans = max({helper(n-1, m, k), helper(n, m-1, k), helper(n-1, m-1, k) + 1});
    } else {
        ans = max({helper(n - 1, m, k), helper(n, m - 1, k), helper(n - 1, m - 1, k-1) + 1});
    }

    return dp[n][m][k] = ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    memset(dp, -1, sizeof dp);
    cout << helper(n, m, k);

    return 0;
}
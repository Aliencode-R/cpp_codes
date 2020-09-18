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

int dp[1000][3];

int helper(vector<int> v[], int n, int bit, int i) {
    if(i == n) {
        return 0;
    }
    if(dp[i][bit] != -1) return dp[i][bit];
    int ans = imax;
    if(bit != 0) {
        ans = min(ans, helper(v, n, 0, i+1));
    }
    if (bit != 1)
    {
        ans = min(ans, helper(v, n, 1, i + 1));
    }
    if (bit != 2)
    {
        ans = min(ans, helper(v, n, 2, i + 1));
    }
    return dp[i][bit] = ans + v[i][bit];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v[n];
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i].push_back(a);
        v[i].push_back(b);
        v[i].push_back(c);
    }
    memset(dp, -1, sizeof(dp));
    // cout << min({helper(v, n, 0, 0) , helper(v, n, 1, 0) , helper(v, n, 2, 0)});

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for(int i = 1; i < n; i++) {
            dp[i][0] = v[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = v[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = v[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    return 0;
}
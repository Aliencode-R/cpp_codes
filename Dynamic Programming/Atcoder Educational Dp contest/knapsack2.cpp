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

struct item {
    int wt;
    int val;
};

int solve(vector<item> ar, int n, int W) {
    int maxVal = n * 1000;
    int dp[n+1][maxVal + 1];

    for(int val = 0; val <= maxVal; val++) {
        dp[1][val] = imax;
    }

    dp[1][0] = 0;
    dp[1][ar[1].val] = ar[1].wt;

    for(int i = 2; i <= n; i++) {
        for(int v = 0; v <= maxVal; v++) {
            dp[i][v] = dp[i-1][v];
            if(ar[i].val > v) {
                continue;
            }
            dp[i][v] = min(dp[i][v], ar[i].wt + dp[i-1][v - ar[i].val]);
        }
    }
    int ans = 0;
    for(int val = 0; val <= maxVal; val++) {
        if(dp[n][val] <= W) {
            ans = val;
        }
    }
    return ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w; cin >> n >> w;
    vector<item> v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].wt >> v[i].val;
    }
    cout << solve(v, n, w);

    return 0;
}
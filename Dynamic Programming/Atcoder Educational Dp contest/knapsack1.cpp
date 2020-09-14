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
int dp[101][100005];

int helper(int *wt, int *val, int n, int index, int w) {
    if(w == 0) {
        return 0;
    }
    if(index == n-1) {
        if(wt[index] <= w) {
            return val[index];
        } else {
            return 0;
        }
    }
    if(dp[index][w] != -1) return dp[index][w];
    int ans = imin;
    if(wt[index] <= w) {
        ans = val[index] + helper(wt, val, n, index+1, w-wt[index]);
    }
    ans = max(ans, helper(wt, val, n, index+1, w));
    return dp[index][w] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n, w; cin >> n >> w;
    int val[n], wt[n];
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << helper(wt, val, n, 0, w);
    return 0;
}
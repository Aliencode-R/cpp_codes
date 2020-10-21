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
int n, m, k; 
int dp[70][70][40][75];

int helper(int i, int j, int cnt, int rem) {
    int &ret = dp[i][j][cnt][rem];
    if(ret != -1) {
        return ret;
    }
    if(j == m) {
        if(i == n)
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n  >> m >> k;
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        // sort(arr[i], arr[i]+m);
    }
    memset(dp, -1, sizeof dp);
    cout << helper(0, 0, 0, 0);

    return 0;
}
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

// int dp[10001][501];

int helper(int *arr, int n, int m, int i, int dp[][501]) {

    if(m == 0) return 1;
    if(m < 0) return 0;
    if(i == n and m != 0) return 0;
    if(dp[m][i] != -1) return dp[m][i];

    return dp[m][i] =  helper(arr, n, m - arr[i], i, dp) + helper(arr, n, m, i + 1, dp);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        int arr[n]; 
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int m; cin >> m;
        int dp[m+1][501];
        memset(dp, -1, sizeof dp);
        cout << helper(arr, n, m, 0, dp) << endl;
    }
    return 0;
}
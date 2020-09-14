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

void clear(int dp[][3], int n) {
    for(int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }
    return ;
}

int helper(int arr[][3], int n, int col, int index, int dp[][3]) {
    if(index == n-1) {
        return arr[n-1][col];
    }
    if(dp[index][col] != -1) return dp[index][col];
    int ans = imin;
    if(col != 0)
        ans = max(ans, helper(arr, n, 0, index + 1, dp));
    if (col != 1)
        ans = max(ans, helper(arr, n, 1, index + 1, dp));
    if (col != 2)
        ans = max(ans, helper(arr, n, 2, index + 1, dp));

    return dp[index][col] = ans + arr[index][col];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n][3];
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int ans = imin;
    int dp[n][3];
    clear(dp, n);
    ans = max(ans, helper(arr, n, 0, 0, dp));
    clear(dp, n);
    ans = max(ans, helper(arr, n, 1, 0, dp));
    clear(dp, n);
    ans = max(ans, helper(arr, n, 2, 0, dp));

    cout << ans << endl;
    return 0;
}
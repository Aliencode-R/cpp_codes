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

int dp[100005];

int helper(int *arr, int n, int i, int cost) {
    if(i == n-1) 
    {
        return 0;
    }
    if(dp[i] != -1) return dp[i]; 
    int ans = imax;
    if(i+1 < n)
        ans = min(ans, abs(arr[i+1] - arr[i]) + helper(arr, n, i+1, cost));
    if(i+2 < n)
        ans = min(ans, abs(arr[i + 2] - arr[i]) + helper(arr, n, i + 2, cost));
    return dp[i] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << helper(arr, n, 0, 0);
    return 0;
}
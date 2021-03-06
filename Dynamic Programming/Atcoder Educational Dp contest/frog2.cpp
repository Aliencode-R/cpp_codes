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

int helper(int *arr, int n, int k) {
    int dp[n] = {0};
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = imax;
        for(int j = i - 1; j >= 0 and i - j <= k; j--) {
            dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
        }
    }
    return dp[n-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << helper(arr, n, k);
    return 0;
}
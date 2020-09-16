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
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int dp[n+1] = {0};
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 1; j <= arr[i] and i+j <= n; j++) {
            dp[i] += dp[i+j];
        }
    }
    cout << dp[0];
    return 0;
}
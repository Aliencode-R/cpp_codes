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
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    
    int dp[n];
    int val = 1;
    bool inc = true;
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        if(inc) {
            if(arr[i] >= arr[i-1]) {
                dp[i] = val;
            } else {
                dp[i] = val;
                inc = false;
            }
        } 
        else {
            if(arr[i] <= arr[i-1]) {
                dp[i] = val;
            } else {
                inc = true;
                val ++;
                dp[i] = val;
            }
        }
    }
    // for(int x : dp) cout << x << " ";
    while(m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if(l == r or r - l <= 1) cout << "Yes" << endl;
        else if(dp[l] == dp[r] or  dp[l+1] == dp[r]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
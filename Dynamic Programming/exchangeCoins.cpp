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
umap<int,int> dp;

int helper(int n) {
    if(n == 0) return 0;
    if(dp.count(n) != 0) {
        return dp[n];
    }
    // if(n % 2 == 0 and n % 3 == 0 and n % 4 == 0) {
        return dp[n] = max(n, helper(n/2) + helper(n/3) + helper(n/4));
    // } else {
    //     return dp[n] = n;
    // }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << helper(n);
    return 0;
}
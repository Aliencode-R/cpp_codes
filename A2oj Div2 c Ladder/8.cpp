#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
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

int dp[101][2];

int helper(int n, int k, int d, bool hasOccured) {
    if(n == 0) {
        if(hasOccured) return 1;
        else return 0;
    }
    if(dp[n][hasOccured] != -1) return dp[n][hasOccured];

    int ans = 0;

    for(int i = 1; i <= min(k, n); i++) {
        bool b = (i >= d or hasOccured) ;
        ans += helper(n-i, k, d, b);
        ans %= mod;
    }
    return dp[n][hasOccured] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n, k, d;
    cin >> n >> k >> d;
    cout << helper(n, k, d, false);
    return 0;
}

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

int a[1000];
int dp[1000][1000];

int sum (int s, int e) {
    int ans = 0;
    for(int i = s; i <= e; i++) {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int helper(int i, int j) {

    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j], helper(i,k) + helper(k+1, j) + sum(i,k) * sum(k+1,j));
    }

    return dp[i][j];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= n; j++) {
        //         dp[i][j] = -1;
        //     }
        // }
        cout << helper(0, n-1) << endl;
    }

    return 0;
}
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
    string s; cin >> s;
    int n = s.size();
    int dp[n] = {};
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '(') continue;
        if(s[i-1] == '(') {
            dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
        } else if(i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(') {
            dp[i] = dp[i-1] + ((i - dp[i-1] >= 2 ? dp[i-dp[i-1] - 2] : 0) + 2);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans ;
    return 0;
}
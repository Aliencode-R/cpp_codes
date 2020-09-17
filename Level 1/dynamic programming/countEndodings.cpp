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
int dp[11] = {};
int helper(string s, int i) {
    if(i == s.size()) {
        return 1;
    }
    if(i == s.size() - 1) {
        return 1;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    int ans = 0;
    if(s[i] != '0') {
        ans += helper(s, i+1);
    }
    if(i + 1 < s.size() and s[i] != '0' and (s[i] - '0') * 10 + (s[i+1] - '0') <= 26) {
        ans += helper(s, i+2);
    }
    return dp[i] =  ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    // string s = "";
    memset(dp, -1, sizeof dp);
    cout << helper(s, 0);
    return 0;
}
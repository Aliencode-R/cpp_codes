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
string s; 
int dp[100][100];

int helper(int i, int j) {
    if(i == j) return 1;
    if(i + 1 == j) return 2 + (s[i] == s[j]);

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    ret = 0;
    if(s[i] == s[j]) {
        ret += helper(i + 1, j - 1) + 1;
    }
    ret += helper(i + 1, j);
    ret += helper(i , j-1);
    ret -= helper(i + 1, j - 1);
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> s;
        int n = s.size();
        memset(dp, -1, sizeof dp);
        cout << helper(0, n-1) << endl;
    }
    return 0;
}
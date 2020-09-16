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
#define Max 3000

int dp[Max+1][Max+1];

string getLcs(string &s, string &t, int len) {
    string lcs;
    int i = 0, j = 0;
    while(len > 0) {
        if(s[i] == t[j]) {
            lcs += s[i];
            i++;
            j++;
            len--;
        } else {
            if(dp[i][j+1] > dp[i+1][j]) {
                j++;
            } else {
                i++;
            }
        }
    }
    return lcs;
}

int lenLcs(string &s, string &t, int i, int j) {
    if(i >= s.size() or j >= t.size()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(s[i] == t[j]) {
        return dp[i][j] =  1 + lenLcs(s, t, i+1, j+1);
    } else {
        return dp[i][j] = max(lenLcs(s, t, i+1, j), lenLcs(s, t, i, j+1));
    }
}

string solve(string s, string t) {
    memset(dp, -1, sizeof dp);
    int len = lenLcs(s, t, 0, 0);
    return getLcs(s, t, len);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; cin >> s >> t;
    cout << solve(s, t);
    return 0;
}
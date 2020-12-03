#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define sz(x) ((int)x.size())
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

bool check(umap<char, int> s, umap<char, int> p) {
    int ques = s['?'];
    for(int i = 0; i < 25; i++) {
        char c = i + 'a';
        if(s[c] > p[c]) {
            return false;
        }
        if(s[c] + ques >= p[c]) {
            ques -= p[c] - s[c];
        } else {
            return false;
        }
    }
    return true;
}

void solve () {
    string s, p; cin >> s >> p;
    if(sz(s) < sz(p)) {
        cout << 0 << endl;
        return;
    }
    umap<char, int> window;
    umap<char, int> mp;
    for(char c : p) {
        mp[c]++;
    }
    int n = sz(s);
    int m = sz(p);

    int ans = 0;

    for(int i = 0; i < m; i++) {
        window[s[i]]++;
    }

    ans += check(window, mp);

    for(int i = m; i < n; i++) {
        window[s[i]]++;
        window[s[i-m]]--;
        ans += check(window, mp);
    }
    cout << ans ;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
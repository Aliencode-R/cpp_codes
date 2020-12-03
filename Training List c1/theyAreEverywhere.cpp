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
int n;
string s;

bool check(umap<char, int> &m, uset<char> &myset) {
    for(auto c : myset) {
        if(m[c] == 0) {
            return false;
        }
    }
    return true;
}

bool isGood(int window, uset<char> &myset) {
    umap<char, int> m; 
    for(int i = 0; i < window; i++) {
        char c = s[i];
        m[c]++;
    }
    // now we have the initial window 

    // now check window
    bool flag = check(m, myset);

    for(int i = window; i < n; i++) {
        char left = s[i-window];
        char right = s[i];
        m[right]++;
        m[left]--;
        flag = flag or check(m, myset);
        if(flag) return true;
    }
    return flag;

}

void solve () {
    cin >> n; 
    cin >> s; 
    umap<char,int> m;
    uset<char> myset;
    for(char c : s) myset.insert(c);

    int low = sz(myset);
    int high = n;
    int ans = n;

    while(low <= high) {
        int mid = (high + low) / 2;
        if(isGood(mid, myset)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
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
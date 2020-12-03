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

void solve () {
    string s; cin >> s; 
    int k; cin>> k;
    map<char, int> m; 
    for(char c : s) m[c]++;
    uset<char> elementsToRemove;
    while(k > 0) {
        // get min freq element and its freq;
        char c;
        int freq = imax;
        for(auto p : m) {
            if(freq > p.second) {
                freq = p.second;
                c = p.first;
            }
        }
        // we have c and freq
        if(k >= freq) {
            k -= freq;
            m[c] = imax;
            elementsToRemove.insert(c);
        } else {
            break;
        }
    }
    debug(k);
    string t; 
    // count distinct elements in t;
    uset<char> tset;
    for(char c : s) {
        if(elementsToRemove.find(c) == elementsToRemove.end()) {
            t += c;
            tset.insert(c);
        }
    }

    cout << sz(tset) << endl << t ;

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
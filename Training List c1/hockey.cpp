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
    int n; cin >> n; 
    vector<string> v(n); 
    for(int i= 0; i < n; i++) cin >> v[i];
    string w;
    char letter;
    cin >> w >> letter;
    bool should[sz(w)] = {};
    for(int k = 0; k < n; k++) {
        string pat = v[k];
        for(int i = 0; i + sz(pat) <= sz(w); i++) {
            bool matched = true;
            for(int j = 0; j < sz(pat); j++) {
                if(tolower(w[i+j]) != tolower(pat[j])) {
                    matched = false ;
                    break;
                }
            }
            
            if(matched) {
                for(int j = 0; j < sz(pat); j++) {
                    should[i + j] = true;
                }
            }
        }
    }

    for(int i = 0; i < sz(w); i++) {
        if(should[i] == false) continue;
        if(tolower(w[i]) == tolower(letter)) {
            if(tolower(letter) == 'a') {
                if(isupper(w[i])) {
                    w[i] = 'B';
                } else {
                    w[i] = 'b';
                }
            } else {
                if (isupper(w[i]))
                {
                    w[i] = 'A';
                }
                else
                {
                    w[i] = 'a';
                }
            }
        } else {
            if(isupper(w[i])) {
                w[i] = toupper(letter);
            } else {
                w[i] = tolower(letter);
            }
        }
    }
    cout << w << endl;

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
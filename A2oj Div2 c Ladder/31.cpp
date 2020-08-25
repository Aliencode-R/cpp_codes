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
// #define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    vector<int> l, r;
    l.reserve(100000);
    r.reserve(100000);
    for(int i = 0;i < s.size();i++) {
        char c = s[i];
        if(c == 'l') {
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }
    // for(int x : r) cout << x+1 << endl;
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] + 1 << endl;
    }
    for(int i = l.size()-1; i >= 0; i--) {
        cout << l[i]+1 << endl;
    }
    return 0;
}
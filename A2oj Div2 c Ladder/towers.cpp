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
    int n, k; cin >> n >> k; 
    vector<pii> v;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back({num, i+1});
    }
    sort(all(v));
    // for(pii p : v) cout << p.first << " " << p.second << endl;
    vector<pii> ans;
    int s = 0, e = n-1;
    int i;
    for( i = 0; i < k; i++) {
        if(v[e].first > v[s].first) {
            v[e].first--;
            v[s].first++;
            ans.push_back({v[e].second, v[s].second});
            // cout << v[e].second << " " << v[s].second << endl;
        } else {
            break;
        }
        sort(all(v));
    }
    cout << v[e].first - v[s].first << " " << i << endl;
    for(pii p : ans ) cout << p.first << " " << p.second << endl;
    return 0;
}
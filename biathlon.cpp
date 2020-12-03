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

vi search_segments(int x, int y, vector<pii> &segments) {
    vi ans;
    // use x coordinate
    int low = 1, high = sz(segments) - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(segments[mid].first > x) {
            low = mid + 1;
        } else if(segments[mid].second < x) {
            high = mid - 1;
        } else {
            ans.push_back(mid);
            if(mid > 0 and segments[mid-1].second == x) {
                ans.push_back(mid-1);
            }
            if(mid < sz(segments) - 1 and segments[mid+1].first == x) {
                ans.push_back(mid+1);
            }
            break;
        }
    }
    return ans;
}

void solve () {
    int n; cin >> n;
    vector<pii> circle(n);
    vector<pii> segment(n);
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a>> b;
        circle[i] = {a, b};
        segment[i] = {a - b, a + b};
    }

    int m; cin >> m; 
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        // first search the segment 
        vi seg = search_segments(x, y, segment);
        
    }

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
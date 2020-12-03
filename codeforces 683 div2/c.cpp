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

bool check(int num, int w) {
    if(num > w) return false;
    int half;
    if(w % 2 ==0) {
        half = w / 2; 
    } else {
        half = w/ 2 + 1;
    }
    if(num >= half) return true;
    return false;
}

void solve () {
    int n, w; cin >> n >> w; 
    pii arr[n+1];
    vi index;
    int sum = 0;
    bool flag = false;
    int ii;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        arr[i] = {num, i};
        if(check(num, w)) {
            flag = true;
            ii = i;
        }
        int half;
        if (w % 2 == 0)
        {
            half = w / 2;
        }
        else
        {
            half = w / 2 + 1;
        }
        if(num < half) {
            sum += num;
            index.push_back(i);
        }
    }
    if(flag) {
        cout << 1 << endl << ii << endl;
        return;
    }
    int half;
    if (w % 2 == 0)
    {
        half = w / 2;
    }
    else
    {
        half = w / 2 + 1;
    }
    if(sum < half) {
        cout << -1 << endl;
        return;
    }
    while(sum > w and sz(index) > 0) {
        int last = index[sz(index)-1];
        sum -= arr[last].first;
        index.pop_back();
    }


    if(check(sum, w) and sz(index) != 0) {
        cout << index.size() << endl;
        for(auto x : index) cout << x <<  " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
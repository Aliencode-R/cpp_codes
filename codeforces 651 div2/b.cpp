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
    int n; cin >>n ; 
    vi arr(2*n+1);
    for(int i = 1; i <= 2*n; i++) cin >> arr[i];
    vi odd, even;
    for (int i = 1; i <= 2*n; i++)
    {   
        if(arr[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    if(sz(odd) % 2 == 0) {
        if(sz(odd) >= 2) {
            odd.pop_back();
            odd.pop_back();
        } else {
            even.pop_back();
            even.pop_back();
        }
    } else {
        odd.pop_back();
        even.pop_back();
    }
    cout << endl;
    for(int i = 0; i < sz(odd); i += 2)
    {
        cout << odd[i] << " "<< odd[i+1] << endl;
    }
    for (int i = 0; i < sz(even); i += 2)
    {
        cout << even[i] << " " << even[i + 1] << endl;
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
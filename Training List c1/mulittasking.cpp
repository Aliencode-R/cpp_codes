#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
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
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<pii>> v;
    int terminator = m-1;
    for(int i = 1; i < m; i++) {
        if(terminator == 0) break;
        vector<pii> temp;
        for(int j = 1; j <= terminator; j++) {
            pii p;
            if(k == 0)
                p = {j, j+1};
            else 
                p = {m - j +1, m - j };
            temp.push_back(p);
        }
        // if(k == 1) {
        //     reverse(all(temp));
        // }
        v.push_back(temp);
        terminator--;
    }
    cout << (m * (m-1) ) / 2 << endl;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].first << " " << v[i][j].second << endl;
        }
    }
    return 0;
}
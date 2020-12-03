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
struct cell{
    int x, y;
};
int N, M, x, y, z, p;
vector<cell> arr;

void rotate() {
    for(int i = 0; i < p; i++) {
        int newi = arr[i].y;
        int newj = N - arr[i].x - 1;
        arr[i].x = newi;
        arr[i].y = newj;             
    }
    swap(N, M);
    return;
}

void mirror() {
    for(int i = 0; i < p; i++) {
        arr[i].y = M - arr[i].y - 1;
    }
    return ;
}

void solve () {
    cin >> N >> M >> x >> y >> z >> p;
    for(int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        arr.push_back({a, b});
    }   
    x %= 4, y %= 2, z %= 4;
    for(int i = 0; i < x; i++) {
        rotate();
    }
    // cout << endl;
    // for (int i = 0; i < p; i++)
    //     cout << arr[i].x << " " << arr[i].y << endl;


    if(y > 0)
        mirror();

    // cout << endl;
    // for (int i = 0; i < p; i++)
    //     cout << arr[i].x << " " << arr[i].y << endl;


    for(int i = 0; i < (3 * z) % 4; i++) {
        rotate();
    }
    // cout << endl;
    for(int i = 0; i < p; i++) cout << arr[i].x +1<< " " << arr[i].y +1<< endl;
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
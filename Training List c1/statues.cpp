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
vector<string> chess(8);
bool flag = false;
int dx[] = {0, 0, 1, -1, -1, 1, -1, 1, 0};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};

// void backtrack(int i, int j) {
//     cout << i << " " << j << endl;
//     if(chess[i][j] == 'A' or flag) {
//         flag = true;
//         return;
//     }
//     for(int ii = 0; ii < 9; ii++) {
//         int dx = d[ii].first;
//         int dy = d[ii].second;
//         if(isAllowed(i + dx, j + dy)) {
//             if(ii == 7 or ii == 8 or ii == 9) {
//                 if(j == 7) continue;
//             }
//             backtrack(i + dx, j + dy);
//         }
//     }
//     return;
// }

bool dfs(int x, int y, int steps) {
    if(steps >= 8) {
        return true;
    }
    // if(chess[x][y] == 'A') return true;
    for(int i = 0; i < 9; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 or ny < 0 or nx > 7 or ny > 7) {
            continue;
        }
        if (nx - steps >= 0 && chess[nx - steps][ny] == 'S')
            continue;
        if (nx - steps - 1 >= 0 && chess[nx - steps - 1][ny] == 'S')
            continue;
        if (dfs(nx, ny, steps + 1))
            return true;
    }
    return false;
}

void solve () {
    for(int i = 0; i < 8; i++) cin >> chess[i];

    if(dfs(7, 0, 0)) {
        cout << "WIN" << endl;
    } else {
        cout << "LOSE" << endl;
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
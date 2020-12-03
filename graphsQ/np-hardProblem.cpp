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

const int N = 100005;
vector<int> graph[N];
int visited[N]; // 0: not visited, 1: coloured 1, 2: coloured 2
bool oddCycle = false;

void dfs(int cur, int par, int col)
{
    visited[cur] = col;

    for (auto child : graph[cur])
    {
        if (visited[child] == 0)
        {
            dfs(child, cur, (col + col) % 3); // or 3 - col
        }
        else if (child != par and col == visited[child])
        {
            // backedge and odd length cycle
            oddCycle = true;
            return;
        }
    }
}

void solve () {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // dfs(1, 0, 1);

// first find a comp which is bipartite
   
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0 and sz(graph[i]) != 0) {
            debug(i) ;
            // oddCycle = false;
            // dfs(i, 0, 1);
            // if(oddCycle == false) break;
            // cout << i << "-> " << oddCycle << endl;
            dfs(i, 0, 1);
            if(oddCycle) {
                cout << -1 ;
                return;
            }
        }
    }    
    // cout << oddCycle << endl;
    debug(oddCycle);
    if(oddCycle) {
        cout << -1;
        return;
    }

    vi one, two;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 1) one.push_back(i);
        else if(visited[i] == 2) two.push_back(i);
    }
    if(sz(one) == 0 or sz(two) == 0) {
        cout << -1 << endl;
        return;
    }

    cout << sz(one) << endl;
    for(auto x : one) cout << x << " ";
    cout << endl;
    cout << sz(two) << endl;
    for (auto x : two)
        cout << x << " ";
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
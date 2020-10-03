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

void dfs(int cur, int par, int col, int n, vector<int> *g, int *visited) {
    visited[cur] = col;
    for(auto child : g[cur]) {
        if(visited[child] == 0) {
            dfs(child, cur, 3 - col, n, g, visited);
        }
        else if(col == 1 and visited[child] == 1) {
            // dfs(child, cur, 3 - col, n, g, visited);
            visited[child] = 2;
        }
    }
    return ;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, e; cin >> n >> e;
        vector<int> g[n+1];
        int visited[n+1] = {};
        for(int i = 0; i < e; i++) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1, 0, 1, n, g, visited);
        vector<int> op1, op2;
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 1) op1.push_back(i);
            else op2.push_back(i);
        }
        if(op1.size() >= op2.size()) {
            cout << op1.size() << endl;
            for(int x : op1) cout << x << " " ;
            cout << endl;
        } else {
            cout << op2.size() << endl;
            for (int x : op2)
                cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}
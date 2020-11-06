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
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;


void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack) {
    visited[i] = true;

    for(auto nbr : graph[i]) {
        if(!visited[nbr]) {
            dfs(graph, nbr, visited, stack);
        }
    }
    stack.push_back(i);
}

void dfs2(vector<int> graph[], int i, bool *visited)
{
    visited[i] = true;
    cout << i << " ";
    for (auto nbr : graph[i])
    {
        if (!visited[nbr])
        {
            dfs2(graph, nbr, visited);
        }
    }
}

void kosa(vector<int> graph[], vector<int> rev_graph[], int n) {
    bool visited[n];
    memset(visited, 0, sizeof visited);

    vector<int> stack;
    // step1: neet to store the vertices acc to dfs finish time
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(graph, i, visited, stack);
        }
    }

    // ordering is stored in stack
    // step 2 : rev the graph which is already done by rev graph
    // step 3: do dfs acc to the ordering given in the stack 
    memset(visited, 0, sizeof visited);
    int component = 0;
    for(int x = stack.size() - 1; x >= 0; x--) {
        int node = stack[x];
        if(!visited[node]) {
            cout << "component " << component << " : ";
            dfs2(rev_graph, node, visited);
            cout << endl;
            component++;
        }
    }


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    // n++;
    vector<int> graph[n];
    vector<int> rev_graph[n];

    int m; cin >> m;
    while(m--) {
        // cout << m << " ";
        int x, y; cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    kosa(graph, rev_graph, n);

    return 0;
}
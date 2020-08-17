#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

class graph
{
    map<int, uset<int>> adj;

public:
    void addEdge(int u, int v, bool bidir = true)
    {
        adj[u].insert(v);
        if (bidir)
        {
            adj[v].insert(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto nbr : i.second)
            {
                cout << nbr << " ";
            }
            cout << nL;
        }
    }
    int bfs_helper(int src, umap<int, bool> &visited)
    {
        int ans = 1;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (q.size() != 0)
        {
            int cur = q.front();
            q.pop();
            // cout << cur << "->";
            for (auto i : adj[cur])
            {
                if (visited[i] == false)
                {
                    ans ++;
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return ans;
    }
    int nc2(int n) {
        return n * (n - 1) / 2;
    }
    void bfs()
    {
        umap<int, bool> visited;
        // bfs_helper(src, visited);
        // cout << endl;
        int n = 0, c;
        vector<int> ci;
        for (auto p : adj)
        {
            if (visited[p.a] == false)
            {
                c = bfs_helper(p.a, visited);
                ci.push_back(c);
                n += c;
            }
        }
        int ans = nc2(n);
        for (auto x: ci) {
            ans -= nc2(x);
        }
        cout << ans;
    }

};

int main()
{
    graph g;
    int n, p; cin >> n >> p;
    for(int i = 0; i < n; i++) {
        g.addEdge(i,i);
    }
    for(int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        g.addEdge(a, b);
    }
    g.bfs();
    return 0;
}
//to check undirected graph is a tree or not
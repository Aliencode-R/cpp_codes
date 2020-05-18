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
    void dfs_helper(int src, umap<int, bool> &visited, list<int> &ordering)
    {
        visited[src] = true;
        cout << src << " ";

        for (auto i : adj[src])
        {
            if (visited[i] == false)
            {
                dfs_helper(i, visited, ordering);
            }
        }
        ordering.push_front(src);
    }
    void dfs(int src)
    {
        list<int> ordering;
        umap<int, bool> visited;
        dfs_helper(src, visited, ordering);
        cout << endl;
        for (auto p : adj)
        {
            if (visited[p.a] == false)
            {
                dfs_helper(p.a, visited, ordering);
                cout << endl;
            }
        }
        for(auto node: ordering)
        {
            cout << node << " ";
        }

    }
};

int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 2);
    g.addEdge(3, 3);
    g.addEdge(4, 4);
    // g.bfs(2);
    g.dfs(2);
    // g.print();
    return 0;
}
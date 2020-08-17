#include <bits/stdc++.h>
using namespace std;

struct dsu
{
    vector<int> p;
    void init(int n)
    {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x)
    {
        return (x == p[x]) ? x : p[x] = get(p[x]);
    }

    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y)
        {
            p[x] = y;
        }
    }
};

int main()
{
    int i, j, k, n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // x--;
        // y--; // making 0-indexed
        edges[i] = {w, x, y};
    }
    sort(edges.begin(), edges.end());

    dsu g;
    g.init(n+1);
    vector<vector<int>> output;

    for (int i = 0; i < m; i++)
    {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];

        // cycle detection
        if(g.get(x) != g.get(y) ) {
            output.push_back({x, y, w});
            // can take this edge
            g.unite(x, y);
            ans += w;
        }
    }
    cout << "output: " << endl;
    for(auto v: output) {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
    cout << "total wt: " << ans;
    // cout << ans;
    return 0;
}
// 4 6 1 2 5 2 4 8 3 4 7 1 3 6 1 4 10 2 3 9 output : 1 2 5 1 3 6 3 4 7 total wt : 18
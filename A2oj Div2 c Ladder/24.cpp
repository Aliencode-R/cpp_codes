#include <bits/stdc++.h>
using namespace std;

class dsu
{
    vector<int> parent;
    vector<int> sz;
    int components;

public:
    dsu(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        components = n;
    }

    int getComponents()
    {
        return components;
    }

    int getSuperParent(int x)
    {
        // path compression
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return parent[x] = getSuperParent(parent[x]);
        }
    }

    void unite(int x, int y)
    {
        int super_x = getSuperParent(x);
        int super_y = getSuperParent(y);

        if (super_x != super_y)
        {
            parent[super_x] = super_y;
            sz[super_y] += sz[super_x];
            sz[super_x] = 0;
            components--;
        }
    }
};

int main()
{
    int n; cin >>n;
    vector<pair<int,int>> v(n);
    // unordered_map<pair<int,int>, int > m;
    for(int i = 0;i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    dsu g(n);
    for(int i = 1; i < n; i++) {
        int x = v[i].first;
        int y = v[i].second;
        for(int j = i-1; j >= 0; j --) {
            if(x == v[j].first or y == v[j].second) {
                g.unite(i, j);
            }
        }
    }
    cout << g.getComponents() - 1;

}
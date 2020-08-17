#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int, list<pair<int, int>>> m;

public:
    void addEdge(int u, int v, int wt)
    {
        m[u].push_back(make_pair(v, wt));
        m[v].push_back(make_pair(u, wt));
    }

    void print()
    {
        for (auto j : m)
        {
            cout << j.first << "->";

            for (auto l : j.second)
            {
                cout << "(" << l.first << "," << l.second << ")";
            }
            cout << endl;
        }
    }

    void dijkstra(int src)
    {
        unordered_map<int, int> dist;

        for(auto j: m) {
            dist[j.first] = INT_MAX;
        }
        // set is pair of wt, node bcz set sorts in order of first element
        set<pair<int,int>> s;   

        dist[src] = 0;
        s.insert(make_pair(0, src));
        
        

    }
};

int main()
{
    graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.print();
    // g.dijkstra(1);
    return 0;
}
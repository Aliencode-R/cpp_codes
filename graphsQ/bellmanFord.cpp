#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<vector<int>> edges){
    vector<int> dis(n+1, INT_MAX);
    dis[src] = 0;
    // relax all edges n-1 times
    for(int i = 0; i < n-1; i++) {
        for(auto x: edges) {
            int from = x[0], to = x[1], wt = x[2];
            if(dis[to] > dis[from] + wt) {
                // edge relax
                dis[to] = dis[from] + wt;
            }
        }
    }

    // check for the -ve wt cycle
    for (auto x : edges)
    {
        int from = x[0], to = x[1], wt = x[2];
        if (dis[to] > dis[from] + wt)
        {
            cout << "negative wt cycle present" ;
            exit(0);
        }
    }
    return dis;
}

    int main()
{

    int n, m; cin >> n >> m;
    vector<vector<int>> edges;

    for(int i  = 0;i < m; i++) {
        int from, to, wt;
        cin >> from >> to >> wt ;
        edges.push_back({from, to, wt});
    }
    vector<int> dis = bellmanFord(n, 1, edges);
    for(int i = 1; i <= n; i++) {
        cout << i << " " << dis[i] << "\n";
    }

    return 0;
}
// 3 3 1 2 4 1 3 5 3 2 - 7
// 1 0 2 - 2 3 5

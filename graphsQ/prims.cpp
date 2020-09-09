#include<bits/stdc++.h>
using namespace std;

#define int long long
bool marked[100000];
vector<pair<int,int>> adj[100000];
// vector<vector<int>> par;
// int parent = 0;


int prim(int x) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pair<int,int> p;
    pq.push({0, x});
    int minCost = 0;

    while(pq.size() != 0) {
        p = pq.top();
        pq.pop();
        int node = p.second;
        int wt = p.first;
        if(marked[node]) continue;
        // par.push_back({parent, node, wt});
        // parent = node;
        minCost += p.first;
        marked[node] = true;

        for(auto pii: adj[node]) {
            int nbr = pii.second;
            int wt = pii.first;
            if(marked[nbr] == false) {
                // par.push_back({node, nbr, wt});
                pq.push(pii);
            }
        }
    }
    return minCost;
}

int32_t main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        y--, x--;
        adj[x].push_back({wt, y});
        adj[y].push_back({wt, x});
    }
    cout << prim(0) << endl;

    // for(auto v : par) {
    //     cout << v[0] << " " << v[1] << " " << v[2] << endl;
    // }

    return 0;
}
// 4 6 1 2 5 2 4 8 3 4 7 1 3 6 1 4 10 2 3 9 output : 1 2 5 1 3 6 3 4 7 total wt : 18

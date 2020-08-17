#include<bits/stdc++.h>
using namespace std;

#define int long long
bool marked[100000];
vector<pair<int,int>> adj[100000];
vector<vector<int>> par;


int prim(int x) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pair<int,int> p;
    pq.push({0, x});
    int minCost = 0;

    while(pq.size() != 0) {
        p = pq.top();
        pq.pop();
        int node = p.second;
        if(marked[node]) continue;

        minCost += p.first;
        marked[node] = true;

        // for(int i = 0; i < adj[node].size(); i++) {
        //     int 
        // }
        for(auto pii: adj[node]) {
            int nbr = pii.second;
            if(marked[nbr] == false) {
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
        adj[x].push_back({wt, y});
        adj[y].push_back({wt, x});
    }

    cout << prim(0) << endl;


    return 0;
}
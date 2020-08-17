#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshal(int n, vector<vector<pair<int,int>>> &adj) {
    vector<vector<int>> dist(n+1, vector<int>(n+1, 2e9));

    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;

        for(auto ed: adj[i]) {
            int nbr = ed.first;
            int wt = ed.second;
            dist[i][nbr] = wt;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {

    return 0;
}
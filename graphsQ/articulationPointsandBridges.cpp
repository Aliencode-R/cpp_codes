#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100005, M = 22;

vector<int> graph[N];
int disc[N], low[N], tme;

// discorvery time will be the time we first reach that node
// low is the time that a node can reach backward by moving forward via backedge

set<int> articulationPoints;
vector<pair<int,int>> bridge;

void dfs(int cur, int par) {

    disc[cur] = low[cur] = tme++;
    int no_child = 0;
    for(auto child: graph[cur]) {
        // not visited: discovery time will be 0
        if(disc[child] == 0) {
            dfs(child, cur);
            no_child++;
            low[cur] = min(low[cur], low[child]);

            // check for art point
            if (par != 0 and low[child] >= disc[cur]) {
                articulationPoints.insert(cur);
            }
            // check for bridge
            if(low[child] > disc[cur]) {
                bridge.push_back({cur, child});
            }
        }
        else if(child != par) {
            // backedge
            // cycle found
            low[cur] = min(low[cur], disc[child]);
        }
    }
    // separate case for root to be articulation point
    if(par == 0 and no_child >= 2) {
        articulationPoints.insert(cur);
    }
    return ;
}


int32_t main() {
    // 5 5 1 2 2 3 3 1 3 4 4 5
    // 3 4

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    tme = 1; 
    dfs(1, 0);
    cout << endl;
    for(auto x: articulationPoints) cout << x << " ";
    cout << endl;

}
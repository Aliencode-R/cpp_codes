#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;
vector<int> graph[N];
int visited[N]; // 0: not visited, 1: coloured 1, 2: coloured 2
bool oddCycle = false;

void dfs(int cur, int par, int col) {
    visited[cur] = col;

    for(auto child: graph[cur]) {
        if(visited[child] == 0) {
            dfs(child, cur, (col + col) % 3); // or 3 - col
        } else if(child != par and col == visited[child]) {
            // backedge and odd length cycle
            oddCycle = true;
            return ;
        }
    }
}

int main() {
    // 5 5 1 2 2 3 3 1 3 4 4 5
    // not bipartite
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0, 1);
    cout << (oddCycle ? "not bipartite" : "bipartite");
    return 0;
}
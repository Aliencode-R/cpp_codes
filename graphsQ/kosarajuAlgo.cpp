#include <bits/stdc++.h>
using namespace std;
// algo : order matrix- if a node x is reachable form node y 
// then it comes before it.
// if we reverse the graph and still the x is reachable from y
// that means the are in cycle i.e. connected component

// tc: O(n)

const int N = 100005, M = 22;
vector<int> graph[N], revGraph[N];
vector<int> order; // like reverse topo Sort
int visited[N];
int comp[N]; // tells us in which component is the node present

void dfs(int cur) {
    visited[cur] = 1;
    for(auto x: graph[cur]) {
        if (visited[x] == 0)
        {
            dfs(x);
        }
    }
    order.push_back(cur);
}

void dfsReverse(int cur, int col) {
    comp[cur] = col;
    visited[cur] = 1;
    for (auto x : revGraph[cur])
    {
        if (visited[x] == 0)
        {
            dfsReverse(x, col);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x , y; cin >> x >> y;
        graph[x].push_back(y);
        revGraph[y].push_back(x);
    }
    // filling the order array
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }
    // now starting from the backside of the order
    memset(visited, 0, sizeof(visited));
    int col = 1;
    for(int i = n; i >= 1; i--) {
        if(!visited[order[i]]) { // value at ith index in order

            dfsReverse(order[i], col);
            col++;
        }
    }
    cout << " \nOutput: \n";
    // now print the component of every node
    for(int i = 1; i <= n; i++) {
        cout << i << " -> " << comp[i] << endl;
    }

    return 0;
}
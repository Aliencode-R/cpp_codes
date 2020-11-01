#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
      tree_order_statistics_node_update>
      pbds;

bool bfs(int **residualCapacity, int src, int sink, int n, int *parent) {
    bool visited[n];
    memset(visited, 0, sizeof visited);
    queue<int> q;
    visited[src] = true;
    q.push(src);
    bool foundAugmentedPath = false;
    while(! q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++) {
            if(visited[v] == false and residualCapacity[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if(v == sink) {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugPaths(vector<vi> augPaths) {
    for(int i = 0; i < augPaths.size(); i++) {
        for(int j = 0; j < augPaths[i].size(); j++) {
            cout << augPaths[i][j] << "," ;
        }
        cout << endl;
    }
}

int maxFlow(int **capacity, int src, int sink, int v) {
    int **residualCapacity = new int*[v];
    for(int i = 0; i < v; i++) {
        residualCapacity[i] = new int[v];
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    int *parent = new int[1000];
    vector<vi> augPaths;
    int maxflow = 0;

    while(bfs(residualCapacity, src, sink, v, parent)) {
        vi currentAugPath;
        int flow = imax;
        int v = sink;
        while(v != src) {
            currentAugPath.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v]) {
                flow = residualCapacity[u][v];
            }
            v = u;
        }
        currentAugPath.push_back(src);
        reverse(all(currentAugPath));
        augPaths.push_back(currentAugPath);
        maxflow += flow;

        v = sink;
        while(v != src) {
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
        }
    }
    printAugPaths(augPaths);

    return maxflow;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e; cin >> v >> e;
    int **capacity = new int*[v];
    for(int i = 0; i < v; i++) {
        capacity[i] = new int[v];
    }
    for(int i = 0; i < e; i++) {
        int u, v, c; cin >> u >> v >> c; 
        capacity[u][v] = c;
    }
    cout << maxFlow(capacity, 0, 1, v);
    return 0;
}
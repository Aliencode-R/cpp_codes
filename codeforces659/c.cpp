#include <bits/stdc++.h>
using namespace std;
#define int long long
// pair<int,int> visited[100005];
unordered_map< pair<int,int> , bool > visited;
unordered_map< pair<int,int> , vector<pair<int,int>> > graph;

void dfs(pair<int,int> src, int &c) {
    visited[src] = true;
    c++;
    for(auto nbr: graph[src]) {
        if(visited[nbr] == false) {
            dfs(nbr, c);
        }
    }
}

int32_t main()
{
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // xy a(x1,y1);
        pair<int, int> p = {x1, y1};
        pair<int, int> q = {x2, y2};

        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    // memset(visited, false, sizeof(visited));
    int total = 0;
    for(auto p: graph) {
        if(visited[p.first] == false) {
            int c = 0;
            dfs(p.first, c);
            total += c;
        }
    }
    cout << total - 1;
    
    return 0;
}

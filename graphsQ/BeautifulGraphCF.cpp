#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 1000;
int mod = 998244353;

int p2[N];
vector<int> graph[N];
int cnt[3]; // 0 -> not visited, 1 , 2 are colours
int visited[N];
bool isBipartite;

void dfs(int cur, int col) {

    visited[cur] = col;
    cnt[col] ++;
    for(auto child: graph[cur]) {
        // 2 cases 1. visited, 2. not visited
        if(visited[child] == 0) {
            dfs(child, 3-col);
        } 
        else if(visited[child] == visited[cur]) {
            isBipartite = false;
            return ;
        }
    }
}

int32_t main() {

    p2[0] = 1;
    for (int i = 1; i < N; ++i)
        p2[i] = (2 * p2[i - 1]) % mod;

    int t; cin >> t;
    while(t--) {

        int n, m; cin >> n >> m;

        for (int i = 1; i <= n; i++)
            graph[i].clear();

        for(int i = 0; i < m; i++) 
        {
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int ans = 1;
        for(int i = 1; i <= n; i++) {
            visited[i] = 0;
        }

        isBipartite = true;
        for(int i = 1; i <= n; i++) {

            if(visited[i] != 0) continue;

            cnt[1] = cnt[2] = 0;
            dfs(i, 1);
            if(isBipartite == false) {
                break;
            }
            int c1 = (int)p2[cnt[1]] % mod ;
            int c2 = (int)p2[cnt[2]] % mod;
            int temp = (c1+c2) % mod;
            ans = (ans * temp) % mod;
        }

        if(isBipartite) cout << ans << endl;
        else cout << 0 << endl; 

    }

    return 0;
}
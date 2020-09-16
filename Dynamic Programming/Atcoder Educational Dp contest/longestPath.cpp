#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

const int N = 100005;
// int dist[N];
int dp[N];
vector<int> g[N];

// void helper( int src) {
//     queue<pair<int,int>> q;
//     q.push({src,0});
//     dist[src] = 0;
//     while(q.size() != 0) {
//         int node = q.front().first;
//         int pops = q.front().second;
//         q.pop();
//         for(auto nbr : g[node]) {
//             if(dist[node]+1 >= dist[nbr] and nbr != pops) {
//                 dist[nbr] = max(dist[nbr], 1 + dist[node]);
//                 q.push({nbr,node});
//             }
//         }
//     }
//     return ;
// }

// int bfs(int n, int m) {
//     memset(dist, -1, sizeof dist);

//     for(int i = 1; i <= n; i++) {
//         if(dist[i] == -1) {
//             helper(i);
//         }
//     }
//     int ans = -1;
//     for(int i = 1; i <= n; i++) {
//         ans = max(ans, dist[i]);
//     }
//     return ans;

// }

int solve(int src) {
    if(dp[src] != -1) {
        return dp[src];
    }
    bool leaf = true;
    int bestChild = 0;
    for(int child : g[src]) {
        leaf = false ;
        bestChild = max(bestChild, solve(child));
    }
    if(leaf == true) {
        return dp[src] = 0;
    } else {
        return dp[src] =  1 + bestChild;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans;

    // cout << bfs(n,m);


    return 0;
}
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
char arr[1001][1001];
bool vis[1001][1001][4];
int n, m; 


bool dfs(int i, int j, int turns, int dir) {
    if(i < 0 or j < 0 or i == n or j == m or arr[i][j] == '*' or turns > 2) {
        return false;
    }

    if(vis[i][j][dir]) return false;
    vis[i][j][dir] = true;

    if(arr[i][j] == 'T') {
        return turns <= 2;
    }
    
    bool op1 = dfs(i + 1, j, turns + (dir != 0), 0);
    bool op2 = dfs(i, j - 1, turns + (dir != 1), 1);
    bool op3 = dfs(i, j + 1, turns + (dir != 2), 2);
    bool op4 = dfs(i - 1, j, turns + (dir != 3), 3);

    return op1 or op2 or op3 or op4;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
    // memset(vis, false, sizeof vis);
            if(arr[i][j] == 'S') {

                memset(vis, false, sizeof vis);
                bool ans1 = dfs(i, j, 0, 0);

                memset(vis, false, sizeof vis);
                bool ans2 = dfs(i, j, 0, 1);

                memset(vis, false, sizeof vis);
                bool ans3 = dfs(i, j, 0, 2);

                memset(vis, false, sizeof vis);
                bool ans4 = dfs(i, j, 0, 3);

                ans = ans1 or ans2 or ans3 or ans4;
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO");

    return 0;
}
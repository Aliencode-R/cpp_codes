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
int n, m; 
bool vis[101][101];
vector<pair<int,int>> v;

void print(vector<pii> v) {
    for(pii p : v) cout << p.first << " " << p.second<< endl;
    exit(0);
}

void helper(int x, int y) {
    for(int i = x; i <= n; i++) {
        vis[i][y] = true;
        v.push_back({i,y});
    }
    for(int i = x-1; i >= 1; i--) {
        vis[i][y] = true;
        v.push_back({i,y});
    }
    int j = y+1;
    int toggle = 1; // down going
    while(j <= m) {
        if(toggle == 1) {
            for(int i = 1; i <= n; i++) {
                v.push_back({i,j});
                vis[i][j] = true;
            }
        }
        else {
            for (int i = n; i >= 1; i--)
            {
                v.push_back({i, j});
                vis[i][j] = true;
            }
        }
        j++;
        toggle = 1 - toggle;
    }
    j = y - 1;
    while(j >= 1) {
        if (toggle == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                v.push_back({i, j});
                vis[i][j] = true;
            }
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                v.push_back({i, j});
                vis[i][j] = true;
            }
        }
        j--;
        toggle = 1 - toggle;
    }
    print(v);
}

void helper(int x, int y);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y; cin >> n >> m >> x >> y;
    memset(vis, false, sizeof vis);
    // v.push_back({x,y});
    // vis[x][y] = true;
    helper(x, y);
    return 0;
}
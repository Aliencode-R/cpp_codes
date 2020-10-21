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

string s[500];
int n, m, k; 
int S = 0;
int cnt = 0;

bool oneSideOpen(int i, int j) {
    int blockSides = 0;
    if(i+1 == n or s[i+1][j] == 'X' or s[i+1][j] == '#') {
        blockSides++;
    }
    if (i - 1 == -1 or s[i - 1][j] == 'X' or s[i - 1][j] == '#') {
        blockSides++;
    }
    if (j + 1 == m or s[i][j+1] == 'X' or s[i][j+1] == '#')
    {
        blockSides++;
    }
    if (j - 1 == -1 or s[i][j-1] == 'X' or s[i][j-1] == '#')
    {
        blockSides++;
    }
    if(blockSides == 3) return true;
    return false;
}

void dfs(int i, int j) {
    if(i >= n or j >= m or i < 0 or j < 0 or s[i][j] != 'X') return;
    if(cnt >= S - k) return;
    cnt++;
    s[i][j] = '.';
    if (i + 1 != n and s[i+1][j] == 'X') {
        dfs(i+1, j);
    }
    if (i - 1 != -1 and s[i - 1][j] == 'X')
    {
        // blockSides++;
        dfs(i-1, j);
    }
    if (j + 1 != m and s[i][j+1] == 'X')
    {
        // blockSides++;
        dfs(i, j+1);
    }
    if (j - 1 != -1 and s[i][j-1] == 'X')
    {
        // blockSides++;
        dfs(i, j-1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> s[i];
    bool find = false;
    for(int i = 0; i<n; i++) {
        for(int j = 0;j <m ; j++) {
            if(s[i][j] == '.'){
                s[i][j] = 'X';
                S++;
            }
        }
    }
    // cout << S << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(find == false and s[i][j] == 'X') {
                dfs(i, j);
                // cout << i << " " << j << endl;
                find = true;
                
            }
        }
    }
    // if(!find) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < m; j++) {
    //             if(find == false and k != 0 and s[i][j] == '.') {
    //                 dfs(i, j);
    //                 find = true;
    //             }
    //         }
    //     }
    // }
    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }


    return 0;
}
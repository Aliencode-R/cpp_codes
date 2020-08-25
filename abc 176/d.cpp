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
int h, w;
int dp[1000][1000];
bool vis[1000][1000];


bool oob(int ch, int cw) {
    return (ch >= 0 and cw >= 0 and ch < h and cw < w);
}

int dfs(char arr[1000][1000], int ch, int cw, int dh, int dw) {
    cout << ch << " " << cw << endl;
    cout << "hello";
    if(!oob(ch, cw))
        return -1;
    if (vis[ch][cw] = true) {
        return dp[ch][cw];
    }
    vis[ch][cw] = true;
    if(arr[ch][cw] == '#' ) {
        return dp[ch][cw] = -1;
    }
    if(ch == dh and cw == dw)
        return dp[ch][cw] = 0;

    if(dp[ch][cw] != -2)
        return dp[ch][cw];

    int ans = INT_MAX;

    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            if(i == 0 and j == 0) continue;
            
            int temp = dfs(arr, ch+i, cw+j, dh, dw);
            if(temp >= 0) {
                ans = min(ans, temp);
                cout << ans << endl;
            }
        }
    }
    return dp[ch][cw] = ans;    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    
    int ch, cw; cin >> ch >> cw;
    ch--, cw--;
    int dh, dw; cin >> dh >> dw;
    dh--, dw--;
    memset(vis, false, sizeof(vis));
    char arr[1000][1000];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            dp[i][j] = -2;
            cin >> arr[i][j];
        }
    }
    cout << dfs(arr, ch, cw, dh, dw);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << dp[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}
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
int k ;

bool isCorner(char arr[500][500], int x, int y, int n, int m) {
    int count = 0;
    if(x+1 < n and arr[x+1][y] == '.'){
        count ++;
    }
    if (x-1 >= 0 and arr[x - 1][y] == '.')
    {
        count++;
    }
    if (y+1 < m and arr[x][y+1] == '.')
    {
        count++;
    }
    if (y-1 >= 0 and arr[x][y-1] == '.')
    {
        count++;
    }
    if(count == 1) return true;
    return false;
}

void dfs(char arr[500][500], int x, int y, int n, int m) {
    if(k == 0) return;
    if(!isCorner(arr, x, y, n, m)) return;
    k--;
    arr[x][y] = 'X';
    if (x + 1 < n and arr[x + 1][y] == '.')
    {
        
        dfs(arr, x+1, y, n, m);
    }
    if (x - 1 >= 0 and arr[x - 1][y] == '.')
    {
        
        dfs(arr, x - 1, y, n, m);
    }
    if (y + 1 < m and arr[x][y + 1] == '.')
    {
        dfs(arr, x, y + 1, n, m);
    }
    if (y - 1 >= 0 and arr[x][y - 1] == '.')
    {
        dfs(arr, x, y-1, n, m);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m >> k;
    char arr[500][500];
    for(int i = 0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.' and isCorner(arr, i, j, n, m)) {
                x = i;
                y = j;
                dfs(arr, x, y, n, m);
                if(k == 0) break;
            }
        }
    }   
    while(k != 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == '.') {
                    arr[i][j] = 'X';
                    k--;
                
                }
            }
        }
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
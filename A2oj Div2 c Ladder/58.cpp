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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    char arr[n][n];
    for(int i = 0; i < n; i ++) {
        for(int j = 0;j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == '.') {
                v.push_back({i,j});
                for(int k = 0; k < n; k++) {
                    if(arr[i][k] == '.') 
                        arr[i][k] = 'p';
                    else if(arr[i][k] == 'E'){
                        arr[i][k] = 'P';
                    }
                }
                for(int k = 0; k < n; k++) {

                    if (arr[k][j] == '.')
                        arr[k][j] = 'p';
                    else if (arr[k][j] == 'E')
                    {
                        arr[k][j] = 'P';
                    }
                }
                continue;
            }
        }
    }
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if(arr[i][j] == '.' or arr[i][j] == 'p') {
                bool flag = false;
                for(int k = 0; k < n; k++) {
                    if (arr[i][k] == '.')
                    {
                        flag = true;
                        arr[i][k] = 'p';
                    }
                    if (arr[i][k] == 'E')
                    {
                        flag = true;
                        arr[i][k] = 'P';
                    }
                }
                for (int k = 0; k < n; k++)
                {
                    if (arr[k][j] == '.')
                    {
                        flag = true;
                        arr[k][j] = 'p';
                    }
                    if (arr[k][j] == 'E')
                    {
                        flag = true;
                        arr[k][j] = 'P';
                    }
                }
                if(flag) {
                    v.push_back({i,j});
                }
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == '.' or arr[i][j] == 'E') {
                cout << -1 ;
                return 0;
            }
        }
    }
    for(auto p : v) {
        cout << p.first+1 << " " << p.second+1;
        cout << endl;
    }

    return 0;
    }
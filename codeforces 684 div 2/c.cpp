#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
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
#define sz(x) ((int)x.size())
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

void helperfinal(int n, int m, string *arr, int i, int j) {
    if(arr[i][j] == '1')
        cout << i+1 << " " << j+1 << endl;
    if (arr[i][j-1] == '1')
        cout << i+1 << " " << j << endl;
    if (arr[i-1][j] == '1')
        cout << i << " " << j+1 << endl;
    if (arr[i-1][j-1] == '1')
        cout << i << " " << j << endl;
    return;
}

void helpersingle(int n, int m, string *arr, int i, int j){
    if (arr[i][j] == '1' or arr[i - 1][j - 1] == '1')
    {
        cout << i - 1 + 1 << " " << j +1 << " " << i +1<< " " << j -1 +1<< " ";
        if (arr[i][j] == '1') {
            cout << i+1 << " "<< j +1<< endl;
        } else {
            cout << i - 1 +1 << " " << j - 1+1 << endl;
        }
    }
    else {
        cout << i - 1+1<< " " << j - 1+1 << " " << i +1<< " " << j +1<< " ";
        if(arr[i][j-1] == '1') {
            cout << i+1 << " " << j - 1+1 << endl;
        } else {
            cout << i - 1+1 << " " << j +1<< endl;
        }
    }
    helperfinal(n, m, arr, i, j);
}

void helperpair(int n, int m, string *arr, int i, int j){
    if (arr[i][j] == '1')
        cout << i + 1 << " " << j + 1 << endl;
    if (arr[i][j - 1] == '1')
        cout << i + 1 << " " << j << endl;
    if (arr[i - 1][j] == '1')
        cout << i << " " << j + 1 << endl;
    if (arr[i - 1][j - 1] == '1')
        cout << i << " " << j << endl;
    bool flag = false;
    if (arr[i][j] == '0' and flag == false)
        cout << i + 1 << " " << j + 1 << endl, flag = true;
    if (arr[i][j - 1] == '0' and flag == false)
        cout << i + 1 << " " << j << endl, flag = true;
    if (arr[i - 1][j] == '0' and flag == false)
        cout << i << " " << j + 1 << endl, flag = true;
    if (arr[i - 1][j - 1] == '0' and flag == false)
        cout << i << " " << j << endl, flag = true;

    helpersingle(n, m, arr, i, j);
}

void helper(int n, int m, string *arr, int i, int j)
{
    int count = 0;
    if (arr[i][j] == '1')
        count++;
    if (arr[i][j - 1] == '1')
        count++;
    if (arr[i - 1][j] == '1')
        count++;
    if (arr[i - 1][j - 1] == '1')
        count++;

    if(count == 3) {
        helperfinal(n, m, arr, i, j);
    }    
    if(coun)

    // check diagnol



}

void solve () {
    int n, m; cin >> n >> m;
    string arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            helper(n, m, arr, i, j);
        }
    }
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
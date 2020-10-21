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
    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(i == j) {
                sum = (sum + arr[i][j]) % 2;
            }
        }
    }
    // cout << sum;
    int q; 
    cin >> q;
    while(q--) {
        int query; cin >> query;
        if(query == 3) {
            cout << sum;
            continue;
        }
        int x; cin >> x;
        sum = 1-sum;
        // cout << sum;
    }

    return 0;
}
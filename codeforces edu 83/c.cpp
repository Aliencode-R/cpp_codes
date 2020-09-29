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

const int Mx = 1e16+1;

int val(int n, int k) {
    int sum = 0;
    int j = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            sum += pow(k, (j-1));
        }
        j = (j << 1);
        n = (n >> 1);
        if(sum >= Mx) return -1;
    }
    return sum;
}

bool visHelp(bool *vis, int n) {
    int i = 0;
    while(n != 0) {
        int bit = (n & 1);
        if(bit == 1 and vis[i] == 1) return false;
        vis[i] = true;
        i++;
        n = (n >> 1);
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << val(64,9);
    int t; cin >> t; 
    while(t--) {
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool vis[65] = {};
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) continue;
            for(int j = 0; j <= 64; j++) {
                int Val = val(j,k);
                if(Val == arr[i]) {
                    if(!visHelp(vis, j) ) {
                        flag = false;
                        break;
                    }
                    continue;
                }
                if(Val == -1) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}
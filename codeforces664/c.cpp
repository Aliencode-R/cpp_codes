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
    int n, m; cin >> n >> m;
    int arr[n], brr[m];
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool z = false;
    for(int j = 0; j < m; j++) {
        cin >> brr[j];
        if(brr[j] == 0) {
            z = true;
            break;
        }
    }
    if(z) {
        cout << 0 ;
        return 0;
    }
    for(int a = 0; a < pow(2,9); a++) {
        bool isA = true;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < m; j++) {
                if(a == ((arr[i] & brr[j]) | a)){
                    flag = true;
                    break;
                }
            }
            if(flag) {
                continue;
            } else {
                isA = false;
            }
        }
        if(isA) {
            cout << a ;
            return 0;
        }
    }
    // cout << ans;
    return 0;
}
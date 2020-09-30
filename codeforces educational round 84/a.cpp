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

int arr[10000];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int sum = 1;
    // arr[1] = 1;
    // for(int i = 2; i <= 10000; i++) {
    //     arr[i] = arr[i-1] + 2;
    // }
    int t; cin >> t; 
    while(t--) {
        int n, k; cin >> n >> k;
        if(n < k * k) {
            cout << "NO" << endl;
            continue;
        }
        if(n % 2 == 0) {
            if(k % 2 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            if (k % 2 == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
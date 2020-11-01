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
    if(n % 2 == 0) {
        cout << "NO" ;
        return 0;
    }
    int *arr = new int[2*n + 1];
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            arr[i] = 2*i-1;
            arr[i+n] = 2*i;
        } else {
            arr[i] = 2*i;
            arr[i+n] = 2*i-1;
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= 2*n; i++) cout << arr[i] << " " ;
    // for(int )
    return 0;
}
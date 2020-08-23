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
    int n, k; cin >> n >> k;
    if(k < n/2) {
        cout << -1;
        return 0;
    }
    if(k == n/2) {
        for(int i = 1; i <= n; i++) cout << i << " ";
        return 0;
    }
    int n1; 
    if(n%2) n1 = n-2;
    else n1 = n-3;
    for(int i=2; i<=n1; i++) cout << i << " ";
    int nk = (n-2)/2;
    int temp = k - nk;
    cout << temp << " " << 2*temp << " ";
    // if(n % 2 == 1) cout << 


    return 0;
}
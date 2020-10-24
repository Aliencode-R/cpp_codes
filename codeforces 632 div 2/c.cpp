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
    int arr[n+1] = {}; 

    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++) arr[i] += arr[i-1];

    map<int, int> m; 
    m[0] = 1;
    int last = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        last = max(last, m[arr[i]]);
        m[arr[i]] = i+1;
        ans += (i - last);   
    }
    cout << ans; 

    return 0;
}
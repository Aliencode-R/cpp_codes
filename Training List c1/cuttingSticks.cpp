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

int arr[52];

int helper(int i, int j) {
    if(i > j) return imax;
    if(i + 1 == j) return 0;
    int ret = imax;
    for(int k = i+1; k < j; k++) {
        ret = min(ret, helper(i, k) + helper(k, j) + arr[j] - arr[i]);
    }
    return ret; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total, n; 
    while(cin >> total) {
        if(total == 0) break;
        cin >> n ;
        // int arr[n];
        arr[0] = 0;
        arr[n+1] = total;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        cout << "The minimum cutting is " << helper(0, n + 1) << endl;
    }
    return 0;
}
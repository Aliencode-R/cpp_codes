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

int freq[200020] = {};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k; 
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int mn = imax;
    int N = imin;
    for(int i = 0; i <n; i++){
        N = max(N, arr[i]);
        mn = min(arr[i], mn);
    }
    vector<int> v; 
    for(int i = 0; i< n; i++){
        arr[i] -= mn;
        if(arr[i] != 0) v.push_back(arr[i]);
    }
    sort(all(v));
    vector<int> b;
    
    for(int i = 0; i<n; i++){
        freq[arr[i]]++;
    } 
    if(freq[0] == n) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    int temp = k;
    for(int i = 0; i <= N - mn + 1; i++) {
        if(temp <= 0) {
            ans ++;
            temp = k;
        }
        temp -= freq[i];
    }
    cout << ans; 

    return 0;
}
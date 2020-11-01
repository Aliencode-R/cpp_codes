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
    int n, p; cin >> n >> p;
    int arr[n];
    int mn = imax;
    int mi;
    p--;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        // mn = min(mn, arr[i]);
        if(mn > arr[i]) {
            mn = arr[i]; 
            mi = i;
        }
    }

    for(int i = 0; i < n; i++) arr[i] -= mn;

    int ans = mn * n;
    int index = p; 
    while(arr[index] != 0) {
        arr[index]--;
        ans++;
        index--;
        if(index == -1) index = n-1;
    }
    arr[index] = ans;

    for(int i : arr) cout << i << " " ;


    return 0;
}
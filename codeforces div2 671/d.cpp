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
    int arr[n]; 
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int j = n-1; 
    int i = 0;
    // int ans = 0;
    int toggle = 0;
    vector<int> v;
    while(i <= j) {
        if(toggle == 1) {
            v.push_back(arr[i]);
            i++;
         
        } else {
           
            v.push_back(arr[j]);
            j--;
        }
        toggle = 1-toggle;
    }

    int ans = 0;
    // int s = v.size();
    for(int i = 1; i < n-1; i++) {
        if(v[i] < v[i-1] and v[i] < v[i+1]) {
            ans ++;
        }
    }
    cout << ans << endl;
    for(int x : v) cout << x << " ";
    return 0;
}
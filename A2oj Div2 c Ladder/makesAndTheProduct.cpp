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
    int n; cin >>n; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    sort(arr, arr+n);
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    umap<int,int> m;
    for(int i = 0; i < n; i++) {
        m[arr[i]] ++;
    }
    if(a == b and b == c) {
        int n = m[a];
        cout << (n * (n - 1) * (n - 2)) / 6;
    } else if(a == b) {
        int ans = 0;
        int n1 = m[b] - 1;
        // for(int i = 1; i < n1; i++) {
        //     ans += i * (n1 - i);
        // }
        ans = (n1 * (n1 + 1) ) / 2;
        cout << ans * m[c];
    } else if( b == c) {
        int ans = 0;
        int n1 = m[b] - 1;
        // for (int i = 1; i < n1; i++)
        // {
        //     ans += i * (n1 - i);
        // }
        ans = (n1 * (n1 + 1)) / 2;
        cout << ans * m[a];
    }
    else {
        cout << m[a] * m[b] * m[c];
    }
    return 0;
}
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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[n]; 
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int z = 0, o = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                z++;
            }
            else {
                o++;
            }
        }
        int p;
        if(z >= n/2) {
            p = 0;
        } else {
            p = 1;
        }
        int N;
        if(p == 1) {
            // cout << n/2 << endl;
            if((n/2) % 2 == 0)  {
                N = n/2;
            }
            else {
                N = n/2+1;
            }
        }
        else {
            N = z;
        }
        // cout << max(z,o) << endl;
        cout << N << endl;
        for(int i = 0; i < N; i++) {
            cout << p << " ";
        }
        cout << endl;

    }
    return 0;
}
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
        pair<int,int> a, b;
        int arr[n];
        for(int i = 0; i< n; i++) {
            cin >> arr[i];
        }
        a.first = b.first = -1;
        for(int i = 0; i <n; i++) {
            if(a.first == -1) {
                a.first = arr[i];
                a.second = i;
            } else if(b.first == -1 and arr[i] != a.first) {
                b.first = arr[i];
                b.second = i;
            }
        }
        if(b.first == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                if(i == a.second) continue;
                if(arr[i] == a.first) {
                    cout << b.second+1 << " " << i+1 << endl;
                } else {
                    cout << a.second+1 << " " << i+1 << endl;
                }
            }
        }
    }
    return 0;
}
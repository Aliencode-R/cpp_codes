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
        for(int i = 0; i < n; i++) cin >> arr[i];
        vector<int> v; 
        int zero = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i]== 0) {
                zero++;
            }
        }
        for(int i = 0; i <n; i++) {
            if(arr[i] == 1) break;
            zero--;
        }
        for(int j = n-1; j >= 0; j--) {
            if(arr[j] == 1) break;
            zero--;
        }
        cout << zero << endl;
    }
    return 0;
}
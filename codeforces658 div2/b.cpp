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
// #define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool a1 = true;
        int arr[n];
        for(int i =  0; i < n; i++){
            cin >> arr[i];
            if(arr[i] != 1) 
                a1 = false;
        } 
        if(a1) {
            if(n % 2 == 0) cout << "Second" << endl;
            else cout << "First" << endl;
            continue;
        }
        
    int toggle = 1;
    int ans;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 1) {
            ans = toggle;
            break;
        }
        toggle = 1-toggle;
    }
    if(toggle == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    }
    return 0;
}
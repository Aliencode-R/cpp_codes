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

int sum (int n) {
    return (n * (n + 1)) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n, k; cin >> n >> k;
        
        int start = 1, end = 2000000000;
        int b1, b2;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(sum(mid) < k and sum(mid+1) >= k ) {
                b1 = mid + 1;
                b2 = k - sum(mid) - 1;
                break;
            } else if(sum(mid) > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } 
        // cout << b1 << " " << b2 << " " ;
        string s; 
        if(k == 1) {
            b1= 0;
            b2 = 1;
        }
        for(int i = 0; i < n; i++) {
            if(i == b1 or i == b2) {
                s = 'b' + s;
            } else {
                s = 'a' + s;
            }
        }
        cout << s << endl;
    }
    return 0;
}
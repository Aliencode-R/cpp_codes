#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int main() {
    int l, r, d;
    cin >> l >> r >> d;
    int ans = 0;
    for(int i = l; i <= r; i++) {
        if(i % d == 0) {
            ans ++;
        }
    }
    cout << ans;
    // if(l / d == 1) {
    //     cout << r / d - l / d + 1;
    // }
    // else {
    // cout << r / d - l / d;

    // }
    return 0;
}
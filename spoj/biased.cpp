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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        int arr[n+1] = {0};
        for(int i = 0; i < n ;i++) {
            string a;
            cin >> a;
            ll num;
            cin >> num;
            arr[num] ++;
        }

        ll ans = 0;
        ll cur = 1;
        for(int i = 1; i <= n; i++) {
            while(arr[i] != 0) {
                ans += abs(i - cur);
                arr[i]--;
                cur++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
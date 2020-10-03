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

int helper(int n) {
    int ans = 0;
    while(n) {
        if(n % 10 == 9) {
            ans++;
            n /= 10;
        } else {
            return ans;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d; cin >> n >> d;
    int ans = n;
    int k = 10;
    int mx = helper(n);
    while(true) {
        int a = n - n % k - 1;
        if(n - a <= d and a != -1) {
            if(helper(a) > mx)
                ans = a;
            k *= 10;
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}
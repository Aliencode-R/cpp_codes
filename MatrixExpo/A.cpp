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

double helper(int n, double p) {
    double phappy = 1.0;
    while(n > 0) {
        if(n % 2 == 1) {
            phappy = phappy * (1-p) + p * (1-phappy);
        }
        p = p * (1-p) + (1-p) * p;
        n /= 2;
    }
    return phappy;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    double p; cin >> p;
    cout << fixed << setprecision(9) << helper(n, p);
    return 0;
}
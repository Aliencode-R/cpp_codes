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

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    int l = lcm(a, b);
    int fa = (l - a) / a;
    int fb = (l - b) / b;
    if(fa < fb) fa ++;
    else fb++;
    // cout << (fa < fb ? "Masha" : "Dasha");
    if(fa < fb) {
        cout << "Masha";
    } else if(fb < fa) {
        cout << "Dasha";
    } else {
        cout << "Equal";
    }
    return 0;
}
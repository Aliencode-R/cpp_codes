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
const int N = 1000006;

int f[N];
void fact() {
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= N; i++) {
        f[i] = (i * f[i-1]) % mod;
    }
    return;
}


bool isExc(int n, int a, int b) {
    while(n != 0) {
        if(n % 10 == a or n % 10 == b) {
            n /= 10;
            continue;
        }
        return false;

    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact();
    int a, b, n; cin >> a >> b >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int j = n - i;
        int sum = (i * a + j * b);
        // cout << sum << "-";
        // cout << endl;
        if(isExc(sum, a, b)) {
            cout << sum << " "; 
            cout << i << " " << j << endl;   
            ans += (f[n] / (f[i] * f[j]));
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}
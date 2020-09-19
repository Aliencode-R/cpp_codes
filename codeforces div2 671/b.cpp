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

int p(int x, int m)
{
    if (m == 0)
        return 1;

    if (m % 2 == 0) // even power
    {
        int val = p(x, m / 2);
        return val * val;
    }
    else
    {
        int val = p(x, m / 2);
        return val * val * x;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v(60); 
    v[0] = 1;
    for(int i = 1; i < 60; i++) {
        int tillNow = v[i-1];
        int x = p(2, i);
        x = p(x, 2);
        x +=  2*tillNow;
        v[i] = x;
    }
    // for(int i = 0; i < 5; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 0; i < 60; i++) {
            if(n - v[i] >= 0) {
                ans ++;
                n -= v[i];
            } 
            else {
                break;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
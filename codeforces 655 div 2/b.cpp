#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
void findfactor(int n, vector<int> &v)
{
    v.push_back(1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >>n; 
        if(n%2 == 0) {
            cout << n / 2 << " " << n/2 << endl;
            continue;
        }
        vi v;
        findfactor(n, v);
        sort(rall(v));
        cout << v[0] << " " << n - v[0] << endl;
    }
    return 0;
}
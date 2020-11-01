#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
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
vector<pii> printFactors(int n)
{
    vector<pair<int, int>> factors;

    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            factors.push_back(make_pair(i, count));
        }
    }
    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }

    // for (auto p : factors)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    return factors;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int p, q; cin >> p >> q; 
        if(p % q != 0) {
            cout << p << endl;
            continue;
        }

        int ans = infl;
        
        vector<pii> v = printFactors(q);
        for(auto pr : v) {
            int num = pr.first;
            int powP = 0;
            int temp = p;
            while(temp % num == 0) {
                powP++;
                temp /= num;
            }
            debug(powP);
            int diff = powP - pr.second + 1;
            int newP = pow(pr.first, diff);
            debug(newP);
            ans = min(ans, newP);

        }
        cout << p / ans << endl;


    }
    return 0;
}
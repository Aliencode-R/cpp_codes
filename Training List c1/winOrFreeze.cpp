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
                factors.push_back(make_pair(i, count));
            }
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
    // return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl << 0;
        return 0;
    }
    vector<pii> v = printFactors(n);
    int ans = 1;
    if(v.size() == 2) {
        cout << 2;
        return 0;
    }
    if(v.size() == 1) 
    {
        cout << 1 << endl << 0 ;
        return 0;
    }
    // for(int i = 0; i < v.size() - 2; i++) {
    //     ans *= v[i].first;
    // }
    ans *= v[0].first * v[1].first;
    cout << 1 << endl << ans;

    return 0;
}
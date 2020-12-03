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
#define sz(x) ((int)x.size())
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define deb(x...)
#endif

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
    return factors;
    // // for (auto p : factors)
    // // {
    // //     cout << p.first << " " << p.second << endl;
    // // }
    // return;
}

bool isprime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve () {
    int n; cin >> n; 
    if(isprime(n)) {
        cout << 1 << endl << n << endl;
        return;
    }

    vector<pii> factors = printFactors(n);
    pii p = {-1, -1};
    for(int i =0; i < sz(factors); i++) {
        if(factors[i].second > p.second) {
            p = factors[i];
        }
    }
    int s = 0;
    vi ans;
    for(int i = 1; i < p.second; i++) {
        ans.push_back(p.first);
    }
    int last = p.first;
    for(int i = 0; i < sz(factors); i++) {
        if(factors[i] == p) continue;
        for(int j = 0; j < factors[i].second; j++) {
            last *= factors[i].first;
        }
    }
    ans.push_back(last);
    cout << sz(ans) << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
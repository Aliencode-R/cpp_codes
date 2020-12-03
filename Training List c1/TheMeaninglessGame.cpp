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

    // for (auto p : factors)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    return factors;
}

// void solve () {
//     int a , b; cin >> a >> b;
//     vector<pii> faca = printFactors(a);
//     vector<pii> facb = printFactors(b);

//     // deb(faca);
//     // deb(facb);

//     if(sz(faca) != sz(facb)) {
//         cout << "No" << endl;
//         return;
//     }
//     bool flag = true;
//     for(int i = 0; i < sz(faca); i++) {
//         if(faca[i].first != facb[i].first) {
//             flag = false;
//             break;
//         }
//         int p = faca[i].second;
//         int q = facb[i].second;
//         if(p > q) swap(p, q);

//         int sum = p + q;

//         if(sum % 3 == 0 and 2 * p >= q) {
//             // ok
//         } else {
//             flag = false;
//             break;
//         }
//     }
//     if(flag) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }
// }

void solve() {
    int a, b; cin >> a >> b; 

    int ab = cbrt(a * b);

    int s = a / ab;
    int p = b / ab;

    if(s * s * p == a and p * p * s == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
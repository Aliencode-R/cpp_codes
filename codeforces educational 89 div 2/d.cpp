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

void findfactor(int n, vector<int> &v)
{
    // v.push_back(1);
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
    v.push_back(n);
}

void solve () {
    int n; cin >> n; 
    vector<int> arr(n);
    for(int i =0; i < n; i++) cin >> arr[i];
    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        vector<int> fac;
        findfactor(num, fac);
        sort(all(fac));
        // deb(fac);
        pii cur = {-1, -1};
        bool flag = false;
        for(int l = 0;l < sz(fac); l++) {
            if(flag) break;
            for(int j = l + 1; j < sz(fac); j++) {
                if(flag) break;
                if(__gcd(fac[l] + fac[j], num) == 1) {
                    cur = {fac[l], fac[j]};
                    flag = true;
                }
            }
        }
            deb(num, cur);
            ans.push_back(cur);
    }
    // deb(n);
    deb(ans);
        // for(int i = 0; i < n; i++) {
        //     cout << arr[i] << " " << ans[i].first << " " << ans[i].second << endl;
        // }
        cout <<endl;
        for (int i = 0; i < n; i++)
            cout << ans[i].first << " ";
            cout << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i].second << " ";
        cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
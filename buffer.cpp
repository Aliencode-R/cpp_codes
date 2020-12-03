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
#define f first
#define s second
#define pb push_back
#define mp make_pair
// #define inf 1e9
#define infl 1e18
#define sz(x) ((int)x.size())
#define int long long

void __print(long x)
{
    cerr << x;
}
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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

const int maxn = 200500;
const int inf = (2e9) + 2;

vector<pair<pair<int, int>, pair<int, int>>> queries;
vi bestCost(maxn);

int l[maxn];
int r[maxn];
int cost[maxn];

int solution(int n, int needLen)
{
    queries.clear();
    for (int j = 0; j < n; j++)
    {
        queries.pb(mp(mp(l[j], -1), mp(r[j], cost[j])));
        queries.pb(mp(mp(r[j], 1), mp(l[j], cost[j])));
    }
    for (int j = 0; j < maxn; j++)
        bestCost[j] = inf;
    ll ans = 2LL * inf;
    sort(queries.begin(), queries.end());
    // deb(queries);
    int sz = queries.size();
    for (int j = 0; j < sz; j++)
    {
        int type = queries[j].f.s;
        // lr 
        if (type == -1)
        {
            int curLen = queries[j].s.f - queries[j].f.f + 1;
            if (curLen <= needLen)
                ans = min(ans, 1LL * queries[j].s.s + 1LL * bestCost[needLen - curLen]);
        }
        // rl
        if (type == 1)
        {
            int curLen = queries[j].f.f - queries[j].s.f + 1;
            bestCost[curLen] = min(bestCost[curLen], queries[j].s.s);
        }
        // deb(j, type, ans);
    }
    // deb(bestCost);

    return ans >= inf ? -1 : ans;
}


void solve () {
    int n, x; cin >> n >> x; 
    for(int i = 0; i < n; i++) { 
        cin >> l[i] >> r[i] >> cost[i];
    }
    cout << solution(n, x) << endl;
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
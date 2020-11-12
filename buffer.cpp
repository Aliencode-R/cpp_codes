#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << " " << x << endl
#define clr(x, v) memset(x, v, sizeof(x))
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    vector<int> need(k);
    for (int &x : need)
        cin >> x;
    sort(allr(arr));
    sort(all(need));
    int pos = 0;
    ll sum = 0;
    vector<int> left;
    for (int i = 0; i < k; i++)
    {
        if (need[i] == 1)
        {
            sum += arr[pos] * 2LL;
        }
        else
        {
            sum += arr[pos];
            left.pb(need[i] - 1);
        }
        pos++;
    }
    sort(allr(left));
    // for(int i : left) cout << i << "," ;
    cout << endl;
    pos = n - 1;
    for (int i : left)
    {
        sum += arr[pos];
        pos -= i;
    }
    cout << sum << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        cp();
    }
    return 0;
}
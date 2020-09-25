/*
Just Another Source code by -
Ambuj              
*/
#include <bits/stdc++.h>
using namespace std;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define VP vector<pll>
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FF first
#define SS second
#define teji                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define DI \
    int n; \
    cin >> n;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int sum()
{
    return 0;
}

template <typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }
bool desc(int a, int b)
{
    return a > b;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll fac[300006];

ll recpow(ll n, ll p, ll m)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * n % m;
        n = n * n % m;

        p >>= 1;
    }
    return ans;
}
ll modInverse(ll n, ll p)
{
    return recpow(n, p - 2, p);
}

ll nCr(ll n, ll r, ll p)
{

    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt", "r", stdin);
//     freopen("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt", "w", stdout);
// #endif
    ll p = 998244353;
    fac[0] = 1;
    for (int i = 1; i <= 300006; i++)
    {
        fac[i] = (fac[i - 1] * i) % p;
    }
    ll n, k;
    cin >> n >> k;
    VP v;
    rep(i, 0, n)
    {
        ll l, r;
        cin >> l >> r;
        v.pb({l, 0});
        v.pb({r, 1});
    }
    sort(all(v));
    // for(auto p : v) cout << p.first << " " << p.second << endl;
    ll ans = 0, cnt = 0;
    rep(i, 0, v.size())
    {
        if (v[i].SS == 0)
        {
            cnt++;
            if (cnt >= k)
                ans = ans + nCr(cnt - 1, k - 1, p);
            ans %= p;
        }
        else
        {
            cnt--;
        }
    }
    cout << ans << endl;

    return 0;
}
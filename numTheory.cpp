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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll fac[300006];

ll power(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = (__int128)r * b % m;
        b = (__int128)b * b % m;
        p /= 2;
    }
    return r;
}

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

long long C(int n, int m) // ncr 2  
{
    long long result(1);
    for (int i = 0; i < m; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

void findfactor(int n) // all factors 
{
    vector<int> v;
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
    for (int i : v)
        cout << i << " ";
}

const int MAXN = 1e3 + 5;

ll fact[MAXN];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y = y / 2;
    }
    return res;
}

ll inv(ll a)
{
    return fpow(a, mod - 2);
}

ll ncr(int n, int r)
{
    if (n < r)
        return 0;

    ll ans = fact[n];
    // nCr = n!/(n-r)!/r!
    // nCr = n! * inv((n-r)!) * inv(r!)
    ans = (ans % mod * inv(fact[n - r]) % mod) % mod;
    ans = (ans % mod * inv(fact[r]) % mod) % mod;
    return ans;
}
// prefix mex
set<int> S;
for (int i = 1; i <= no_of_elements; i++)
{
    S.insert(i);
}

vector<int> prefix_mex(no_of_elements + 1);
for (int i = 1; i <= no_of_elements; i++)
{
    if (S.find(A[i]) != S.end())
    {
        S.erase(A[i]);
    }

    prefix_mex[i] = *(S.begin());
}
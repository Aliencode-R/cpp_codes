#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define lim 100
vector<bool> mark(lim + 2, 1);
vector<ll> primes;
void sieve() // we need primes upto 10^8
{
    //ll times = 0;
    for (ll i = 3; i <= lim; i += 2)
    {
        //times++;
        if (mark[i] == 1)
        {
            for (ll j = i * i; j <= lim; j += 2 * i) //skip to odd numbers as i*i is odd
            {
                mark[j] = 0;
            }
        }
    }
    primes.pb(2);
    for (ll i = 3; i <= lim; i += 2)
    {
        if (mark[i])
            primes.pb(i);
    }
}

vector<ll> factorize(ll m)
{
    vector<ll> factors;
    factors.clear();
    ll i = 0;
    ll p = primes[i];
    while (p * p <= m)
    {
        if (m % p == 0)
        {
            factors.pb(p);
            while (m % p == 0)
                m = m / p;
        }
        // if(m % p == 0) {
        //     int count = 0;
        //     while(m % p == 0) {
        //         count ++;
        //         m /= p;
        //     }
        //     factors.push_back({p, count});
        // }
        i++;
        p = primes[i];
    }
    if (m != 1)
        factors.pb(m);
    return factors;
}

int main()
{
    sieve();
    int n;
    cin >> n;
    vector<ll> a = factorize(n);
    for (auto x : a)
    {
        cout << x << ' ';
    }
}
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

vector<ll> primes;

vector<bool> primeSieve(ll n)
{

    vector<bool> p(n + 1, false);

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for (ll i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for (ll i = 3; i <= sqrt(n); i += 2)
    {

        if (p[i])
        {
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for (ll j = i * i; j <= n; j += 2 * i)
            {
                p[j] = 0;
            }
        }
    }
    return p;
}

// 1E6 - 1000000
vector<ll> prime_numbers()
{
    vector<bool> p = primeSieve(1E6);
    // vector<ll> primes;
    primes.push_back(2);

    for (ll i = 3; i < 1E6; i++)
    {
        if (p[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

set<ll> divisors(ll n)
{
    set<ll> div;
    div.insert(1);
    // for (int i = 0; i < 20; i++)
    //     cout << primes[i] << ",";
    // cout << endl;
    for (ll i = 0; primes[i] <= sqrt(n); ++i)
    {
        if (n % primes[i] == 0)
        {
            ll num = n;
            div.insert(primes[i]);
            cout << primes[i] << ": " ;
            while (num and n % num == 0)
            {
                div.insert(num);
                num /= primes[i];
                cout << num << ",";
            }
            cout << endl;
            // div.insert(primes[i]);
            // div.insert(n / primes[i]);
        }
    }
    return div;
}

void findfactor(int n, vector<int> &v)
{
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
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes = prime_numbers();
    cout << endl;
    int n; cin >> n; 
    set<int> s = divisors(n);
    vector<int> v;
    findfactor(n, v);
    sort(all(v));
    for(int x : s) cout << x << " " ;
    cout << endl;
    for(int x : v) cout << x << " ";
// #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
    return 0;
}
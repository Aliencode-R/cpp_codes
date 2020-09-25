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
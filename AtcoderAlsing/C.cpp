#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read

#define ll long long

ll sieve[10002] = {0};


void makeSieve() {
    for(ll i = 1; i <= 40; i++) {
        for(ll j = i; j <= 70; j++) {
            for(ll k = j; k <= 10000; k++)
            {
                ll n = i*i + j*j + k*k + i*j + j*k + i*k;
                if (n <= 10000) {

                    if (i == j and k == j)
                    {

                        sieve[n] += 1;
                    }
                    else  {
                        sieve[n] += 3;
                    }
 
                }
            }
        }
    }
}

int main()
{
    ll n; cin >> n;
    makeSieve();
    for(ll i = 1; i <= n; i++) {
        cout << i << " " <<  sieve[i] << endl;
    }
    return 0;
}
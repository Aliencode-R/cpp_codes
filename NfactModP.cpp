#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000009

ll exponentMod(ll A, ll B, ll C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
 
    ll y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (ll)((y + C) % C); 
} 
  

ll modInv(ll a, ll m)
{
    return exponentMod(a, m-2, m);
}

void helper(ll n, ll p)
{    ll ans = 1;
    for(ll i = n+1; i < p; i++)
    {
        ans *= i;
        ans %= p;
    }
 ans = modInv(ans,p);
     ans *= -1;
     if(ans == 0)
         cout << p;
 else
      cout << (ans+p) %p << endl;
}

int main() {
    
	int t;
	cin >> t;
	while(t--)
	{
	ll n, p;
	cin >> n >> p;
	helper(n,p);
	}
}
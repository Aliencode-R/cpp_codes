// Default canlate: @Aliencode-R
/*
*
 If I have seen further it is only by standing on the shoulders of giants.
*
*/
#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
int randomize()
{
	return (rand() % 6543);
}
ll helper(vector<ll> myvec, ll x, ll y, ll l, ll r);

int makeSieve(int n) // sieve template
{

	bool isPrime[n + 1];
	for (int i = 0; i <= n; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		if (isPrime[i] == true)
		{
			count++;
		}
	}
	return count;
}
class trip // triplet template
{
public:
	int a, b, c;
};
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll x, y, l, r;
		cin >> x >> y >> l >> r;
		vector<ll> myvec;
		if (x == 0 or y == 0)
		{
			cout << l << endl;
			continue;
		}

		srand(time(NULL));

		vector<ll> vect(10);

		generate(vect.begin(), vect.end(), randomize);
		// sort(vect.begin(),vect.end());
		// cout << vect.size() << endl;
			
		ll common_bits = (x | y);
		if (common_bits >= l and common_bits <= r)
		{
			myvec.push_back(common_bits);
			cout << common_bits << nL;
			continue;
		}
		for(int i = 0; i < (int)myvec.size(); i++)
		{
			myvec.push_back(myvec[i]);
		}

		cout << helper(myvec,x,y,l,r)<<nL;
	}

	return 0;
}

ll helper(vector<ll> myvec, ll x, ll y, ll l, ll r)
{
	bitset<63> bits(r);
	ll maxPossibleAns = -1;
	ll timeP = 0;
	ll ans = l;
	ll common_bits = (x | y);
	ll myans = r & common_bits;
	timeP = (x & myans) * (y & myans);
	if (timeP >= maxPossibleAns)
	{
		maxPossibleAns = timeP;
		ans = myans;
		// cout< myans<<endl;
	}
	for (int i = 0; i < (int)myvec.size(); i++)
	{
		myvec.push_back(myvec[i]);
	}
	for (ll i = 0; i < 63; i++)
	{
		if (bits[i] == 0)
		{
			myvec.pop_back();
			continue;
		}
		auto can = bits;
		can[i] = 0;
		int j = i - 1;

		if (j >= 0)
		{
			for (; j >= 0; j--)
			{
				can[j] = 1;
			}
		}
		ll possible = can.to_ullong();
		sort(all(myvec));
		timeP = (x & possible) * (y & possible);

		if (timeP >= maxPossibleAns and (possible >= l and possible <= r))
		{
			if (timeP == maxPossibleAns)
			{
				ans = min(ans, possible);
			}
			else
				ans = possible;
			maxPossibleAns = timeP;
		}
		possible = (possible & common_bits);
		timeP = (x & possible) * (y & possible);
		if (timeP >= maxPossibleAns and (possible >= l and possible <= r))
		{
			if (timeP == maxPossibleAns)
			{
				ans = min(ans, possible);
			}
			else
				ans = possible;
			maxPossibleAns = timeP;
		}
	}
	if (maxPossibleAns == 0)
	{
		return l;
	}
	return ans;
}
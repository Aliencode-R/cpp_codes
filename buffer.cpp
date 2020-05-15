#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define ll long long
#define vec vector<ll>
#define mat vector<vec>
#define pll pair<ll, ll>
#define imin INT_MIN
#define imax INT_MAX
#define endl "\n"
#define umap unordered_map
#define uset unordered_set
#define mp make_pair
#define pb push_back
#define inf 1e9
#define MOD 1000000007 // 10^9 + 7

void getZarr(string str, ll Z[]);

ll search(string text, string pattern)
{
	string concat = pattern + "$" + text;
	ll l = concat.length();
	ll Z[l];
	getZarr(concat, Z);

	
	ll count = 0;
	for (ll i = 0; i < l; ++i)
	{
		if (Z[i] == pattern.length())
		{
			count++;
		}
	}
	// if(count >0){
	    cout<<count<<" "<<concat<<endl;
	// }
	return count;
}

void getZarr(string str, ll Z[])
{
	ll n = str.length();
	ll L, R, k;

	L = R = 0;
	for (ll i = 1; i < n; ++i)
	{

		if (i > R)
		{
			L = R = i;

			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		}
		else
		{
			k = i - L;

			if (Z[k] < R - i + 1)
				Z[i] = Z[k];

			else
			{

				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}

vector<string> getPermutations(string a, string b)
{
	vector<string> ans;
	// ans.reserve(a.size() * b.size());

	for (ll i = 0; i <= a.size(); i++)
	{
		for (ll j = 0; j < b.size(); j++)
		{
			string temp = a.substr(0, i) + b.substr(j);
			ans.pb(temp);
		}
	}
	return ans;
}
ll getSol(vector<string> permu, vector<pair<string, ll>> bounty)
{
	ll ans = INT_MIN;
	// string temp = "";
	for (auto i : permu)
	{
		ll count = 0;
		for (auto j : bounty)
		{
			// if (i.length() < j.first.length())
			// {
			// 	continue;
			// }
			count += (search(i, j.first) * j.second);
		}
		if (ans < count)
		{
			// temp = i;
			ans = count;
		}
	}
	//cout<<temp<<endl;
	return ans;
}

int main()
{

	ll t;
	cin >> t;
	while (t--)
	{
		string a;
		string b;
		cin >> a >> b;
		ll n;
		cin >> n;
		vector<pair<string, ll>> bounty;
		for(ll i = 0; i< n; i++)
		{
			string temp;
			ll b;
			cin >> temp;
			cin >> b;
			bounty.pb({temp, b});
		}
		// cout<<a<<endl<<b;
		// cout<<endl<<bounty.size()<<endl;
		// for(auto i : bounty){
		//     cout<<i.first<<" "<<i.second<<endl;
		// }
		vector<string> permu = getPermutations(a, b);
		// for(auto i : permu){
		//     cout<<i<<endl;
		// }
		ll ans = getSol(permu, bounty);
		cout << ans << endl;
		// for(auto i : bounty){
		//     search("odechef",i.first);
		// }
	}

	return 0;
}
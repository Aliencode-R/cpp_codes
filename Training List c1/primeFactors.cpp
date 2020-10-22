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
void printFactors(int n)
{
    vector<pair<int, int>> factors;

    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            factors.push_back(make_pair(i, count));
        }
    }
    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }
    vector<int> v;
    for (auto p : factors)
    {
        // cout << p.first << " " << p.second << endl;
        for(int i = 0; i< p.second; i++) {
            // cout << p.first  << " " ;
            v.push_back(p.first);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if( i < v.size() - 1) cout << " x ";
    }
    cout << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n ) {
        if(n == 0) break;
        cout << n << " = ";
        if(n < 0) {
            cout << -1 << " x ";
            n = -1 * n;
        }
        printFactors(n);
    }
    return 0;
}
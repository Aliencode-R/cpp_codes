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

bool compare(pair<ll,ll> a, pair<ll,ll> b) {
    return a.second < b.second;
}
 
int main() {
    ll t; cin>> t;
    while(t--) {
        ll n; cin>>n;
        vector<pair<ll,ll>> v;
        for(int i = 0; i < n; i++) {
            ll a, b; cin >> a >> b;
            v.push_back(make_pair(a,b));
        }
        // vector<ll>
        sort(v.begin(), v.end(), compare);
        int count = 1;
        int last = v[0].second;
        for(int i = 1; i < n; i++) {
            // pair<ll, ll> a = v[i];
            // pair<ll, ll> b = v[i+1];
            if(v[i].first >= last) {
                last = v[i].second;
                count ++;
            }
        }
        cout << count << endl;
    }
    return 0;
}










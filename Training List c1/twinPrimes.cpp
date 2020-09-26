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

const int n = 100000000;

vector<int> primes;

void prime() {
    vector<int> mark(n, 1);
    for(int i = 3; i*i <= n; i += 2) {
        if(mark[i]) {
            for(int j = i * i; j <= n; j += i) {
                mark[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= n; i+=2) {
        if(mark[i]) primes.push_back(i);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime();
    vector<pii> ans;
    for(int i = 1; i < primes.size(); i++) {
        if(primes[i] - primes[i-1] == 2) ans.push_back({primes[i-1], primes[i]});
    }
    int i; 
    while(cin >> i) {
        cout << "(" << ans[i-1].first << ", " << ans[i-1].second << ")" << endl;
    }
    return 0;
}
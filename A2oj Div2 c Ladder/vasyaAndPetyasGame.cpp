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

bool isPrime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0 ) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 
    vector<int> v;
    for(int i = 2; i <= n; i++) {
        if(isPrime(i) == false) continue;
        int j = i;
        while(j <= n) {
            v.push_back(j);
            j *= i;
        }
    }
    cout << v.size() << endl;
    for(int x : v) cout << x << " ";
    return 0;
}
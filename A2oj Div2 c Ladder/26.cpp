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
#define N 10000010
int cnt[N] = {0};
bool primes[N];
int F[N] = {0};

void seive() {
    memset(primes, true, sizeof(primes));

    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= N; i++) {
        if(primes[i] == true) {
            for(int j = i*i; j <= N; j+=i) {
                primes[j] = false;
            }
        }
    }
}

void compute() {
    for(int i = 2; i <= N; i++) {
        if(primes[i]) {
            for(int j = i ; j <= N; j+=i) {
                F[i]+= cnt[j];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        F[i] += F[i-1];
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]] ++;
    }
  
    compute();
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        if(l > 10000000ll) 
            cout << 0 << endl;
        else 
            cout << F[min(r, 10000000ll)] - F[l-1] << endl;
    }
    
    return 0;
}
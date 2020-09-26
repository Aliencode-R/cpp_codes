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
const int N = 10000001;
vector<int> primes(N, 1);
void prime() {
    for (int i = 2; i * i <= N; i ++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    // for(int i = 2; i < 100; i ++) {
    //     if(primes[i] ) cout << i << " ";
    // }
}

pii helper(int n) {
    for(int i = 2; i <= n/2; i++) {
        if(primes[i] and primes[n-i]) {
            return {i, n-i};
        }
    }
    return {1,2};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime();

    int n; 

    while(cin >> n) {
        if(n <= 7) {
            cout << "Impossible." << endl;
            continue;
        }

        if(n % 2 == 0) {
            pii p = helper(n - 4);
            cout << "2 2 " << p.first << " " << p.second << endl;
        } else {
            pii p = helper(n - 5);
            cout << "2 3 " << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
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

bool isBin(int n) {
    while (n != 0)
    {
        if(n % 10 == 0 or n % 10 == 1) {
            n /= 10;
        }
        else {
            return false;
        }
    }
    return true;    
}
int bin(int n) {
    int ans = 0;
    int j = 1;
    while(n != 0) {
        if(n % 10 == 1) {
            ans += j;
        }
        j = (j << 1);
    }
    return ans;
}

int decimal(int n) {
    int ans = 0;
    int j = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            ans += j;
        }
        j *= 10;
        n /= 2;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    for(int i = 1; i <= pow(2,10); i++) {
        if(decimal(i) > n) {
            cout << i - 1;
            return 0;
        }
    }
    return 0;
}
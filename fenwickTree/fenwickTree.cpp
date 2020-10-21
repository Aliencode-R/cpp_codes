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

int arr[10000];
int bit[10000] = {0};

void update(int i, int increment, int n) {
    while(i <= n) {
        bit[i] += increment;
        i += (i & (-i));
    }
    return;
}

int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], n);
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << query(r) - query(l-1) << endl;
    }


    return 0;
}
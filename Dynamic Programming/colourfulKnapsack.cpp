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
struct item {
    int wt; 
    int col;
};
bool compare(item a, item b) {
    return a.col < b.col and a.wt < b.wt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x; cin >> n >> m >> x;
    vector<int> arr[m]; 
    item items[n];
    for(int i = 0; i < n; i++){
        cin >> items[i].wt;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].col;
    }
    sort(items, items+n, compare);
    int index = 0; 
    while(index < n) {
        // not able to do
    }

    return 0;
}
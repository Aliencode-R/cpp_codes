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

int query(int *blocks, int *arr, int l, int r, int rn) {
    int ans = 0;
    // left part 
    while(l < r and l%rn != 0) {
        ans += arr[l];
        l++;
    }
    // middle part
    while(l + rn <= r) {
        int blockId = l / rn;
        ans += blocks[blockId];
        l += rn;
    }
    // right part
    while(l <= r) {
        ans += arr[l];
        l++;
    }

    return ans;
}

void update(int *blocks, int *arr, int i, int val, int rn) {
    int blockId = i / rn;
    blocks[blockId] += (val - arr[i]);
    arr[i] = val;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // build the blocks array
    int rn = sqrt(n); // root n
    int blocks[rn+1] = {0};
    int blockId = -1;
    for(int i = 0; i <n; i++) {
        if(i % rn == 0)  {
            blockId++;
        }
        blocks[blockId] += arr[i];
    }
    update(blocks, arr, 3, 100, rn);
    int l, r; cin >> l >> r;
    cout << query(blocks, arr, l, r, rn);

    return 0;
}
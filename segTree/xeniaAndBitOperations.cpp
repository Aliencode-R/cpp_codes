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
int *arr = new int[1000000];
int *seg = new int[2000000];

void build(int index, int s, int e) {
    if(s == e) {
        seg[index] = arr[s];
        return ;
    }
    int mid = (s + e) / 2;

    build(2*index, s, mid);
    build(2*index+1, mid+1, e);

    int times = log2(e - s + 1);

    if(times & 1) {
        seg[index] = seg[2*index] | seg[2*index+1];
    } else {
        seg[index] = seg[2*index] ^ seg[2*index+1];
    }
}

void update(int index, int i, int s, int e, int val) {
    if(i < s or i > e) {
        return;
    }
    if(s == e) {
        seg[index] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(2*index, i, s, mid, val);
    update(2*index+1, i, mid+1, e, val);

    int times = log2(e - s + 1);

    if (times & 1)
    {
        seg[index] = seg[2 * index] | seg[2 * index + 1];
    }
    else
    {
        seg[index] = seg[2 * index] ^ seg[2 * index + 1];
    }
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    n = pow(2, n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1);

    while(m--) {
        int id, val; cin >> id >> val;
        id--;
        update(1, id, 0, n-1, val);

        cout << seg[1] << endl ;
    }

    return 0;
}
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

struct node {
    int prefix, suffix, total, best;
};

void buildTree(node *tree, int *arr, int s, int e, int index) {
    if(s == e) {
        tree[index].prefix = arr[s];
        tree[index].suffix = arr[s];
        tree[index].total = arr[s];
        tree[index].best = arr[s];
        return ;
    }
    int mid = (s + e) / 2;
    buildTree(tree, arr, s, mid, 2 * index);
    buildTree(tree, arr, mid+1, e, 2 * index+1);

    node left = tree[2 * index];
    node right = tree[2 * index + 1];

    tree[index].prefix = max(left.prefix, left.total + right.prefix);
    tree[index].suffix = max(right.suffix, left.suffix + right.total);
    tree[index].total = left.total + right.total;
    tree[index].best = max({left.suffix + right.prefix, left.best, right.best});

    return;
}

node query(node *tree, int* arr, int s, int e, int qs, int qe, int index) {
    if(qs <= s and qe >= e) {
        return tree[index];
    }
    node ret;
    if(s > qe or e < qs) {
        ret.prefix = ret.suffix = ret.total = ret.best = imin;
        return ret;
    }
    int mid = (s + e) / 2;
    node left = query(tree, arr, s, mid, qs, qe, 2 * index);
    node right = query(tree, arr, mid+1, e, qs, qe, 2 * index+1);

    ret.prefix = max(left.prefix, left.total + right.prefix);
    ret.suffix = max(right.suffix, left.suffix + right.total);
    ret.total = left.total + right.total;
    ret.best = max({left.suffix + right.prefix, left.best, right.best});

    return ret;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    node *tree = new node[4 * n + 1];
    buildTree(tree, arr, 1, n, 1);

    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        node ans = query(tree, arr, 1, n, l, r, 1);
        cout << ans.best << endl;
    }

    return 0;
}
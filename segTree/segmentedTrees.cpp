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

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    // before going down relove the lazy value if it exists
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        // check if non leaf node
        if(ss != se) {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        // clear the current lazziness
        lazy[index] = 0;
    }
    if(ss > r or se < l) {
        return ;
    }

    // complete overlap
    if(ss >= l and se <= r) {
        tree[index] += inc;

        // create a new lazy value of children node
        if(ss != se) {
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return ;
    }
    // recursive case
    int mid = (ss + se) / 2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
    updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2*index], tree[2*index+1]);

    return;
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {
    // before going down relove the lazy value if it exists
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        // check if non leaf node
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        // clear the current lazziness
        lazy[index] = 0;
    }

    // no overlap
    if(ss > qe or se < qs) {
        return imax;
    }

    // complete overlap
    if(ss >= qs and se <= qe) {
        return tree[index];
    }

    // partial overlap
    int mid = (ss + se) / 2;
    int left = queryLazy(tree, ss, mid, qs, qe, 2*index);
    int right = queryLazy(tree, mid+1, se, qs, qe, 2*index+1);

    return min(left, right);
}


void buildTree(int *a, int s, int e, int *tree, int index) {
    if(s == e) {
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;

    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid+1, e, tree, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index) {
    if(qs <= ss and se <= qe) {
        return tree[index];
    }
    if(qe < ss or qs > se) {
        return imax;
    }
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}

void update(int *tree, int ss, int se, int i, int increment, int index) {
    if(i > se or i < ss) {
        return ;
    }
    // leaf 
    if(ss == se) {
        tree[index] += increment;
        return;
    }

    int mid = (ss + se) / 2;
    update(tree, ss, mid, i, increment, 2 * index);
    update(tree, mid + 1, se, i, increment, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

    return;
}

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) // not very efficient
{
    //Out of bounds
    if (l > se || r < ss)
    {
        return;
    }

    // Leaf Node
    if (ss == se)
    {
        tree[index] += inc;
        return;
    }

    // Left and Right  Call Otherwise
    int mid = (ss + se) / 2;

    updateRange(tree, ss, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {1, 3, 2, -5, 6, 4};
    int n = 6;

    int tree[4 * n + 1];
    buildTree(a, 0, n-1, tree, 1);
    for(auto t : tree) cout << t << " ";

    return 0;
}
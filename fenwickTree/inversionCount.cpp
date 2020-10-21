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

int *arr = new int[200009];
// int *bit = new int/[200009];
int bit[200009] = {0};
void update(int i, int increment, int n)
{
    while (i <= n)
    {
        bit[i] += increment;
        i += (i & (-i));
    }
    return;
}
void updateBIT(int n, int index, int val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        bit[index] += val;

        // Update index to that of parent in update View
        index += index & (-index);
    }
}

int getSum(int index)
{
    int sum = 0; // Initialize result

    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += bit[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int t; cin >> t; 
while(t--) {
    memset(bit, 0, sizeof bit);
    int n;
    cin >> n;
    int mx = imin;

    set<int> s; 
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        // mx = max(mx, arr[i]);
    }

    // cordinate compression
    umap<int,int> imap;
    int ind = 1;
    for(auto x : s) {
        imap[x] = ind++;
    }

    for(int i = 1; i <= n; i++) {
        arr[i] = imap[arr[i]];
    }
    // done cordinate compression

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += query(arr[i] - 1) ;
        update(arr[i], 1, n);
    }
    cout << ans  << endl;
}
    return 0;
}
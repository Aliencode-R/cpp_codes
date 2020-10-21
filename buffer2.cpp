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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void multiply(int A[2][2], int M[2][2])
{

    int firstValue = (A[0][0] * M[0][0]) %mod+ (A[0][1] * M[1][0]) % mod;
    int secondValue = (A[0][0] * M[0][1]) % mod + (A[0][1] * M[1][1]) % mod;
    int thirdValue = (A[1][0] * M[0][0]) % mod + (A[1][1] * M[1][0]) % mod;
    int fourthValue = (A[1][0] * M[0][1]) % mod + (A[1][1] * M[1][1]) % mod;

    A[0][0] = firstValue % mod;
    A[0][1] = secondValue % mod;
    A[1][0] = thirdValue % mod;
    A[1][1] = fourthValue % mod;
}
void power(int A[2][2], int n)
{
    if (n == 1)
    {
        return;
    }
    power(A, n / 2);
    multiply(A, A);
    if (n % 2 != 0)
    {
        int F[2][2] = {{1, 1}, {1, 0}};
        multiply(A, F);
    }
}
int getFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int A[2][2] = {{1, 1}, {1, 0}};
    power(A, n - 1);
    return A[0][0] % mod;
}

void buildTree(int *a, int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;

    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = gcd(tree[2 * index], tree[2 * index + 1]) % mod;

    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss and se <= qe)
    {
        return tree[index] % mod;
    }
    if (qe < ss or qs > se)
    {
        return -1;
    }
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

    if(left == -1 and right == -1) {
        return -1;
    }
    if(left == -1) return right % mod;
    if(right == -1) return left % mod;

    return gcd(left, right) % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int *tree = new int[4*n+1];
    buildTree(arr, 0, n-1, tree, 1);
    while(q--) {
        int l, r; cin >> l >> r;
        cout << getFibonacci( query(tree, 0, n-1, l-1, r-1, 1) % mod ) % mod<< endl;
    }
    // for(int i = 0; i <= 4*n; i++) {
    //     cout << i << ": " << tree[i] << endl;
    // }

    return 0;
}
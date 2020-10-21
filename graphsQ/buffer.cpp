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
int r; 

struct matrix {
	int a, b, c, d;
	matrix(int a1, int b1, int c1, int d1) {
		a = a1;
		b = b1; 
		c = c1; 
		d = d1;
	}
	matrix() {};
};
matrix multiply(matrix &A, matrix &B) {
	matrix ret;
		ret.a = ((A.a % r * B.a % r ) % r + (A.b % r * B.c % r ) % r) % r;
		ret.b = ((A.a % r * B.b % r ) % r + (A.b % r * B.d % r ) % r) % r;
		ret.c = ((A.c % r * B.a % r ) % r + (A.d % r * B.c % r ) % r) % r;
		ret.d = ((A.c % r * B.b % r ) % r + (A.d % r * B.d % r ) % r) % r;
	return ret;
}


void build(matrix *tree, matrix *arr, int s, int e, int index) {
	if(s > e) return;
	if(s == e) {
		tree[index] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(tree, arr, s, mid, 2*index);
	build(tree, arr, mid+1, e, 2*index+1);
	
	tree[index] = multiply(tree[2*index], tree[2*index+1]);
	return;
}

matrix query(matrix *tree, matrix *arr, int s, int e, int qs, int qe, int index) {

	if(s > e or s > qe or e < qs ) {
		matrix ret;
		ret.a = ret.d = 1;
		ret.b = ret.c = 0;	
		return ret;	
	}
	if(qs <= s and qe >= e) {
		return tree[index];
	}

	int mid = (s+e) / 2;
	matrix left = query(tree, arr, s, mid, qs, qe, 2*index);
	matrix right = query(tree, arr, mid+1, e, qs, qe, 2*index+1);

	return multiply(left, right);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// cout << "hellp";
	// r = 3;
	// matrix t(2,1,1,2);
	// matrix y(2,1,1,2);
	
	// matrix z = multiply(t, y);
	// cout << z.a << " " << z.b << " " << z.c << " " << z.d << endl;

	int n, q;
	cin >> r >> n >> q;
	matrix *arr = new matrix[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
	}
	// matrix tree[4*n+1];
	matrix *tree = new matrix[4*n+1];
	// cout << endl;
	build(tree, arr, 0, n-1, 1);
	// for(int i = 0; i <= 4*n; i++) {
	// 	cout << i << ": " ;
	// 	cout << tree[i].a << " " << tree[i].b << " " << tree[i].c << " "<< tree[i].d << endl;
	// }
	for(int i = 0; i < q; i++) {
		int l, rr; cin >> l >> rr;
		
		matrix ans = query(tree, arr, 0, n-1, l-1, rr-1, 1);
		cout << ans.a << " " << ans.b << endl << ans.c << " " << ans.d << endl;
		cout << endl;
	}
    return 0;
}
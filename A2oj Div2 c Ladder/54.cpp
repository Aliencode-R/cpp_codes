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

bool helper(int x, int y, int p, int q, int a, int b) {
    if(abs(x-p)*abs(x-p) + abs(y-q)*abs(y-q) == a*a + b*b) {
        return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    int x1 = -1, y1 = -1;
    for(int i = -1000; i < 1001; i++) {
        for(int j = -1000; j < 1001; j++) {
            if (i * i + j * j == a * a)
            {
                x1 = i;
                y1 = j;
                break;
            }
            if(i*i + j*j == b*b) {
                swap(a,b);
                x1 = i;
                y1 = j;
                break;
            }
        }
    }
    // cout << x1;
    if(x1 == -1) {
        cout << "NO" ;
        return 0;
    }
    for(int i = -1000; i <= 1000; i++) {
        for(int j = -1000; j <= 1000; j++) {
            
            // if(i == -4 and j == 3) {
            //     cout << m1 << " " << m2 << " " << (m1*m2 == (double)1.00)<< endl;
            // }
            if(abs(j*y1) == abs(x1*i) and helper(i, j, x1, y1, a, b)){ 
                cout << "YES" << endl;
                cout << 0 << " " << 0 << endl;
                cout << i << " " << j << endl;
                cout << x1 << " " << y1 << endl;
                return 0;
            }
        }
    }
    cout << "NO";
    // cout << helper(-4,3,3,4,a,b) << " " ;
    // cout << "hello";
    return 0;
}
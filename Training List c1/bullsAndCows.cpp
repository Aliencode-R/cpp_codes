#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

void setarr(int *arr) {
    for(int i = 0; i < 10000; i++) {
        int temp = i;
        int a = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int c = temp % 10;
        temp /= 10;
        int d = temp % 10;
        
        if(a != b and b != c and c != d and d != a and a != c and b != d) {
            arr[i] = 1;
            // cout << i << endl;
        } else {
            arr[i] = 0;
        }
    }
    return;
}

void helper(int *arr, int b, int c, int num) {
    umap<int,int> m;
    int x = num;
    m[4] = num % 10;
    num /= 10;
    m[3] = num % 10;
    num /= 10;
    m[2] = num % 10;
    num /= 10;
    m[1] = num % 10;
    num /= 10;

    for(int i = 0; i < 10000; i++) {
        if(arr[i] == 0) continue;
        int temp = i;
        umap<int,int> p;
        p[4] = temp % 10;
        temp /= 10;
        p[3] = temp % 10;
        temp /= 10;
        p[2] = temp % 10;
        temp /= 10;
        p[1] = temp % 10;
        temp /= 10;
        int bulls = 0, cows = 0;
        // bulls 
        for(int ii = 1; ii <= 4; ii++) {
            if(m[ii] == p[ii]) bulls++;
        }
        for(int ii = 1; ii <= 4; ii++) {
            for(int jj = 1; jj <= 4; jj++) {
                if(ii != jj and m[ii] == p[jj]) cows++;
            }
        }
        // if(i == 2134) cout << "bulls " << bulls << "  " << cows << endl;
        if(bulls == b and cows == c) {
            arr[i] = 1;
            // if(i == 2134) cout << "here " << arr[i] << " num " << x << endl;
        }
        else arr[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10000];
    setarr(arr);
    int n; cin >> n; 
    while(n--) {
        int num, b, c;
        cin >> num >> b >> c;
        helper(arr, b, c, num);
    }   
    vi v; 
    for(int i = 0; i <10000; i++) {
        if(arr[i] == 1) {
            v.push_back(i);
        }
    }
    if(v.size() == 1) {
        if(v[0] < 1000) cout << 0;
        cout << v[0];
    } else if(v.size() > 1) {
        cout << "Need more data";
    } else {
        cout << "Incorrect data";
    }
    // for(int x : v) cout << x << ",";
    // cout << endl;
    // cout << arr[2134] << endl;
    return 0;
}
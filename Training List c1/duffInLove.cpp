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

bool check(int n) {
    int a = sqrt(n);
    return a * a == n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    // bool *arr = new bool(1000001);
    bool arr[1000001];
    memset(arr, false, sizeof arr);
    for(int i = 1; i*i <= 1000000; i++) {
        arr[i*i] = true;
    }

    vector<int> v;
    for(int i = 1; i*i <= n; i++) {

        if(n % i == 0) {
            v.push_back(i);
            v.push_back(n/i);
        }
       
    }
    // cout << (arr[4] == true and 12 % 4 == 0);
    sort(v.rbegin(), v.rend());
    int ans;
    for(int x : v) {
        bool flag = true;
        for(int i = 4; i <= x and i <= 1000000; i++) {
            if(check(i) and x % i == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans = x;
            break;
        }
    }
    cout << ans;
    return 0;
}
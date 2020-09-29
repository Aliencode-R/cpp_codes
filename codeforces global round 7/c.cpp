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
#define mod 998244353
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    int arr[n]; 
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cut = n - k + 1;
    int fir = 0;
    for(int i = cut; i <= n; i++) {
        fir += i;
    }
    bool flag = false;
    
    int sum = 1;
    int count = 0;
    for(int i = 0; i < n; i++) {

        if(flag == false and arr[i] < cut) continue;
        if(flag == false and arr[i] >= cut) {
            flag = true;
            continue;
        }
        // flag = true;
        if(arr[i] < cut) {
            count++;
            continue;
        }
        if(arr[i] >= cut) {
            
            sum *= (count + 1);
            count = 0;
            sum %= mod;
        }

    }
    for(int i = n-1; i >= 0; i++) {
        if(arr[i] >= cut) break;
        
    }
    cout << fir << " " << sum % mod;
    return 0;
}
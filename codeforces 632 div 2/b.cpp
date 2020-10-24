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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>> t; 
    while(t--) {
        int n; cin >> n ;
        int arr[n] , brr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> brr[i];

        int one = n, mone = n;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 1) {
                one = min(one, i);
            }
            if(arr[i] == -1) {
                mone = min(mone, i);
            }
        }
        bool flag = true;
        for(int i = n-1; i >= 0; i--) {
            if(brr[i] > arr[i] and i > one) {
                continue;
            }
            if(brr[i] < arr[i] and i > mone) {
                continue;
            }
            if(brr[i] == arr[i]) continue;
            flag = false;
            break;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
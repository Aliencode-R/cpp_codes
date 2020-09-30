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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool prince[n+1];
        memset(prince, true, sizeof prince);
        int princess = -1;
        for(int i = 1; i <= n; i++) {
            int k; cin >> k;
            int arr[k]; 
            for(int j = 0; j < k; j++) cin >> arr[j];
            bool flag = false;
            for(int j = 0; j < k; j++) {
                // int num; cin >> num;
                int num = arr[j];
                if(prince[num] == true) {
                    prince[num] = false;
                    flag = true;
                    break;
                }
            }
            if(flag == false and princess == -1) {
                princess = i;
            }
        }
        if(princess == -1) {
            cout << "OPTIMAL" << endl;
        } else {
            int p;
            for(int i = 1; i <= n; i++) {
                if(prince[i] ) {
                    p = i;
                    break;
                }
            }
            cout << "IMPROVE" << endl;
            cout << princess << " " << p << endl;
        }
    }
    return 0;
}
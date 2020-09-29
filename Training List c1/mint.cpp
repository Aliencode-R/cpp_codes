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
    int n, t; 
    while(true) {
        cin >> n >> t;
        if(n == 0 and t == 0) break;

        int arr[n];
        int tables[t];
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < t; i++) cin >> tables[i];

        for(int i = 0; i < t; i++) {
            int table = tables[i];
            bool arr[1000000] = {};
            int mn = table;
            for(int i = 0; i < n; i++) {
                int low = arr[i] * (table / arr[i]);
                if(low == table) {
                    arr[table] = true;
                } else {
                    arr[low] = true;
                    arr[low + arr[i]] = true;
                }
            }
            int left = table;
            int right = table;
            for()
            cout << mn << endl;


        }

    }
    return 0;
}
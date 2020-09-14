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
        bool z = false;
        int n; cin >> n;
        vector<int> arr(n); 
        // int arr[n]; 
        bool pve = false;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] == 0) z = true;
            if(arr[i] > 0) pve = true;

        }
        // priority_queue<int, vector<int>, greater<int>> p;
        // priority_queue<int, vector<int>, greater<int>> ne;
        // for(int i = 0; i < n; i++) {
        //     if(p.size() < 5) {
        //         if(arr[i] >= 0) {
        //             p.push(arr[i]);
        //         }
        //     } else {
        //         if(p.top() < arr[i]) {
        //             p.push(arr[i]);
        //             p.pop();
        //         }
        //     }
        //     if(arr[i] >= 0) continue;
        //     if (ne.size() < 5)
        //     {
        //             ne.push(-1*arr[i]);   
        //     }
        //     else
        //     {
        //         if (ne.top() < abs(arr[i]))
        //         {
        //             ne.push(abs(arr[i]));
        //             ne.pop();
        //         }
        //     }
        // }
        // while(p.size() != 0 ) {
        //     arr.push_back(p.top());
        //     p.pop();
        // }
        // while(ne.size() != 0) {
        //     v.push_back(-1*ne.top());
        //     ne.pop();
        // }

        int ans = imin;
        sort(all(arr));
        int vs = arr.size();
        ans = arr[vs-1] * arr[vs-2] * arr[vs-3] * arr[0] * arr[1];
        ans = max(ans, arr[vs - 1] * arr[2] * arr[0] * arr[1] * arr[3]);
        ans = max(ans, arr[vs - 1] * arr[vs - 2] * arr[vs - 3] * arr[vs-4] * arr[vs-5]);
        // cout << ans << endl;
        if(ans < 0 and z) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
        // for(int x : arr) cout << x << " ";
    }
    return 0;
}
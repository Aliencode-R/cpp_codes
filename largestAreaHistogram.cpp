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
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int left[n];
    int right[n];

    stack<int> s; 

    s.push(n-1);
    right[n-1] = n;
    
    for(int i = n-2; i >= 0; i--) {
        while(s.size() > 0 and arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if(s.size() == 0) {
            right[i] = n;
        } else {
            right[i] = s.top();
        }
        s.push(i);
    }

    while(s.size() != 0) s.pop();

    left[0] = -1;
    s.push(0);

    for(int i = 1; i < n; i++) {
        while(s.size() != 0 and arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.size() == 0)
        {
            left[i] = -1;
        }
        else
        {
            left[i] = s.top();
        }
        s.push(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        // cout << right[i]  << " ";
        ans = max(ans, arr[i] * (right[i] - left[i] - 1));
    }
    // cout << endl;
    cout << ans;



    return 0;
}
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

int isK(int *arr, int n, int window) {
    int ret = -1;
    umap<int,int> imap;
    int pre[n+1];
    memset(pre, 0, sizeof pre);
    int count = 0;
    for(int i = 1; i <= window; i++) {
        imap[arr[i]]++;
        pre[arr[i]] = 1;
        if(imap[arr[i]] == 1) {
            count ++;
        }
    }
  
    // cout << window << endl;

    for(int i = 2; i <= n - window + 1; i++) {
        imap[arr[i-1]]--;
        imap[arr[i+window - 1]] ++;
        if(imap[arr[i-1]] == 0) {
            pre[arr[i-1]] = 0;
            count --;
            // if(count == 0) {
            //     return -1;
            // }
        }
    }

    // for (int i = 1; i <= n; i++)
    //     cout << pre[i] << " ";
    // cout << endl;

    for(int i = 1; i <= n; i++) {
        if(pre[i] == 1) {
            ret = i;
            break;
        }
    }
    return ret;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        int arr[n+1];
        for(int i = 1; i <= n; i++) cin >> arr[i];

        int low = 1; int high = n; 
        int index = n; 
        int val = -1;
        while(low <= high) {
            int mid = (high + low) / 2;
            // cout << mid << " ";
            int temp = isK(arr, n, mid);
            if(temp != -1) {
                high = mid - 1;
                index = mid;
                val = temp;
            } else {
                low = mid + 1;
            }
        }
        // cout << isK(arr, n, 1);
        for(int i = 1; i <= n; i++) {
            if(i < index)
                cout << -1 << " ";
            else 
                cout << isK(arr, n, i) << " ";
        }
        cout << endl;
    }
    return 0;
}
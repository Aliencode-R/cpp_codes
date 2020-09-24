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

int maxSubArraySum(vector<int> a, int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >>  q;
        int arr[n]; 
        for(int i = 0; i < n; i++) cin >> arr[i];

        // int big = arr[0];
        // int small = arr[0];
        int ans = 0;
        vector<int> v;
        int index = 0;
        int last = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > last) {
                index = i;
            }
            else {
                break;
            }
            last = arr[i];
        }
        // cout << index << endl;
        v.push_back(arr[index]);
        int toggle = 0;
        int small = arr[index];
        int big = arr[index];
        for(int i = index+1; i < n; i++) {
            if(toggle == 0) {
                if(arr[i] < small) {
                    small = arr[i];
                }
                else {
                    toggle = 1;
                    v.push_back(-1 * small);
                    big = arr[i];
                }
            } else {
                if(arr[i] > big) {
                    big = arr[i];
                } else {
                    toggle = 0;
                    v.push_back(big);
                    small = arr[i];
                }
            }
        }
        if(arr[n-1] != v[v.size()-1]) {
            if (arr[n - 1] > v[v.size() - 1]) {
                v.push_back(arr[n - 1]);
            } else {
                v.push_back(-1 * arr[n - 1]);
            }
        }
            // v.push_back(arr[n-1]);
            cout << maxSubArraySum(v, v.size());
        // for(int i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
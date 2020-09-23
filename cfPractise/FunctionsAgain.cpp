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

int kadane(vector<int> &a) {
    int size = a.size();
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
    int n; cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> v;
    vector<int> v2;

    for(int i = 1; i < n; i++) {
        if(i % 2 == 1) {
            v.push_back(abs(arr[i] - arr[i-1]));
            v2.push_back(-1 * abs(arr[i] - arr[i - 1]));
        }
            
        else 
        {
            v2.push_back(abs(arr[i] - arr[i - 1]));

            v.push_back(-1 * abs(arr[i] - arr[i - 1]));
        }
    }
    // for(int x : v ) cout << x << " ";

    cout << max(kadane(v2), kadane(v));
    return 0;
}
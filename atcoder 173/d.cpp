#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
// #define a first
// #define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
  
    int arr[n];
    for(int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    if (n == 2)
    {
        cout << max(arr[0],arr[1]);
        return 0;
    }
    sort(arr, arr+n);
    int start = n/2+1 ;
    ll ans = arr[n/2] + arr[n-1];
    for(int i = start; i < n-1; i++) {
        ans += 2*arr[i];
    }
    if(n == 4) {
        ans += arr[n-2];
    }
    cout << ans;
    // if(n% 2 == 0) {

    // }

    return 0;
}

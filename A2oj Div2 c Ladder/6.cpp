#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    int arr[3] = {a, b, c};
    sort(arr, arr+3);
    if(arr[0]+arr[1] <= arr[2]/2) cout << arr[0] + arr[1];
    else cout << (arr[0]+arr[1]+arr[2])/3;
    return 0;
}

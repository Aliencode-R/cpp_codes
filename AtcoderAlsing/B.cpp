#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
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

int main()
{
    int n; cin >> n;
    int arr[n+1];
    int ans = 0;
    for(int i = 1; i <= n;i++) {
        cin >> arr[i];
        if(i % 2 == 1 and arr[i] % 2 == 1) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
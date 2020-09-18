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
    int buy = -1 * arr[0]; 
    int sell = 0; 
    int coolSell = 0;

    for(int i = 1; i < n; i++) {
        int newBuy = imin; 
        int newSell = imin;
        int newCoolSell = imin;

        newBuy = max(buy, coolSell - arr[i]);

        newSell = max(sell, buy + arr[i]);

        newCoolSell = max(coolSell, sell);

        buy = newBuy;
        sell = newSell;
        coolSell = newCoolSell;
    }

    cout << sell; 

    return 0;
}
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
    int fee; cin >> fee;

    int buyStateProfit = -1 * arr[0];
    int sellStateProfit = 0;

    for(int i = 1; i < n; i++) {
        int newBuyStateProfit = 0;
        int newSellStateProfit = 0;

        if(sellStateProfit - arr[i] > buyStateProfit) {
            newBuyStateProfit = sellStateProfit - arr[i];
        } else {
            newBuyStateProfit = buyStateProfit;
        }

        if(arr[i] + buyStateProfit - fee > sellStateProfit) {
            newSellStateProfit = arr[i] + buyStateProfit - fee;
        } else {
            newSellStateProfit = sellStateProfit;
        }

        sellStateProfit = newSellStateProfit;
        buyStateProfit = newBuyStateProfit;
    }
    cout << sellStateProfit;


    return 0;
}
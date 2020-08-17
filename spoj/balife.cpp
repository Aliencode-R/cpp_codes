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

int main() {
    ll n;
    // cin >> n;
    while(true) {
        cin >> n;
        if (n == -1)
            break;
        // cin >> n; 
        int arr[n];
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if(sum % n != 0) {
            cout << -1 << endl;
            continue;
        }

        ll single = sum / n;
        ll ans = INT_MIN;
        ll sum_till_now = 0;
        for(int i = 0; i < n; i++) {
            ll honaChie = i * single;
            ans = max(ans, abs(honaChie - sum_till_now));

            sum_till_now += arr[i];
        }

        cout << ans << endl;



    }
    return 0;
}
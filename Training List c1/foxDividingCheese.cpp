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
    int a, b; cin >> a >> b;
     if(a == b) {
        cout << 0;
    } else {
        int arr[6] = {};
        int brr[6] = {};
        for (int i = 2; i <= 5; i++)
        {
            // if(a == b) break;
            if (a % i == 0)
            {
                int count = 0;
                while (a % i == 0)
                {
                    a = a / i;
                    count++;
                }    
                // cout << i << " " << count << ", ";       
                arr[i] = count;     
            }
        }
        // cout << endl;
        for (int i = 2; i <= 5; i++)
        {
            
            if (b % i == 0)
            {
                int count = 0;
                while (b % i == 0)
                {
                    b = b / i;
                    count ++;
                }
                // cout << i << " " << count << ", ";
                brr[i] = count;
            }
        }
        // cout << endl;
        // cout << a << " " << b << endl;
        // cout << arr[0] << arr[1] << arr[2];
        // cout << endl;
        // cout << brr[0] << brr[1] << brr[2];
        // cout << endl;

        if(a == b) {
            int ans = 0;
            ans += abs(arr[2] - brr[2]);
            ans += abs(arr[3] - brr[3]);
            ans += abs(arr[5] - brr[5]);
            cout << ans;
        } else {
            cout << -1;
        }
    }
    return 0;
}
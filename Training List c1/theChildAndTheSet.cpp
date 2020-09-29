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

unsigned int getFirstSetBitPos(int n)
{
    return n & -n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum, n; 
    cin >> sum >> n;
    int temp = 0;

    vector<int> v;
    int N = n % 2 == 0 ? n : n-1;
    for(int i = N; i >= 0; i-=2) {

        int x = getFirstSetBitPos(i);
        if ((n % 2 == 0 and sum <= n/2 ) or (n % 2 == 1 and sum <= n/2 + 1))
        {
            // cout << "break" << endl;
            break;
        }
        if(sum - x >= 0) {
            sum -= x;
            v.push_back(i);
        }
    }
    // cout << sum << endl;
    for(int i = 1; i <= n; i+= 2) {
        if(sum == 0) break;
        sum --;
        v.push_back(i);
    }
    // cout << sum << endl;
    if(sum != 0) {
        cout << -1;
        return 0;
    }

    cout << v.size() << " " ;
    for(int x : v) cout << x << " ";


    return 0;
}
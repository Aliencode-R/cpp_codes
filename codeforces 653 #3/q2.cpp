#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
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
    int t; cin >> t;
    while(t--) { 
        ll n; cin >> n;
        ll count = 0;
        while(n != 1) {
            if(n%6==0) {
                n = n/6;
                count ++;
            } else if(n % 3 == 0) {
                count += 2;
                n = n/3;
            } else {
                break;
            }
        }
        cout << "ans";
        if (n == 1) {
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

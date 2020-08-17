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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool even = false, odd = false;
        if(arr[0] % 2 ==0 ) {
            even = true;
        }
        else {
            odd = true;
        }
        bool isNO = false;
        for(int i = 1; i < n; i++) {
            if(odd and arr[i] % 2 == 0) {
                cout << "NO" << endl;
                isNO = true;
                break;
            }
            else if(even and arr[i] % 2 == 1) {
                cout << "NO" << endl;
                isNO = true;
                break;
            }
        }
        if(!isNO)
            cout << "YES" << endl;
    }


    return 0;
}

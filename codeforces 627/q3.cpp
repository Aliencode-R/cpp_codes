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
    int t ;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size() , i = 0;
        int ans = 0;
        while(i < n){
            if(s[i] == 'R') {
                i++;
                continue;
            }
            else {
                int j = i;
                while(j < n and s[j] == 'L') {
                    j ++;
                }
                ans = max(ans , j - i);
                i = j;
            }
        }
        cout << ans+1 << endl;
    }

    return 0;
}

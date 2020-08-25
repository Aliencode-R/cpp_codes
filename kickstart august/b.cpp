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



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        int n; cin >> n;
        // TODO: n = 1; a b < c
        int a, b, c; cin >> a >> b >> c;

        vector<int> ans;
        for(int i = 0; i < abs(c-a); i++) {
            ans.push_back(n-1);
        }
        for(int i = 0; i < c; i++) {
            ans.push_back(n);
        }
        // if(n != 1 and n != 2)
        // ans.push_back(1);
        int temp = 1;
        while(ans.size() + abs(c-b) < n and temp <= n-1) {
            ans.push_back(temp);
            temp++;
        }
        for (int i = 0; i < abs(c - b); i++)
        {
            ans.push_back(n - 1);
        }
        if(c > a or c > b or ans.size() != n or (a == 1 and b == 1 and c == 1 and n != 1))
        cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        else if(n == 1) {
            if (a != 1 or b != 1 or c != 1)
                cout << "Case #" << t << ": "
                     << "IMPOSSIBLE" << endl;
            else
                cout << "Case #" << t << ": 1" << endl;
        }
        else 
        {
            int m = ans[0];
            int count = 1;
            for(int i = 1; i < ans.size(); i++) {
                if(ans[i] >= m){
                    count++;
                    m = ans[i];
                } 
            }
            int r = ans[ans.size()-1];
            int c1 = 1;
            for(int i = ans.size()-2; i>=0;i--) {
                if(ans[i] >= r) {
                    c1++;
                    r= ans[i];
                }
            }
        
            if(count != a or c1 != b) {
                cout << "Case #" << t << ": "
                     << "IMPOSSIBLE" << endl;
            }
            else{
                cout << "Case #" << t << ": ";
                for(auto x : ans) cout << x << " ";
                cout << endl;
            }
        }
    }
    return 0;
}


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

vector<pair<int,int>> printFactors(int n)
{
    vector<pair<int, int>> factors;

    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            factors.push_back(make_pair(i, count));
        }
    }
    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }
    return factors;

    // for (auto p : factors)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    // return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin>> n;
        vector<int> arr(n); 
        int A[3001] = {0};
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            A[arr[i]]++;
            mx = max(mx, arr[i]);
        }

        A[mx]--;
        vector<int> ans;
        ans.push_back(mx);
        vector<pair<int,int>> factors = printFactors(mx);
        int cur = mx;

        // while(cur != 1) {
        for(int i = 0; i < factors.size(); i++) {
            int div = factors[i].first;
            if(cur % div != 0) continue;
            int temp = cur / div;
            while(temp >= 1) {

                while(A[temp] > 0){
                    ans.push_back(temp);
                    A[temp]--;
                }
                for(int j = 2; temp*j <= mx; j++) {
                    while(A[temp*j] > 0) {
                        ans.push_back(temp*j);
                        A[temp*j]--;
                    }
                }
                temp /= div; 
            }

        }
        for(int i = 1; i <= 3000; i ++) {
            if(A[i] != 0) {
                ans.push_back(i);
            }
        }
        for(auto x : ans) cout << x << " ";
        cout << endl;
        // }
   
        // for(auto x : arr) cout << x << " ";
        // cout << endl;
    }
    return 0;
}
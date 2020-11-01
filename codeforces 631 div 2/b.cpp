#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector<int> A(no_of_elements + 1);
    for (int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    set<int> S;
    for (int i = 1; i <= no_of_elements; i++)
    {
        S.insert(i);
    }

    vector<int> prefix_mex(no_of_elements + 1);
    for (int i = 1; i <= no_of_elements; i++)
    {
        if (S.find(A[i]) != S.end())
        {
            S.erase(A[i]);
        }

        prefix_mex[i] = *(S.begin());
    }
    // cout << "prefix Mex: " ;
    // for(int i = 1; i <= no_of_elements; i++) {
    //     cout << prefix_mex[i] << ",";
    // }
    cout << endl;

    for (int i = 1; i <= no_of_elements; i++)
    {
        S.insert(i);
    }

    vector<int> suffix_mex(no_of_elements + 1);
    for (int i = no_of_elements; i >= 1; i--)
    {
        if (S.find(A[i]) != S.end())
        {
            S.erase(A[i]);
        }

        suffix_mex[i] = *(S.begin());
    }

    // cout << "suffix Mex: ";
    // for (int i = 1; i <= no_of_elements; i++)
    // {
    //     cout << suffix_mex[i] << ",";
    // }
    // cout << endl;

    vector<pair<int, int>> answer;
    for (int i = 1; i < no_of_elements; i++)
    {
        if (prefix_mex[i] == i + 1 && suffix_mex[i + 1] == no_of_elements - i + 1)
        {
            answer.push_back(make_pair(i, no_of_elements - i));
        }
    }

    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) solve();

    return 0;
}
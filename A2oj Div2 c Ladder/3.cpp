#include <bits/stdc++.h>
using namespace std;
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
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int zero, one;
    cin >> zero >> one;

    if (one < zero - 1 or one > 2 * (zero + 1))
    {
        cout << -1 << " ";
        return 0;
    }
    if (zero >= one)
    {
        while (one + zero > 0 and zero > 0 and one > 0)
        {
            cout << "01";
            one--;
            zero--;
        }
        if (zero > 0)
            cout << "0";
        return 0;
    }
    while (one > 0 and zero > 0)
    {
        if (one > zero)
        {
            cout << "11";
            one-=2;
        }
        else if (one == zero){
            cout << "1";
            one--;
        }
        cout << "0";
        zero--;
    }
    if(zero > 0) cout << 0;
    while(one > 0) cout << 1, one--; 

    return 0;
}

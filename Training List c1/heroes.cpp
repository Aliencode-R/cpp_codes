#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
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
#define sz(x) ((int)x.size())
#define int long long


typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
int a, b, c; 
bool like[7][7];
map<string, int> idx;   
int minDiff = imax, maxLike = 0; 

void init(){
    vector<string> name = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    for (int i = 0; i < name.size(); i++)
        idx[name[i]] = i;
}

void helper(int i, vi &aa, vi &bb, vi &cc) {
    if(i == 7) {
        if(aa.empty() or bb.empty() or cc.empty() ) {
            return; 
        }
        int expA = a / sz(aa);
        int expB = b / sz(bb);
        int expC = c / sz(cc);

        int maxExp = max({expA, expB, expC});
        int minExp = min({expA, expB, expC});
        int minDiffHere = maxExp - minExp; 

        int LikeA = 0;
        int LikeB = 0;
        int LikeC = 0;

        for(int p : aa) {
            for(int q : aa) {
                LikeA += like[p][q];
            }
        }

        for (int p : bb)
        {
            for (int q : bb)
            {
                LikeB += like[p][q];
            }
        }
        for (int p : cc)
        {
            for (int q : cc)
            {
                LikeC += like[p][q];
            }
        }

        int likeHere = LikeA + LikeB + LikeC;

        if((minDiffHere < minDiff) or (minDiffHere == minDiff and likeHere > maxLike))
        {
            minDiff = minDiffHere;
            maxLike = likeHere;
        }

    } else {
        aa.push_back(i);
        helper(i + 1, aa, bb, cc);
        aa.pop_back();

        bb.push_back(i);
        helper(i + 1, aa, bb, cc);
        bb.pop_back();
        
        cc.push_back(i);
        helper(i + 1, aa, bb, cc);
        cc.pop_back();
    }
}

void solve () {
    int n; cin >> n; 
    for(int i = 0; i < n; i++) {
        string u, temp, v;
        cin >> u >> temp >> v; 
        like[idx[u]][idx[v]] = true;
    }
    cin >> a >> b >> c;
    vector<int> aa, bb, cc;
    helper(0, aa, bb, cc);
    cout << minDiff << " " << maxLike;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--) {
        solve();
    }
    return 0;
}
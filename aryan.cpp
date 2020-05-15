/*author - Aryan Mittal*/
#include<bits/stdc++.h>
using namespace std;

#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front

#define mod 1000000007
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)

#define mp make_pair
#define ff first
#define ss second
#define null NULL

#define all(c) (c).begin(),(c).end()
#define nl "\n"

typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll,ll> pll;
typedef map< ll,ll> mll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;

    while(t--){

        ll n,k;
        cin>>n>>k;

        ll a[n+1];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        ll pref[2*k+50]={0};
        vector<pair<ll,ll>> input;
        for(ll i=0;i<n/2;i++){
            ll min_v = min(a[i],a[n-i-1]);
            ll max_v = max(a[i],a[n-i-1]);
            input.push_back(make_pair(min_v,max_v));
        }

        // 1 change
        map<ll,ll> mp;
        for(auto pair : input){
            ll l = pair.first + 1;
            ll r = pair.second  + k;

            mp[pair.first + pair.second]++;

            pref[l] += 1;
            pref[r+1] -= 1;
        }

        ll sum = 0;
        for(ll i=2;i<=2*k;i++){
            sum += pref[i];
            pref[i] = sum;
        }

        ll min_change = n;
        for(ll i=2;i<=2*k;i++){
            ll cnt0 = mp[i];
            ll cnt1 = pref[i] - cnt0;
            ll cnt2 = (n/2)-cnt1-cnt0;

            // total_changes
            ll t_changes = 0*cnt0 + 1*cnt1 + 2*cnt2;

            min_change = min(min_change,t_changes);
        }

        cout<<min_change<<"\n";

    }

    
    return 0;
}
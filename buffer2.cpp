#include<bits/stdc++.h>
using namespace std;
#define mat vector<vector<long long >> 
#define vec vector<long long>
#define umap unordered_map
#define ll long long
#define pb push_back

void fucku(){
    
}

int main()
{
    // IOS;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vec arr(n + 1);
        umap<ll, ll> mp;
        mp.reserve(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            mp[arr[i]] = i;
        }
        mat ans;
        ans.reserve(k);
        // logic
        int flag = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (arr[i] == i)
            {
                continue;
            }
            ll i2 = mp[i];
            ll i3 = mp[i2];
            if (i3 == i)
            {
                i3 = i + 1;
                if (i3 == i2)
                {
                    i3++;
                }
                while (i3 <= n and i3 == arr[i3])
                {
                    i3++;
                    if (i3 > n)
                    {
                        break;
                    }
                    if (i3 == i or i3 == i2)
                    {
                        i3++;
                    }
                    if (i3 != arr[i3])
                    {
                        break;
                    }
                }
            }
            if (i3 > n)
            {
                flag = 1;
                break;
            }
            // now handle swaps and update the map
            vec temp = {i, i3, i2};
            ans.pb(temp);
            ll mi = arr[i];
            ll mi2 = arr[i2];
            ll mi3 = arr[i3];
            swap(arr[i], arr[i2]);
            swap(arr[i2], arr[i3]);

            for (int i = 1; i <= n; i++)
                cout << arr[i] << " ";
                cout << endl;
            // for(int k=1; k<=n; k++){
            //     cout<<arr[k]<<" ";
            // }
            // cout<<endl;
            swap(mp[mi], mp[mi2]);
            swap(mp[mi], mp[mi3]);
            // for(int i =1; i<=n; i++){
            //     mp[arr[i]] = i;
            // }
        }
        // for(auto i: arr){cout<<i<<" ";}

        if (ans.size() > k or flag == 1)
        {
            // cout << ans.size();
            cout << -1 << endl;

        }
        else
        {
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                for (auto val : i)
                {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
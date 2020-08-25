#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{

    int num;
    cin >> num;


    vector<int> arr(num);
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }


    int temp = arr[0];
    int ans = 0;
    for (int i = 1; i < num; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }

        else if (temp > arr[i])
        {
            ans += (temp - arr[i]);
        }
    }
    cout << ans;
    return 0;
}
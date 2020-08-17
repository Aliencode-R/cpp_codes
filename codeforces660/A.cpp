#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long

int32_t main()
{
    int n; cin >> n;
    int arr[n] , brr[n];
    int sum = 0;
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0 and brr[i] >= 0) {
            sum += arr[i];
        }
    }
    cout << sum ;

    // for()
    
    return 0;
}

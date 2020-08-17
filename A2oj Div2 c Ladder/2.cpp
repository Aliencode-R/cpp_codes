#include <bits/stdc++.h>
#include <math.h>
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i] ;

    for (int i = 0; i < n; i++) {
        if(i > 0) arr[i] += arr[i-1];
    }

    if(arr[n-1] % 3 != 0) {
        cout << 0 ;
        return 0;
    }
    int x = arr[n-1] / 3;
    int x1 = 0, x2 = 0, x3 = 0;
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == 2*x) {
            x2++;
            ans += x1;
        }
        if(arr[i] == x) {
            x1++;
            // continue;
        }
    }
    cout << ans;


    return 0;
}
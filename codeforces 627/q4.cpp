#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

bool isValid(int * a, int i, int j) {
    if(a[i]  + a[j]> 0) {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int arr[n];
    for(int i = 0; i < n;i++) {
        arr[i] = a[i] - b[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        int index = n;

        int start = i+1, end = n-1;

        while(start <= end) {
            int mid = (end - start) / 2 + start;

            if(isValid(arr, i, mid)){
                index = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
            // cout << i << " " << index << endl;
        ans += (n - index);
    }
    cout << ans;

    return 0;
}

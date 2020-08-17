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

void merge(int *arr, int start, int end) {
    int mid = (start+end) / 2;
    int i = start, j = mid+1;
    int temp[100] = {0};
    int index = 0;
    while(i <= mid and j <= end) {
        if(arr[i] <= arr[j]) {
            temp[index++] = arr[i++];
        }
        else {
            temp[index++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[index++] = arr[i++];
    }
    while(j <= end) {
        temp[index++] = arr[j++];
    }
    for(int k = 0, i = start; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergesort(int *arr, int start, int end) {
    if(start >= end) { 
        return ;
    }
    int mid = (start+end)/2;

    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);

    merge(arr,start,end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

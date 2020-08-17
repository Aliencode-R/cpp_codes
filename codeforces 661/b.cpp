#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
 
    int test; cin >> test; 
    while(test--) {
        int qww; cin >> qww;
        vector<int> arr(qww);
        for(int i = 0; i < qww; i++) {
            cin >> arr[i];

        }
        if(qww == 1) {
            cout << 0 << endl;
            continue;
        }
        if(qww == 2) {
            cout << 1 << endl;
            continue;
        }

        sort(arr.begin(),arr.end());
     
        int mm = arr[0] + arr[1];


        int llk = arr[qww-2] + arr[qww-1];
 

        int ret = INT_MIN;


        for(int w = mm; w <= llk; w++) {
            int i = 0, j = qww-1;
            int teams = 0;
            while(i < j) {




                if(arr[i] + arr[j] == w) {
                    teams++;
                    i++;
                    j--;
                } else if(arr[i] + arr[j] < w) {
                    i++;
                } else {
                    j--;
                }
            }
            ret = max(ret, teams);
        }
        cout << ret << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007
#define int long long

int32_t main() {


    int n;
    cin>>n;
    int ttttt = 1;
    int yup = 1;
    int pop = 1;
    for (int i = 1;i<=n;i++) {
        ttttt = i * yup;
        yup = ttttt%MOD;

    }
    for (int i=1;i<n;i++) {
        pop = 2*pop;
        pop = pop%MOD;
    }
    yup = yup - pop;
    yup = yup%MOD;
    cout<<yup<<"\n";


    return 0;
}

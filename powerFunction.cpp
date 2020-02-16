#include<bits/stdc++.h>
using namespace std;
#define n 1000000

int p(int x, int m)
{
    if(m == 0)
     return 1;

    if(m % 2 == 0) // even power
    {
        int val = p(x,m/2);
        return val*val;
    } else{
        int val = p(x,m/2);
        return val*val*x;
    }
}


int main()
{
    int x,m;
    cin >> x >> m;
    cout << p(x,m);
    return 0;
}
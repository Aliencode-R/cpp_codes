#include <iostream>
#include <string.h>


using namespace std;
#define int long long

int32_t main()
{
    
    string s;
    cin >> s;
    int ans = 0;
    for (char i : s)
    {
        ans += (i - '0');
        ans = ans % 9;
    }

    
    if (ans % 9 == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
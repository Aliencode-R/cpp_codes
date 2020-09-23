#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";

    // Reverse str[begin..end]
    reverse(str.begin(), str.begin() + 2);

    cout << str;
    return 0;
}
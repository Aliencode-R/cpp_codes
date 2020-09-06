#include<bits/stdc++.h>
using namespace std;
vector<int> duplicates(int a[], int n)
{
    unordered_map<int, int> p;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        p[a[i]]++;
    }

    int i = 0;
    while (i < n)
    {
        if (p[a[i]] > 1)
        {
            v.push_back(a[i]);
        }
        i++;
    }

    return v;
}
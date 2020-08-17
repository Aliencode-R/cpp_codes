#include <bits/stdc++.h>
using namespace std;
#define ll long long
int randomize()
{
    return (rand() % 10);
}
int main()
{

    srand(time(NULL));

    vector<ll> vect(500);

    generate(vect.begin(), vect.end(), randomize);
    // sort(vect.begin(),vect.end());
    cout << vect.size() << endl;
    for (int i = 0; i < vect.size()-1; i++)
    {
        cout << (rand() % 10) << " " << (rand() % 10) << " " << (rand() % 10) << endl;
        cout << (rand() % 10) << " " << (rand() % 10) << " " << (rand() % 10) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int randomize()
{
    return (rand() % 6543);
}
int main()
{

    srand(time(NULL));

    vector<ll> vect(1000);

    generate(vect.begin(), vect.end(), randomize);
    // sort(vect.begin(),vect.end());
    cout << vect.size() << endl;
    for (int i = 0; i < vect.size()-1; i++)
        cout << vect[i] << " " << vect[i+1] << " "<< (rand()%654321) << " " << (rand()%789)+87654321 << endl;

    return 0;
}
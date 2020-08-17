#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long

bool compare(pair<ll,ll> p1, pair<ll,ll> p2) {
    return p1.first > p2.first;
}

int main() {

    int n, tx, d, f, D, F, prev = 0;
    cin >> t;
    while(t--) {
        vector<pair<ll, ll>> v;
        priority_queue<ll> pq;

        cin >> n;

        for(ll i = 0; i< n; i++) {
            cin >> d >> f;
            v.push_back(make_pair(d,f));

        }

        sort(v.begin(), v.end(), compare);

        cin >> D >> F;

        for(ll i = 0; i < n; i++) {
            v[i].first = D - v[i].first;
        }

        prev = 0;
        x = 0;

        while(x < n) {

            if(F >= (v[x].first - prev)) {
                F = F - ()
            }

        }

    }
    return 0;
}
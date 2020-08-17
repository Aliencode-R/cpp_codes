#include<bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par;
    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int get(int x) {
        return (x == par[x]) ? x : par[x] = get(par[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            int parent = max(par[x], par[y]);
            par[x] = par[y] = parent;
        }
    }

};

int main() {
    int n, q;
    cin >> n >> q;
    int l[q], r[q], c[q];
    for(int i = 0; i < q; i++ ) {
        cin >> l[i] >> r[i] >> c[i];
    }

    dsu g;
    g.init(n+2);
    int res[n+2] = {0};

    for(int i = q-1; i >= 0; i--) {
        int index = g.get(l[i]);
        
        while(index <= r[i]) {
            res[index] = c[i];
            g.unite(index, index+1);

            index = g.get(index);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }

}
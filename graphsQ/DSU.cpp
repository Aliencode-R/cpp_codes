#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> parent;
    vector<int> sz;
    int components;
    
public:
    dsu(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        components = n;
    }

    int getComponents() {
        return components;
    }

    int getSuperParent(int x) {
        // path compression
        if(parent[x] == x) {
            return x;
        } else {
            return parent[x] = getSuperParent(parent[x]);
        }
    }

    void unite(int x, int y) {
        int super_x = getSuperParent(x);
        int super_y = getSuperParent(y);

        if(super_x != super_y) {
            parent[super_x] = super_y;
            sz[super_y] += sz[super_x];
            sz[super_x] = 0;
            components--;            
        }
    }
};

int main() {

}
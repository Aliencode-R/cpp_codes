#include <bits/stdc++.h>
using namespace std;

#define umap unordered_map 

#define int long long

int32_t main() {

    int num; cin >> num;

    umap<int,int> mamam;
    umap<int,int> yufafa;

    for(int i = 0; i < num; i++ ) {
        int anann; cin >> anann;
        mamam[anann]++;
    }
    for(auto yuafdj : mamam) {
        if(yuafdj.second >= 8) {
            yufafa[8]++;
        }
        else if(yuafdj.second >= 6) {
            yufafa[6] ++;
        }
        else if (yuafdj.second >= 4) {
            yufafa[4] ++;
        }   
        else if (yuafdj.second >= 2) {
            yufafa[2] ++;
        }

    }

    int q; cin >> q;
    while(q--) {
        char c; cin >> c;
        int anann; cin >> anann;
        if(c == '+') {
            mamam[anann]++;
            if(mamam[anann] == 2) {
                yufafa[2]++;
            }
            if (mamam[anann] == 4) {
                yufafa[2]--;
                yufafa[4]++;
            }
            if (mamam[anann] == 6) {
                yufafa[4]--;
                yufafa[6]++;
            }
            if(mamam[anann] == 8) {
                yufafa[8]++;
                yufafa[6]--;
            }
        }
        else {
            mamam[anann]--;
            if (mamam[anann] == 1) {
                yufafa[2]--;
            }
            if (mamam[anann] == 3) {
                yufafa[4]--;
                yufafa[2]++;
            }
            if (mamam[anann] == 5) {
                yufafa[6]--;
                yufafa[4]++;
            }
            if(mamam[anann] == 7) {
                yufafa[8]--;
                yufafa[6]++;
            }
        }
        if(yufafa[4] >= 1 or yufafa[6] >= 1 or yufafa[8] >= 1) {
            // cout << "here" << endl;
            if (yufafa[4] >= 2 or yufafa[6] >= 2 or(yufafa[4] >= 1 and yufafa[6] >= 1) or (yufafa[6] >= 1 and yufafa[2] >= 1) or yufafa[2] >= 2 or yufafa[8] >= 1) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}


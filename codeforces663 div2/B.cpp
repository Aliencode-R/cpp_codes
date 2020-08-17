#include <bits/stdc++.h>
using namespace std;



int main() {

    int test; cin>>test;
    while(test--){

        int nn,mm; cin>>nn>>mm;
        vector<vector<char>> Aarr(nn , vector<char> (mm));
        for(int i=0;i<nn;i++){



            for(int j=0;j<mm;j++){
                cin>>Aarr[i][j];
            }
        }
        int count=0;



        for(int i=0;i<mm-1;i++){
            if(Aarr[nn-1][i]=='D'){
                count++;
            }


        }
        for(int i=0;i<nn-1;i++){
            if(Aarr[i][mm-1]=='R'){
                count++;
            }
        }
        cout<<count<<"\n";



    }
    return 0;
}
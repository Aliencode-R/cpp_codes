#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;

    int x, y, amount;

    // array to store the net amount that each person will have to take at the end

    int net[100000] = {0};

    while(no_of_transactions--) {

        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;

    }

    multiset<int> m;
    
    for(int i = 0; i < friends; i++) {
        if(net[i] != 0) {
            m.insert(net[i]);
        }
    }

    int finalTransactions = 0;

    // greedy approach: popout two persons from left and right and try to settle them
    while(m.size() != 0) {

        auto low = m.begin();
        auto high = prev(m.end());

        int debit = *low;
        int credit = *high;

        // erase
        m.erase(low);
        m.erase(high);

        // settlement
        int settlementAmount = min(-debit, credit);
        finalTransactions++;

        // settlement amount from donor to acceptor , one of them will be 0 now
        debit += settlementAmount;
        credit -= settlementAmount;

        //now insert the non-zero one in the multiset
        if(debit != 0) {
            m.insert(debit);
        } 
        if(credit != 0){
            m.insert(credit);
        }
        
    }

    cout << finalTransactions;

    return 0;
}

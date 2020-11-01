#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
string actions[] = {"fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "Start"};
enum list
{
    FILL_B,
    FILL_A,
    EMPTY_B,
    EMPTY_A,
    POUR_B_A,
    POUR_A_B,
    Start
};

struct state
{
    int a, b, action;
};

const int MAX = 1000 + 9;
bool reached[MAX][MAX];
state prev_state[MAX][MAX];
queue<state> qu;

int ca, cb, required;

void backtrace(state cur) {
    if (cur.a == 0 and cur.b == 0) {
        return ;
    }
    backtrace(prev_state[cur.a][cur.b]);
    cout << actions[cur.action] << endl;
}

void add_state(int a, int b, int action, state parent) {
    if(reached[a][b]) {
        return ;
    }
    state cur = {a, b, action};
    qu.push(cur);
    prev_state[a][b] = parent;
    reached[a][b] = true;
}

void bfs(int a, int b) {
    qu = queue<state>();
    memset(reached, 0, sizeof reached);
    add_state(0, 0, Start, state());
    while(qu.size()) {
        state cur = qu.front();
        qu.pop();
        int a = cur.a, b = cur.b, aa, bb;
        if(b == required) {
            backtrace(cur);
            cout << "success" << endl;
            return ;
        }
        add_state(a, cb, FILL_B, cur);
        add_state(ca, b, FILL_A, cur);
        add_state(a, 0, EMPTY_B, cur);
        add_state(0, b, EMPTY_A, cur);

        aa = (a + b) > ca ? ca : a + b;
        bb = (a + b) > ca ? (a + b) - ca : 0;
        add_state(aa, bb, POUR_B_A, cur);

        aa = (a + b) > cb ? (a + b) - cb : 0;
        bb = (a + b) > cb ? cb : a + b;
        add_state(aa, bb, POUR_A_B, cur);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> ca >> cb >> required) {
        bfs(0, 0);
    }

    return 0;
}
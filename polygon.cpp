#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

struct point
{
    int x;
    int y;

    bool operator<(point &p)
    {
        if (p.x == x)
            return y < p.y;
        else
            return x < p.x;
    }

    bool operator==(point &p)
    {
        return x == p.x and y == p.y;
    }
};

bool counterClockWise(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool clockWise(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
bool collinear(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}

void convexHull(vector<point> &p)
{
    if (p.size() <= 2)
        return;

    sort(p.begin(), p.end());

    int n = p.size();

    point p1 = p[0];     // bottom left point
    point p2 = p[n - 1]; // top right point

    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for (int i = 1; i < n; i++)
    {
        // now check whether the current point is in upper half or lower half
        if (i == n - 1 or !counterClockWise(p1, p[i], p2))
        {
            // p[i] is in the upper half
            while (up.size() >= 2 and counterClockWise(up[up.size() - 2], up[up.size() - 1], p[i]))
            {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        if (n == n - 1 or !clockWise(p1, p[i], p2))
        {
            // p[i] is in lower half
            while (down.size() >= 2 and clockWise(down[down.size() - 2], down[down.size() - 1], p[i]))
            {
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    p.clear();
    for (int i = 0; i < up.size(); i++)
    {
        p.push_back(up[i]);
    }
    for (int i = 0; i < down.size(); i++)
    {
        p.push_back(down[i]);
    }

    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    map<pair<int,int>, int> mp;

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        point temp;
        cin >> temp.x >> temp.y;
        mp[{temp.x, temp.y}]++;
        p.push_back(temp);
    }

    convexHull(p);

    for (auto x : p)
    {
        if(mp.count({x.x, x.y}) > 0) {
            cout << "NO" ;
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
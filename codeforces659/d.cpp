#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (long long((x).size()))

void getZarr(string str, long long Z[]);

// prints all occurrences of pattern in text using Z algo
long long search(string text, string pattern)
{
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    long long l = concat.length();

    // Construct Z array
    long long Z[l];
    getZarr(concat, Z);

    // now looping through Z array for matching condition
    long long count = 0;
    for (long long i = 0; i < l; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length we got the pattern
        if (Z[i] == pattern.length())
            count ++;
    }
    return count;
}

// Fills Z array for given string str[]
void getZarr(string str, long long Z[])
{
    long long n = str.length();
    long long L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (long long i = 1; i < n; ++i)
    {

        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i - L;

            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

long long maxFrequency(string str)
{
    // Your code goes here
    long long n = str.size();
    long long i = 0, j = n-1;
    string a = "", b = "";
    while(i <= j) {
        a += str[i];
        b = str[j] + b;
        if(a == b) break;
        i++; j--;
    }
    if(a != b) {
        return 1;
    }

    return search(str, a);

}

long long main()
{
    long long t; cin >> t;
    while (t--)
    {
        /* code */
        string str; cin >> str;
        cout << maxFrequency(str) << endl;
    }
    

}
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

struct operation
{
    int left, right, value;
};

int main()
{
    int no_of_elements, no_of_operations, no_of_queries;
    scanf("%d %d %d", &no_of_elements, &no_of_operations, &no_of_queries);

    vector<long long> element(no_of_elements + 1, 0);
    for (int i = 1; i <= no_of_elements; i++)
        scanf("%I64d", &element[i]);

    vector<operation> operations(no_of_operations + 1);
    for (int i = 1; i <= no_of_operations; i++)
        scanf("%d %d %d", &operations[i].left, &operations[i].right, &operations[i].value);

    vector<int> no_of_operations_starting(no_of_operations + 2, 0);
    while (no_of_queries--)
    {
        int left_operation, right_operation;
        scanf("%d %d", &left_operation, &right_operation);

        no_of_operations_starting[left_operation]++;
        no_of_operations_starting[right_operation + 1]--;
    }

    vector<int> no_of_uses(no_of_operations + 1, 0);
    for (int i = 1; i <= no_of_operations; i++)
        no_of_uses[i] = no_of_uses[i - 1] + no_of_operations_starting[i];

    vector<long long> no_of_updates_starting(no_of_elements + 2, 0);
    for (int i = 1; i <= no_of_operations; i++)
    {
        int start_point = operations[i].left, end_point = operations[i].right, d = operations[i].value;

        no_of_updates_starting[start_point] += no_of_uses[i] * 1LL * d;
        no_of_updates_starting[end_point + 1] -= no_of_uses[i] * 1LL * d;
    }

    vector<long long> amount_to_be_added(no_of_elements + 1, 0);
    for (int i = 1; i <= no_of_elements; i++)
        amount_to_be_added[i] = amount_to_be_added[i - 1] + no_of_updates_starting[i];

    for (int i = 1; i <= no_of_elements; i++)
        element[i] += amount_to_be_added[i];

    for (int i = 1; i <= no_of_elements; i++)
        printf("%I64d ", element[i]);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
// #define a first
// #define b second
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
    return 0;
}

ListNode *Solution::partition(ListNode *A, int B)
{
    ListNode *start, *a, b;
    ListNode newnode = new ListNode(0);
    newnode->next = A;
    start = newnode;
    // cout<val;
    while (start->next != NULL && start->next->val < B)
    {
        start = start->next;
    }
    // cout<val<<endl;
    b = start;
    a = b;
    while (b != NULL)
    {
        if (b->next != NULL && b->next->val < B)
        {
            b = b->next;
            a->next = b->next;
            b->next = start->next;
            start->next = b;
            start = b;
            b = a;
        }
        else
        {
            b = b->next;
            a = b;
        }
    }
    A = newnode->next;
    return A;
}

ListNode *Solution::partition(ListNode *A, int B)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *pre = dummyHead;
    ListNode *curr = A;
    pre->next = curr;
    ListNode *currpre = pre; //currpre=previous of current
    while (curr != NULL)
    {
        if (curr->val < B)
        {
            if (pre->next != curr)
            {
                ListNode *prenext = pre->next;   //storing previous next
                ListNode *currnext = curr->next; //storing current next
                pre->next = curr;
                curr->next = prenext;
                currpre->next = currnext;
                pre = curr;
                curr = currpre;
            }
            else
                pre = curr;
        }
        currpre = curr;
        curr = curr->next;
    }
    return dummyHead->next;
}

ListNode *Solution::insertionSortList(ListNode *A)
{
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = A;
    while (A->next != NULL)
    {
        ListNode *next = A->next;
        if (A->val < next->val) //that means array is sorted till A
        {
            A = next;
            continue;
        }
        ListNode *prevtrace = dummyHead;
        ListNode *trace = prevtrace->next;
        while (trace->val < next->val) //we will search upto sorted list
        {
            prevtrace = trace;
            trace = trace->next;
        }
        A->next = next->next;         //we will remove the next link of A and inserting it after prevtrace
        next->next = prevtrace->next; //as upto prevtrace list is sorted
        prevtrace->next = next;
    }
    return dummyHead->next;
}
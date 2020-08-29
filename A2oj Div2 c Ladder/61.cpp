#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string number;
int freq[10];

int numbers[] = {9681, 8961, 9816, 6891, 8691, 9861, 8196};

int main()
{
    cin >> number;
    for (int i = 0; i < number.size(); i++)
    {
        freq[number[i] - '0']++;
    }

    freq[9]--;
    freq[8]--;
    freq[6]--;
    freq[1]--;

    int res = 0;
    for (int d = 1; d <= 9; d++)
    {
        for (int f = 0; f < freq[d]; f++)
        {
            res *= 10;
            res += d;
            res %= 7;
            printf("%d", d);
        }
    }

    res *= 10000;

    for (int i = 0; i < 7; i++)
    {
        if ((res + numbers[i]) % 7 == 0)
        {
            printf("%d", numbers[i]);
            break;
        }
    }

    for (int i = 0; i < freq[0]; i++)
        printf("0");

    printf("\n");
}
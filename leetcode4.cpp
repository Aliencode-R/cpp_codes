       #include <bits/stdc++.h>
using namespace std;
#define ll long long
    void moveZeroes(vector<int>& nums) {
        // int j = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == 0)
            {
                int j = i+1;
                while(j < nums.size()-1 && nums[j] == 0)
                {
                    j++;
                }
                // swap(nums[i],nums[j]);
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                cout << nums[i] << " " << nums[j] <<" " << j<<  endl;
            }
            
        }
    }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    int i = 0;
    while(i != -1)
    {
        
        cin >> i;
        if(i != -1)
           v.push_back(i);
    }
    // v.pop_back();
    moveZeroes(v);
    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool answer(vector<int>& nums, vector<vector<bool> >& arr, int sum, int row, int col)
    {
        for(int j=0; j < col; j++)
        {
            arr[0][j] = false;
        }
        
        for(int i=0; i <= nums.size(); i++)
        {
            arr[i][0] = true;
        }
        
        for(int i=1; i<=nums.size(); i++)
        {
            for(int j=1; j<col; j++)
            {
                if(nums[i-1] <= j)
                {
                    arr[i][j] = (arr[i-1][j-nums[i-1]] || arr[i-1][j]);
                }
                else
                    arr[i][j] = arr[i-1][j];
            }
        }
        
        return arr[nums.size()][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto i: nums)
            sum+=i;
        
        if(sum%2!=0)
            return false;
        
        sum = sum/2;
        
        vector<vector<bool>> vec(nums.size()+1, vector<bool>(sum+1));
        
        return answer(nums, vec, sum, nums.size()+1, sum+1);
    }
};



int main()
{

}
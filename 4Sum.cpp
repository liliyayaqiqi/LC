/**
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        // similar to the problem of 3 sum. Another for loop is needed
        // Use pruning (early stop) to optimize execution
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1])
            {
                continue;
            }
            //pruning to optimize, local minimum larger than target
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }
            //pruning to optimize, local maximum smaller than target
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
            {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                int b = nums[j];
                if (j > i + 1 && b == nums[j - 1])
                {
                    continue;
                }
                //pruning to optimize
                if (a + b + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                if (a + b + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                {
                    continue;
                }
                int k = j + 1;
                int m = nums.size() - 1;
                while (k < m)
                {
                    int c = nums[k];
                    int d = nums[m];
                    int sum = a + b + c + d;
                    if (sum == target)
                    {
                        result.push_back(vector<int>{a, b, c, d});
                        while (k < m && c == nums[++k]);
                        while (k < m && d == nums[--m]);
                    }
                    else if (sum < target)
                    {
                        ++k;
                    }
                    else
                    {
                        --m;
                    }
                }
            }
        }
        return result;
    }
};

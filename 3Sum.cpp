/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int a = nums[i];
            if (a > 0)
            {
                break;
            }
            if (i > 0 && a == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int b = nums[j];
                int c = nums[k];
                int value = a + b + c;
                if (value == 0)
                {
                    result.push_back(std::vector<int>{a, b, c});
                    while(j < k && b == nums[++j]);
                    while(j < k && c == nums[--k]);
                }
                else if (value < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //建立原数组中数值到下标的映射
        std::unordered_map<int, int> lut;
        for (int i = 0; i < nums.size(); ++i)
        {
            //在map中插入新元素前，先看这之前的元素是否可以和新元素组成解
            int other = target - nums[i];
            if (lut.find(other) != lut.end())
            {
                //若有解，则返回答案
                return std::vector<int>{lut[other], i};
            }
            //否则将新的解插入映射
            lut[nums[i]] = i;
        }
        return std::vector<int>{};
    }
};
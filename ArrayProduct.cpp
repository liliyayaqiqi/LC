/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6]. 
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */
  vector<int> productExceptSelf(vector<int>& nums)
  {
  	 vector<int> answer(nums.size(), 1);
  	 int pre = 1;
  	 int i = 0;
  	 for (; i < nums.size(); i++)
  	 {
  	 	answer[i] *= pre;
  	 	pre *= nums[i];
  	 }
  	 pre = 1;
  	 i = nums.size() - 1;
  	 for (; i >= 0; i--)
  	 {
  	 	answer[i] *= pre;
  	 	pre *= nums[i];
  	 }
  	 return answer;
  }
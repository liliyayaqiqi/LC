class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	vector<int>::iterator it = nums.begin();
    	int sum = 0;
    	for(; it != nums.end(); it++)
    		sum ^= *it;
    	return sum;        
    }
};
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n)
 to hold additional elements from nums2. 
 The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
 {
 	int p1 = m - 1;
 	int p2 = n - 1;
 	int index = m + n -1;
 	while(p1 >=0 || p2 >=0)
 	{
 		if (p2 < 0)
 			break;
 		if (p1 < 0)
 			nums1[index--] = nums2[p2--];
 		else
 			nums1[index--] = nums1[p1] > nums2[p2]? nums1[p1--] : nums2[p2--];
 	}
 }
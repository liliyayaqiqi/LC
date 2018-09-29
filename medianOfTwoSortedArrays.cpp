class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int totalLength = nums1.size() + nums2.size();
      int count = 0;
      auto iter1 = nums1.begin();
      auto iter2 = nums2.begin();
      double median = 0.0;
      int lastValue = 0;
      int value = 0;
      while (count <= totalLength / 2)
      {
         lastValue = value;
         if (iter1 != nums1.end() && iter2 != nums2.end())
         {
            if (*iter1 < *iter2)
            {
               value = *iter1;
               iter1++;
            }
            else
            {
               value = *iter2;
               iter2++;
            }
         }
         else if (iter1 != nums1.end())
         {
            value = *iter1;
            iter1++;
         }
         else //iter2 != nums2.end()
         {
            value = *iter2;
            iter2++;
         }
         if (count == totalLength / 2)
         {
            if (totalLength % 2 == 1)
            {
               median = value;
            }
            else
            {
               median = static_cast<double>(value + lastValue) / 2;
            }
         }
         ++count;
      }
      return median;
   }
};
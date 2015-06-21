/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
void quickSort(vector<int>& nums, int begin, int end)
{
    if (begin >= end)
        return;
    int pivot = (begin + end) / 2;
    swap(nums[begin], nums[pivot]);
    int index = begin;
    for (int i = begin + 1; i <= end; i++)
    {
        if (nums[i] < nums[begin])
            swap(nums[++index], nums[i]);
    }
    swap(nums[index], nums[begin]);
    quickSort(nums, begin, index - 1);
    quickSort(nums, index + 1, end);
}
void nextPermutation(vector<int>& nums)
{
    int end = nums.size() - 1;
    int index = end;
    for(; index > 0; index--)
    {
        if (nums[index] > nums[index - 1])
            break;
    }
    quickSort(nums, index, end);
    if (index > 0)
    {
        int indSwap = index;
        while (indSwap <= end && nums[indSwap] <= nums[index - 1])
            indSwap++;
        swap(nums[indSwap], nums[index - 1]);
    }
}
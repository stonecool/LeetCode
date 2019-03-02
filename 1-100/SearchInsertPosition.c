// 23：24 - 23:26
int searchInsert(int* nums, int numsSize, int target) {
    if (NULL == nums || numsSize == 0)
        return 0;
    
    int i = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] >= target)
            break;
    }
    
    return i;
}

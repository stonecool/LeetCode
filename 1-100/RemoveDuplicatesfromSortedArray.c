// 23:27 - 23:30
int removeDuplicates(int* nums, int numsSize) {
    if (NULL == nums || numsSize <= 0)
        return 0;
    
    int ret = 1;
    for (int i = 1;i < numsSize; ++i)
    {
        if (nums[i] != nums[i - 1])
            nums[ret++] = nums[i];
    }
    
    return ret;
}

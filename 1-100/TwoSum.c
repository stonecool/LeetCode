/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    
    // solution1
    int flag = 0;
    
    for (int i = 0;i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
                flag = 1;
                break;
            }
        }
        
        if (flag)
            break;
    }
    
    
    return ret;
}

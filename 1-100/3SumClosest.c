// 22:58 - 23:26
void quickSort(int *nums, int left, int right)
{
    if (left >= right)
        return;
    
    int l = left, r = right + 1, temp = 0;
    
    while (1){
        while (nums[++l] < nums[left] && l < right);
    
        while (nums[--r] > nums[left] && r > left);
        
        if (l >= r)
            break;
    
        temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    
    temp = nums[r];
    nums[r] = nums[left];
    nums[left] = temp;
    
    quickSort(nums, left, r - 1);
    quickSort(nums, r + 1, right);
}

int threeSumClosest(int* nums, int numsSize, int target) 
{
    if (NULL == nums || numsSize < 3)
        return 0;
    
    quickSort(nums, 0, numsSize - 1);
    
    int i = 0, j = 0, k = 0, sum = 0, sub = 0, ret = INT_MAX;
    
    for (i = 0; i < numsSize - 2; ++i)
    {
        j = i + 1;
        k = numsSize - 1;
        
        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            
            if (sum == target)
                return target;
            else
            {
                sub = sum - target;
                
                // x，-x 对于 y 的大小关系一致，则绝对值x的小
                if ((sub < ret) == (-1 * sub < ret))
                    ret = sub;
                
                if (sum < target)
                    ++j;
                else
                    --k;
            }
        }
    }
    
    return target + ret;
}

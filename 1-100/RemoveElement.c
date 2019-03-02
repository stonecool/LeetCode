// 23:10 - 23:18
/*
solution 1
void swap(int* nums, int left, int right)
{
    if (left == right)
        return;
    
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = nums[left];
}

int removeElement(int* nums, int numsSize, int val) {
    if (NULL == nums || numsSize <= 0)
        return 0;
    
    int tail = 0, i = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            swap(nums, tail++, i);            
        }
    }
    
    return tail;
}
*/

// 这种方法好，不需要temp再去存储中间变量。因为result 之前的才是必须的，才是有意义的，这样直接覆盖不会影响 result之前的所有元素
int removeElement(int* nums, int numsSize, int val) {
    if (NULL == nums || numsSize <= 0)
        return 0;
    
    int result = 0;
    for (int i = 0; i < numsSize; ++i)
        if (nums[i] != val)
            nums[result++] = nums[i];
    
    return result;
}

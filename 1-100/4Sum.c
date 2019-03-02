/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 00：24 - 01:02
void quickSort(int* nums, int begin, int end)
{
    if (begin >= end)
        return;
    
    int left = begin, right = end + 1, temp = 0;
    
    while (1)
    {
        while (nums[++left] < nums[begin])
			if (left == end)
                break; 
        while (nums[--right] > nums[begin]) ;
        
        if (left >= right)
            break;
        
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    
	temp = nums[begin];
    nums[begin] = nums[right];
    nums[right] = temp;
    
    quickSort(nums, begin, right - 1);
    quickSort(nums, right + 1, end);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (nums == NULL || numsSize < 4)
        return NULL;
    
    int total = 64;
    
    int i = 0, j = 0, k = 0, l = 0, temp = 0, p = 0, q = 0;
    int **t =(int**)malloc(sizeof(int*) * total);
    for (p = 0; p < total; ++p)
        t[p] = (int *)malloc(sizeof(int) * 4);
    
    quickSort(nums, 0, numsSize - 1);
 

    p = 0;
    for (i = 0;i < numsSize - 3; ++i)
    {
        for(j = i + 1; j < numsSize - 2; ++j)
        {
            k = j + 1;
            l = numsSize - 1;

            while (k < l)
            {
                temp = nums[i] + nums[j] + nums[k] + nums[l];

                if (temp == target)
                { 
                    if (p > 0 && 
                        t[p - 1][0] == nums[i] &&
                        t[p - 1][1] == nums[j] &&
                        t[p - 1][2] == nums[k] &&
                        t[p - 1][3] == nums[l])
                    {
                        ++k;
                        --l;
                        continue;
                    }
                    t[p][0] = nums[i];
                    t[p][1] = nums[j];
                    t[p][2] = nums[k];
                    t[p][3] = nums[l];

                    if (++p >= total)
                    {
                        total <<= 1;
                        t = (int**)realloc(t, sizeof(int*) * total);
                        for (q = p; q < total; ++q)
                            t[q] = (int *)malloc(sizeof(int) * 4);
                    }
                }
                else if (temp < target)
                    ++k;
                else
                    --l;
            }
            
            while (j + 1 < numsSize - 2 && nums[j] == nums[j + 1])
                ++j;
        }
        
        while (i + 1 < numsSize - 3 && nums[i] == nums[i + 1])
                ++i;
    }

    *returnSize = p;
    return t;
}

// 看了一个C++的方法，将前两个元素的和存起来，再遍历后两个，最后求总和，分而治之

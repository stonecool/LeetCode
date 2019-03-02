/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 这个题目，解了一天，开始是快排有问题，解决办法：基础基础基础
// 后来是，返回值溢出，解决办法：动态申请空间
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

// solution 2
/*
void swap(int *num, int left, int right)
{
    if (NULL == num || left == right)
        return;
    
    int temp = num[left];
    num[left] = num[right];
    num[right] = temp;
}

int partition(int *nums, int left, int right)
{
    int tail = left, i = left;
    
    for (;i < right; ++i)
    {
        if (nums[i] < nums[right])
        {
            swap(nums, tail++, i);
        }
    }
    
    swap(nums, tail, right);
    
    return tail;
}

void quickSort(int *nums, int left, int right)
{
    if (left >= right)
        return;
    
    int middle = partition(nums, left, right);
    
    quickSort(nums, left, middle - 1);
    quickSort(nums, middle + 1, right);
}
  
/*
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
*/
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3)
        return NULL;
    
    int total = 64;
    
    int i = 0, j = 0, k = 0, temp = 0, p = 0, q = 0;
    int **target =(int**)malloc(sizeof(int*) * total);
    for (p = 0; p < total; ++p)
        target[p] = (int *)malloc(sizeof(int) * 3);
    
    quickSort(nums, 0, numsSize - 1);
 

    *returnSize = 0;
    p = 0;
    while (i < numsSize - 2)
    {
        j = i + 1;
        k = numsSize - 1;

        while (j < k)
        {
            temp = nums[i] + nums[j] + nums[k];

            if (temp == 0)
            { 
                target[p][0] = nums[i];
                target[p][1] = nums[j];
                target[p][2] = nums[k];

                if (++p >= total)
                {
                    total <<= 1;
                    target = (int**)realloc(target, sizeof(int*) * total);
                    for (q = p; q < total; ++q)
                        target[q] = (int *)malloc(sizeof(int) * 3);
                }

                while (++j < k && nums[j] == nums[j - 1]);

                while (j < --k && nums[k] == nums[k + 1]);
            }
            else if (temp < 0)
                ++j;
            else
                --k;
        }

        while (++i < numsSize - 2 && nums[i] == nums[i - 1]);
    }

    *returnSize = p;
    return target;
}

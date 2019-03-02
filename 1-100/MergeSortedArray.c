void merge(int* nums1, int m, int* nums2, int n) {
    if (NULL == nums2 || n <= 0)
        return;
    
    int i = m, j = n;
    
    while (i > 0 || j > 0)
    {
        if (i == 0)
        {
            nums1[i + j - 1] = nums2[j - 1];
            --j;
        }
        else if (j == 0)
        {
            nums1[i + j - 1] = nums1[i - 1];
            --i;
        }else if (nums1[i - 1] > nums2[j - 1])
        {
            nums1[i + j - 1] = nums1[i - 1];
            --i;
        }
        else
        {
            nums1[i + j - 1] = nums2[j - 1];
            --j;
        }
    }
    
}

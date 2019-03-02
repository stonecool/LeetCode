/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 23:26 - 23:49
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (NULL == digits || digitsSize <= 0)
        return NULL;
    
    int p = 1; //代表需要进位
    int *q = digits;
    *returnSize = digitsSize;
    
    for (int i = digitsSize - 1, sum = 0; i >= 0; --i)
    {
        sum = digits[i] + p;
        digits[i] = sum % 10;
        p = sum / 10;
    }
    
    if (p)
    {
        q = (int*)malloc(sizeof(int) * (digitsSize + 1));
        q[0] = 1;
        for (int i = 0; i < digitsSize; ++i)
            q[i + 1] = digits[i];
        *returnSize += 1;
    }
    
    return q;
}

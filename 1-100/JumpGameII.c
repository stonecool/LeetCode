int jump(int* nums, int numsSize){
    if (numsSize <= 0)
        return 0;
    
    int step[numsSize];
    memset(step, 0, sizeof(step));
    
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < nums[i] && i + j + 1< numsSize; ++j) {
            if (step[i + j + 1] == 0)
                step[i + j + 1] = step[i] + 1;
        }
    }
    
    return step[numsSize - 1];
}

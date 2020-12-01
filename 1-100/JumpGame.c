bool canJump(int* nums, int numsSize){
    if (numsSize <= 0) {
        return true;
    }
    
    int touch = 1;
    for (int i = 1 ; i <= numsSize; ++i) {
        if (i + nums[i - 1] > touch)
            touch = i + nums[i - 1];
        
        if (touch <= i || touch >= numsSize)
            break;
    }
    
    if (touch >= numsSize)
        return true;
    else
        return false;
}

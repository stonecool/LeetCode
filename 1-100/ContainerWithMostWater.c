// 09:28 - 09：40
int maxArea(int* height, int heightSize) {
    int max = 0, min = 0, left = 0, right = heightSize - 1;
    
    while (left < right)
    {
        if (height[left] < height[right])
            min = height[left++];
        else
            min = height[right--];
        
        // 把这部分摘出来
        if ((right - left + 1) * min > max)
            max = (right - left + 1) * min;
    }
    
    return max;
}

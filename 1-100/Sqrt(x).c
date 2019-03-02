// 00:55 - 01:06
// 这个方法很巧妙，二分查找
/*
int mySqrt(int x) {
    if (1 == x || 0 == x)
        return x;
    
    long left = 1;
    long right = x;
    long mid = (left + right)/2;
    while(left < right){
        if(mid*mid==x){
            return mid;
        }else if(mid*mid>x){
            right = mid-1;
        }else{
            left = mid+1;
        }
        mid = (left + right)/2;
        
    }
    if(mid*mid>x){
        return mid-1;
    }
    return mid;
    
}
*/

int mySqrt(int x)
{
    if (x <= 1)
        return x;
    
    long left = 1, right = x, middle = (right + left) / 2;
    
    while (left < right)
    {
        if (middle * middle == x)
            return middle;
        else if (middle * middle > x)
            right = middle - 1;
        else
            left = middle + 1;
        
        // midddle 只能放在循环的后面，细节
        middle = (left + right) / 2;
    }
    
    if (middle * middle > x)
        middle -= 1;
    
    return middle;
}

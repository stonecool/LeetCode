// 22:51 - 23:22
/* solution 1
int reverse(int x) {
    long xx = x;
    int flag = 1;
    int overflow = 0;
    
    if (xx < 0)
    {   
        flag = -1; 
        xx *= -1; 
    }   
    
    long target = 0;
    while (xx > 0)
    {   
        target = target * 10 + xx % 10; 
        xx = xx / 10; 
    }   
    
    if (target > INT_MAX)
        return 0;
    else
        return target * flag;
}
*/

/* 
solution 来源于网络 https://leetcode.com/problems/reverse-integer/discuss/242217/C%2B%2B-Simple-Solution
1. 不需要flag标记正负
2. 基础不好， -1 % 10 = -1
*/
int reverse(int x)
{
    if (x == INT_MIN)
        return 0;
    
    long target = 0;
    
    while (0 != x)
    {
        target = target * 10 + x % 10;
        x /= 10;
    }
    
    if (target < INT_MIN || target > INT_MAX)
        return 0;
    else
        return target;
}

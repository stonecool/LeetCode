// 23:23 - 23:45
// solution 1
bool isPalindrome(int x) {
    if (x < 0)
        return false;
    
    int bak = x;
    long target = 0;
    
    while (x != 0)
    {
        target = target * 10 + x % 10;
        x /= 10;
    }
    
    return bak == (int)target;
}

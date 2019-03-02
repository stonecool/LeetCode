// 23:15 - 
/*
int lengthOfLastWord(char* s) {   
    if (NULL == s)
        return 0;
    
    int len = strlen(s) - 1, i = 0, ret = 0;

    while (len >= 0 && s[len] == ' ')
        --len;
    
    if (len < 0)
        return 0;
    
    for (i = len; i >= 0; --i)
        if (s[i] == ' ')
            break;
        else
            ++ret;
    
    return ret;
}*/
// 要注意最后一位也可能是空格

// 下面的方法很巧妙
int lengthOfLastWord(char* s) {
    
    int i, ans = 0;
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            ans++;
        else 
            if (ans) 
                return ans;
    }
    
    return ans;
}

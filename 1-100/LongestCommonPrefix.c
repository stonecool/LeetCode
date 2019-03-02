// 00:34 - 01:22
char* longestCommonPrefix(char** strs, int strsSize) {
    if (NULL == strs || strsSize <= 0)
        return "";
    
    int i = 0, j = 0;
    
    while (strs[0][j] != '\0')
    {
        for (i = 1; i < strsSize; ++i)
        {
            if (strs[i][j] != strs[0][j])
                break;
        }
        
        if (i < strsSize)
            break;
        
        ++j;
    }
 
    
    char* des = (char*)malloc(j + 1);
    
    memset(des, 0, j + 1);
    strncpy(des, strs[0], j);

    return des;
}

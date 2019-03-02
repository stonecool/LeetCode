// 23:31 - 23:55
int strStr(char* haystack, char* needle) {
    if (NULL == haystack || NULL == needle || needle[0] == '\0')
        return 0;
    
    int cur = 0, subCur = 0;
    
    while (haystack[cur])
    {
        if (haystack[cur] == needle[subCur])
        {    
            ++cur;
            ++subCur;
        } else {
            cur -= subCur - 1;
            subCur = 0;
        }
        
        if (needle[subCur] == '\0')
            break;
    }
    
    if (needle[subCur] == NULL)
        return cur -subCur;
    else
        return -1;
}

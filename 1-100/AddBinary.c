// 23:53 - 00:54 
char* addBinary(char* a, char* b) {
    if (NULL == a)
        return b;
    
    if (NULL == b)
        return a;
    
    int al = strlen(a), bl = strlen(b);
    int max = al > bl ? al + 1 : bl + 1;
    char *ret = (char *)malloc(max + 1);
    memset(ret, 0, max + 1);
    
    int temp = 0, sum = 0, i = max - 1;
    while ((al > 0) || 
           (bl > 0) || temp)
    {
        sum = temp;
        if (al > 0)
        {
            sum += a[al - 1] - 48;
            --al;
        }
        if (bl > 0)
        {   
            sum += b[bl - 1] - 48;
            --bl;
        }
        ret[i--] = sum % 2 + 48;
        temp = sum / 2;
    }
    
    if (! ret[0])
    {
        // 注意
        // strncpy(ret, ret + 1, max - 1);
        memmove(ret, ret + 1, max - 1);
        ret[max - 1] = '\0';
    }
    
	return ret;
}


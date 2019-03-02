// 01:22 - 02:07

bool stack(char* s, char c, int *p)
{
    if (c == '(' || c == '[' || c == '{')
    {   
        *p += 1;
        s[*p] = c;
        
        return true;
    } else if ((c == ')' || c == ']' || c == '}') && *p >= 0)
    {
        if ((c == ')' && s[*p] == '(') ||
            (c == ']' && s[*p] == '[') ||
            (c == '}' && s[*p] == '{'))
        {
            *p -= 1;
            return true;
        }
    }
    
    return false;
}


bool isValid(char* s) {
    if (NULL == s)
        return false;
    
    int length = strlen(s), i = -1;
    char *temp = (char*)malloc(length + 1);
    memset(temp, 0 , length + 1);
    
    while (*s)
    {
        if (! stack(temp, *s, &i))
            break;
        else
            ++s;
    }
    
    if (*s || i != -1)
        return false;
    else
        return true;
}

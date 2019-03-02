// 23:47 - 00:16
int convert(char c)
{
    int ret = 0;
    
    switch (c)
    {
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        default:
            break;
    }
    
    return ret;
}

int romanToInt(char* s) {
    int i = 0, target = 0, temp = 0, next = 0;
    
    while (s[i] != '\0')
    {   
        temp = convert(s[i]);
    
        if (0 == temp)
            return 0;
    
    
        if (s[i+1] != '\0')
        {
            next = convert(s[i + 1]);
            if (next > temp)
            {
                temp = next - temp;
                ++i;
            }
        }
    
        ++i;
    
        target += temp;
    }


    return target;
}

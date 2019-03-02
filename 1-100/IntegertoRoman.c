// 08:32 - 09:28
char* intToRoman(int num) {
    char * ret = (char *)malloc(100);
    char * tar = ret;
    
    memset(ret, 0, 100);

    int temp = 0;
    
    temp = num / 1000;

    if (3 == temp)
    {
        strncpy(ret, "MMM", 3);
        ret += 3;
    }
    else if (2 == temp)
    {
        strncpy(ret, "MM", 2);
        ret += 2;
    }else if (1 == temp)
    {
        strncpy(ret, "M", 1);
        ++ret;
    }

    num %= 1000;

    temp = num / 100;
    if (9 == temp)
    {
        strncpy(ret, "CM", 2);
        ret += 2;
    } else if (8 == temp)
    {
        strncpy(ret, "DCCC", 4);
        ret += 4;
    } else if (7 == temp)
    {
        strncpy(ret, "DCC", 3);
        ret += 3;

    } else if (6 == temp)
    {
        strncpy(ret, "DC", 2);
        ret += 2;
    } else if (5 == temp)
    {
        strncpy(ret, "D", 1);
        ++ret;

    } else if (4 == temp)
    {
        strncpy(ret, "CD", 2);
        ret += 2;

    } else if (3 == temp)
    {
        strncpy(ret, "CCC", 3);
        ret += 3;
    } else if (2 == temp)
    {
        strncpy(ret, "CC", 2);
        ret += 2;

    } else if (1 == temp)
    {
        strncpy(ret, "C", 1);
        ++ret;

    }

    num %= 100;

    temp = num / 10;
    if (9 == temp)
    {
        strncpy(ret, "XC", 2);
        ret += 2;
    } else if (8 == temp)
    {
        strncpy(ret, "LXXX", 4);
        ret += 4;

    } else if (7 == temp)
    {
        strncpy(ret, "LXX", 3);
        ret += 3;

    } else if (6 == temp)
    {
        strncpy(ret, "LX", 2);
        ret += 2;

    } else if (5 == temp)
    {
        strncpy(ret, "L", 1);
        ++ret;

    } else if (4 == temp)
    {
        strncpy(ret, "XL", 2);
        ret += 2;

    } else if (3 == temp)
    {
        strncpy(ret, "XXX", 3);
        ret += 3;

    } else if (2 == temp)
    {
        strncpy(ret, "XX", 2);
        ret += 2;

    } else if (1 == temp)
    {
        strncpy(ret, "X", 1);
        ++ret;
    }
    
    temp = num % 10;
    if (9 == temp)
    {
        strncpy(ret, "IX", 2);
        ret += 2;
    } else if (8 == temp)
    {
        strncpy(ret, "VIII", 4);
        ret += 4;

    } else if (7 == temp)
    {
        strncpy(ret, "VII", 3);
        ret += 3;

    } else if (6 == temp)
    {
        strncpy(ret, "VI", 2);
        ret += 2;

    } else if (5 == temp)
    {
        strncpy(ret, "V", 1);
        ++ret;

    } else if (4 == temp)
    {
        strncpy(ret, "IV", 2);
        ret += 2;

    } else if (3 == temp)
    {
        strncpy(ret, "III", 3);
        ret += 3;

    } else if (2 == temp)
    {
        strncpy(ret, "II", 2);
        ret += 2;

    } else if (1 == temp)
    {
        strncpy(ret, "I", 1);
        ++ret;
    }
    
    return tar;
}

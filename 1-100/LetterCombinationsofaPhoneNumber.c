/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 23:29 - 00:59
/*
void test(char c, char *l, char* h)
{
    switch (c)
    {
        case '2':
            *l = 'a', *h = 'c'; 
            break;
        case '3':
            *l = 'd', *h = 'f'; 
            break;
        case '4':
            *l = 'g', *h = 'i'; 
            break;
        case '5':
            *l = 'j', *h = 'l'; 
            break;
        case '6':
            *l = 'm', *h = 'o';
            break;
        case '7':
            *l = 'p', *h = 's';
            break;
        case '8':
            *l = 't', *h = 'v';
            break;
        case '9':
            *l = 'w', *h = 'z';
            break;
        default:
            break;
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (NULL == digits || *digits == '\0')
        return NULL;
    
    int row = 1, col = 0;
    char *c = digits;
    while (*c)
    {
        int mod = 3;
        if (*c == '9' || *c == '7')
            mod = 4;
        row *= mod;
        ++col;
		++c;
    }
    
    char **t =(char**)malloc(sizeof(char*) * row);
    
    int i = 0, j = 0, mul = 1, x = 0;
    for (i = 0; i < row; ++i)
    {
        t[i] = (char*)malloc(sizeof(char) * (col + 1));
        memset(t[i], 0, col + 1);
    }

    
    for (i = 0; i < col; ++i)
    {
        char l, h;
        
        test(digits[i], &l, &h);
        mul *= (h - l + 1);
        x = row / mul;
    
        for (j = 0; j < row; ++j)
            t[j][i] = l + j / x % (h - l + 1);
    }
    
    
	*returnSize = row;
    return t;
}

// 上面的方法，太繁琐了，应该用深度悠闲，递归调用
// 用一个当前 cur 索引，当索引 == lenght 则插入
*/

int length = 0;
int total = 64; 
char phone[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int num = 0;

void test(char *src, int cur, char **des, char * t)
{
    char ** temp = NULL;
    int i = -1; 
    
    int index = src[cur] - '0';

    while (phone[index] != NULL && phone[index][++i] != '\0')
    {   
        temp = &des[num];
        if (NULL ==*temp)
            *temp = (char *)malloc(sizeof(char) * length + 1);

        t[cur] = phone[index][i];

        if (cur == length - 1)
        {
            strcpy(*temp, t); 
            ++num;

            if (num == total)
            {
                total <<= 1;
                des = (char **)realloc(des, sizeof(char *) * total);
                memset(des + num, 0, num);
            }
        }
        else
            test(src, cur + 1, des, t); 
    }   
}

char** letterCombinations(char* digits, int* returnSize) 
{
    if (NULL == digits || *digits == '\0')
        return NULL;
    
    length = strlen(digits);
    char **p = (char **)malloc(sizeof(char *) * total);
    memset(p, 0, sizeof(char *) * total);

    char *temp = (char *)malloc(sizeof(char) * (length + 1)); 
    memset(temp, 0, length + 1); 

    test(digits, 0, p, temp);

    *returnSize = num;
    free(temp);
    return p;
}
// 放弃了，这种方式报错，应该是重新分配 realloc 地方报的错


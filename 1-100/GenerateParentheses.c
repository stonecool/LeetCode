/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 用了很久
/*
void test(char*** p, int *num, int* total, char *str, int cur, int length, int flag)
{
    if (cur == length * 2 && flag == 0)
    {   
        if (*num == *total)
        {
            *total <<= 1;
            *p = (char**)realloc(*p, *total * sizeof(char*));
            memset(*p + *num, 0, *num * sizeof(char*));
        }

        (*p)[*num] = (char*)malloc(length * 2 + 1);
        memset((*p)[*num], 0, length + 1); 
        strcpy((*p)[*num], str);
        *num += 1;
        return;
    }   

    if (cur < length * 2)
    {   
        str[cur] = '(';
        test(p, num, total, str, cur + 1, length, flag + 1); 
        if (flag > 0)
        {
            str[cur] = ')';
            test(p, num, total, str, cur + 1, length, flag - 1); 
        }
    }   
}


char** generateParenthesis(int n, int* returnSize) {
    if (n <= 0)
        return NULL;

    int total = 64, num = 0, cur = 0;
    char **p = (char**)malloc(sizeof(char* ) * total);
    char *str = (char *)malloc(n * 2 + 1); 

    memset(p, 0, sizeof(char *) * (total));
    memset(str, 0, n * 2 + 1); 

    test(&p, &num, &total, str, cur, n, 0); 

    free(str);

    *returnSize = num;
    return p;
}
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <math>

char** recursion(char** solution, char* tmpRow, int currentIndex, int opened, int closed, int maxOpened, int* currentRow);

char** generateParenthesis(int n, int* returnSize) {
    
    char** solution;
    char *tmpRow;
    
    // Allocating for first iteration
    solution = (char**) calloc(1, sizeof(char*));
    
    // Trying to generate all combinations of parenthesis
    tmpRow = (char*) calloc(2*n,sizeof(char));
    *returnSize = 0;
    solution = recursion(solution, tmpRow, 0, 0, 0, n, returnSize);
        
    return solution;
    
}

char** recursion(char** solution, char* tmpRow, int currentIndex, int opened, int closed, int maxOpened, int* currentRow)
{
    
    // If we have reached end of array, store it into the solution
    if(currentIndex == maxOpened*2)
    {
        solution = (char**) realloc(solution, ((*currentRow)+1)*sizeof(char*));
        solution[(*currentRow)] = (char*) calloc(2*maxOpened, sizeof(char));
        strcpy(solution[(*currentRow)], tmpRow);
        (*currentRow)++;
        return solution;
    }
    
    // Try to put open and close parenthesis when possible
    if(opened < maxOpened)
    {
        // We can still try to open a parenthesis
        tmpRow[currentIndex] = '(';
        solution=recursion(solution, tmpRow, currentIndex+1, opened+1, closed, maxOpened, currentRow);
    }
    if(closed < opened)
    {
        tmpRow[currentIndex] = ')';
        solution=recursion(solution, tmpRow, currentIndex+1, opened, closed+1, maxOpened, currentRow);
    }
    
    return solution;
}

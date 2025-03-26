#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void ft_print_arr(int len1, int len2, char arr[len1][len2], char *p, char *s)
{
    printf("  ");
    for (int i = 0; i < len2; i++)
    {
        if (i == 0)
            printf(YELLOW"''"RESET,p[i]);
        else
            printf(YELLOW"  %c"RESET,p[i - 1]);  
    }
    printf("\n");
    for(int i = 0; i < len1; i++)
    {
        if (i == 0)
            printf(BLUE"'' "RESET);
        else
            printf(BLUE"%c  "RESET,s[i - 1]);  
        for(int j = 0; j < len2; j++)
        {
            if (j == 0)
                printf("%c", arr[i][j] == 1? 'T' : 'F');
            else
                printf("  %c", arr[i][j] == 1 ? 'T' : 'F');
        }
        printf("\n");
    }
}

int is_match(char *str, char *patern)
{
    int len1 = strlen(str);
    int len2 = strlen(patern);

    char arr[len1 + 1][len2 + 1];
    memset(arr, 0, sizeof(arr));
    arr[0][0] = 1;
    for (int j = 1; j <= len2; j++)
    {
        if (patern[j - 1] == '*')
            arr[0][j] = arr[0][j - 1];
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str[i - 1] == patern[j - 1])
                arr[i][j] = arr[i - 1][j - 1];
            else if (patern[j - 1] == '*')
                arr[i][j] = (arr[i - 1][j] || arr[i][j - 1]); 
        }
    }
    ft_print_arr(len1 + 1, len2 + 1, arr, patern, str);
    return arr[len1][len2];
}

int main(int ac, char *av[])
{
    if (ac > 1 && ac < 4)
    {
        int c = is_match(av[1],av[2]);
        if (c)
            printf("is match\n");
        else
            printf("is not match\n");
    }
    else
        printf("number of argument is not valid\n");
}

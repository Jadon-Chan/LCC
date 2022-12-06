#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
int count = 0;
int length;
bool reserved(char *str)
{
    if (strcmp(str, "const") == 0 || strcmp(str, "int") == 0 || strcmp(str, "float") == 0 || strcmp(str, "double") == 0 || strcmp(str, "long") == 0 || strcmp(str, "static") == 0 || strcmp(str, "void") == 0 || strcmp(str, "char") == 0 || strcmp(str, "extern") == 0 || strcmp(str, "return") == 0 || strcmp(str, "break") == 0 || strcmp(str, "enum") == 0 || strcmp(str, "struct") == 0 || strcmp(str, "typedef") == 0 || strcmp(str, "union") == 0 || strcmp(str, "goto") == 0)
        return 1;
    else
        return 0;
}
bool integer(char *str)
{
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(*(str + i)))
            return 0;
    }
    return 1;
}
bool floata(char *str)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(*(str + i)) && *(str + i) != '.')
            return 0;
        else
        {
            if (*(str + i) == '.')
                count++;
        }
    }
    if (count == 1)
        return 1;
    else
        return 0;
}
bool operator1(char *str)
{
    if (strstr("+ - * / = == != > < <= >=", str) && strcmp(str, "!") != 0)
        return 1;
    else
        return 0;
}
bool variable(char *str)
{
    if (isdigit(*str))
        return 0;
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(*(str + i)) && *(str + i) != '_' && !isalpha(*(str + i)))
                return 0;
        }
    }
    return 1;
}
bool compile(char *str, int *result)
{
    if (reserved(str))
    {
        *(result + count) = 1;
        count++;
        return 1;
    }
    else if (integer(str))
    {
        *(result + count) = 2;
        count++;
        return 1;
    }
    else if (floata(str))
    {
        *(result + count) = 3;
        count++;
        return 1;
    }
    else if (operator1(str))
    {
        *(result + count) = 4;
        count++;
        return 1;
    }
    else if (variable(str))
    {
        *(result + count) = 5;
        count++;
        return 1;
    }
    else
        return 0;
}
int main(void)
{
    char *str = (char *)malloc(5000);
    int *result = (int *)malloc(sizeof(int) * 5000);
    int pos = 0;
    char ch;

    while ((ch = getchar()) != EOF)
    {
        if (isblank(ch) || ch == '\n')
        {
            length = pos;
            *(str + pos) = '\0';
            pos = 0;
            if (*str == '\0')
                continue;
            if (compile(str, result))
            {
                continue;
            }
            else
            {
                printf("Compile Error");
                system("pause");
                return 0;
            }
        }
        else if (ch == ';')
        {
            length = pos;
            *(str + pos) = '\0';
            pos = 0;
            if (*str == '\0')
            {
                *(result + count) = 6;
                count++;
                continue;
            }
            else
            {
                if (compile(str, result))
                {
                    *(result + count) = 6;
                    count++;
                    continue;
                }
                else
                {
                    printf("Compile Error");
                    system("pause");
                    return 0;
                }
            }
        }
        else
        {
            *(str + pos) = ch;
            pos++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        switch (result[i])
        {
        case 1:
            printf("reserved ");
            break;
        case 2:
            printf("integer ");
            break;
        case 3:
            printf("float ");
            break;
        case 4:
            printf("operator ");
            break;
        case 5:
            printf("variable ");
            break;
        case 6:
            printf("\n");
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
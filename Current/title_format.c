#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void lower(char *ptr)
{
    while (*ptr)
    {
        if (isupper(*ptr))
            *ptr = tolower(*ptr);
        ptr++;
    }
}
int main(void)
{
    char *str = (char*)malloc(5000);
    gets(str);
    char *ptr = str;
    lower(ptr);
    int flag = 1;
    while (*ptr)
    {
        if (flag)
            putchar(toupper(*ptr));
        else
            putchar(*ptr);
        if (*ptr == ' ')
            flag = 1;
        else 
            flag = 0;
        ptr++;
    }
    return 0;
}
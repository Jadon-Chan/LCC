#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void lower(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (*(str+i) >= 'A' && *(str+i) <= 'Z')
            *(str+i) = tolower(*(str+i));
}
int main(void)
{
    char *str = (char*)malloc(5000);
    gets(str);
    lower(str);
    int flag = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (flag)
            putchar(toupper(*(str+i)));
        else
            putchar(*(str+i));
        if (*(str+i) == ' ')
            flag = 1;
        else 
            flag = 0;
    }
    return 0;
}
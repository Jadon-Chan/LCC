#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setup(char *option_no_arg, char *option_with_arg)
{
    char *temp = (char *)malloc(1000);
    gets(temp);
    for (int i = 0; i < strlen(temp); i++)
    {
        if (*(temp + i) != ':')
        {
            char *str = (char *)malloc(2);
            sprintf(str, "%c", *(temp + i));
            if (*(temp + i + 1) == ':')
                strcat(option_with_arg, str);
            else
                strcat(option_no_arg, str);
            free(str);
        }
    }
    free(temp);
}

void parse(char *option_no_arg, char *option_with_arg)
{
    char *name = (char *)malloc(1000);
    scanf("%s", name);
    char *temp = (char *)malloc(1000);
    char **output = (char **)malloc(4000);
    int count = 0;
    do
    {
        scanf("%s", temp);
        if (strlen(temp) == 2 && temp[0] == '-')
        {
            char flag = temp[1];
            if (strchr(option_with_arg, flag))
            {
                char *value = (char *)malloc(1000);
                if (getchar() == '\n')
                {
                    printf("%s: option requires an argument -- '%c'", name, flag);
                    return;
                }
                else
                {
                    scanf("%s", value);
                    *(output + count) = (char *)malloc(1000);
                    sprintf(*(output + count), "%c=%s", flag, value);
                    count++;
                }
                free(value);
            }
            else if (strchr(option_no_arg, flag))
            {
                *(output + count) = (char *)malloc(10);
                sprintf(*(output + count), "%c", flag);
                count++;
            }
            else
            {
                printf("%s: invalid option -- '%c'", name, flag);
                return;
            }
        }
    }while(getchar() != '\n');
    puts(name);
    for (int i = 0; i < count; i++)
    {
        puts(*(output+i));
    }
}

int main(void)
{
    char *option_no_arg = (char *)malloc(130), *option_with_arg = (char *)malloc(130);
    memset(option_no_arg, 0, 130);
    memset(option_with_arg, 0, 130);
    setup(option_no_arg, option_with_arg);
    parse(option_no_arg, option_with_arg);
    system("pause");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <windows.h>

void fertilize(char *, int);

int main(void)
{
    int generation;
    char world[1007];
    for (int i = 0; i < 3; i++)
    {
        *(world +  i) = '.';
    }
    scanf("%d\n", &generation);
    scanf("%s", world + 3);
    int length = strlen(world + 3);
    for (int i = 0; i < 3; i++)
    {
        *(world + 3 + length + i) = '.';
    }
    *(world + length + 6) = '\0';

    for (int i = 1; i <= generation; i++)
        fertilize(world, length);

    for (int i = 0; i < length; i++)
        printf("%c",(*(world + 3 + i)));
    
    return 0;
}

void fertilize(char * world, int length)
{
    char copy[1007];
    strcpy(copy, world);

    for (int i = 0; i < length; i++)
    {
        int count_a = 0;
        int count_b = 0;
        if (*(world + 3 + i) == '.')
        {
            for (char * test = world + i; test <= world + 6 + i; test++)
            {
                if (test != world + 3 + i)
                {
                    if (*test == 'A')
                        count_a++;
                    else if (*test == 'B')
                        count_b++;
                }
            }
            if (count_a == 0 && count_b >= 2 && count_b <= 4)
                *(copy + 3 + i) = 'B';
            else if (count_b == 0 && count_a >= 2 && count_a <= 4)
                *(copy + 3 + i) = 'A';
        }
        else if (*(world + 3 + i) == 'A')
        {
            for (char * test = world + i; test <= world + 6 + i; test++)
            {
                if (test != world + 3 + i)
                {
                    if (*test == 'A')
                        count_a++;
                    else if (*test == 'B')
                        count_b++;
                }
            }
            if (count_b != 0 || count_a <= 1 || count_a >= 5)
                *(copy + 3 + i) = '.';
        }
        else if (*(world + 3 + i) == 'B')
        {
            for (char * test = world + i; test <= world + 6 + i; test++)
            {
                if (test != world + 3 + i)
                {
                    if (*test == 'A')
                        count_a++;
                    else if (*test == 'B')
                        count_b++;
                }
            }
            if (count_a != 0 || count_b <= 1 || count_b >= 5)
                *(copy + 3 + i) = '.';
        }
    }
    strcpy(world, copy);
    return;
}
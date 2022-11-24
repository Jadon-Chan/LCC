#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *origin = (char*)malloc(100005), *t = (char*)malloc(100005), *s;
    gets(origin);
    gets(t);
    s = origin;
    while (strstr(s, t))
    {
        printf("%d ", strstr(s, t) - origin);
        s = strstr(s, t)+1;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int *x = (int*)malloc(sizeof(int));
    float *y = (float*)malloc(sizeof(float));
    char *str = (char*)malloc(sizeof(char)*11), *ptr = str;
    *ptr++ = '0';
    *ptr++ = 'x';
    for (int i = 0 ; i < 8; i++)
        *ptr++ = getchar();
    *ptr = '\0';
    sscanf(str, "%x", x);
    memcpy(y, x, 4);
    printf("%d\n%u\n%.6f\n%.3e\n", *x, *x, *y, *y);
    return 0;
}
#include <stdio.h>
struct state{
    int water[3];
    int time;
};
struct state all[1000];
int count = 0, k;
int volume[3];
struct state pour(int i, int j, int n)
{
    struct state temp;
    temp.water[j] = all[n].water[i]+all[n].water[j]<volume[j]?all[n].water[i]+all[n].water[j]:volume[j];
    temp.water[i] = 0;
    int m = 3-i-j;
    temp.water[m] = all[n].water[m];
    temp.time = all[n].time + 1;
    return temp;
}
void produce(int n)
{
    if (all[n].water[0] != 0)
    {
        all[++count] = pour(0, 1, n);
        all[++count] = pour(0, 2, n);
    }
    if (all[n].water[1] != 0)
    {
        all[++count] = pour(1, 0, n);
        all[++count] = pour(1, 2, n);
    }
    if (all[n].water[2] != 0)
    {
        all[++count] = pour(2, 0, n);
        all[++count] = pour(0, 2, n);
    }
}
int main(void)
{
    struct state test;
    all[0].time = 0;
    scanf("%d %d %d %d %d %d %d %d %d %d", &k, volume, volume+1, volume+2, &all[0].water[0], &all[0].water[1], &all[0].water[2], &test.water[0], &test.water[1], &test.water[2]);
    int i = 0;
    while(all[i].time <= k)
    {
        if (all[i].water[0] == test.water[0] && all[i].water[1] == test.water[1] && all[i].water[2] == test.water[2])
        {
            printf("YES");
            return 0;
        }
        if (all[i].time < k)
            produce(i);
        i++;
    }
    printf("NO");
    return 0;
}
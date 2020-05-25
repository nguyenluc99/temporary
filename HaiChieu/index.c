#include <stdio.h>
#include <stdlib.h>

int **array;

void initArray(int n, int m)
{
    int i = 0;
    // use 1 of 2
    // array = (int **)malloc(n * sizeof(int *)); // sizeof(int*) = sizeof(int**) = 8
    array = (int **)malloc(n * sizeof(int)); // sizeof(int) = 4
    for (i = 0; i < n; i++)
    {
        // use 1 of 2
        array[i] = (int *)malloc(m * sizeof(int));
        // array[i] = (int *)realloc((int *)(*(array + i)), m * sizeof(int));
    }
}
void insertValue(int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Input a[%d,%d], a[%d,%d] = ", i, j, i, j);
            // scanf("%d", &array[i][j]);
            // scanf("%d", array[i] + j);
            scanf("%d", *(array + i) + j);
        }
    }
}
int findMax(int n, int m)
{
    int i, j;
    int max;
    int tmp;
    i = j = 0;
    max = -99999;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            // tmp = **(array + (i * m + j)); // 1 3 coredump
            // tmp = *(*array + (i * m + j)); //  1 2 0 0
            tmp = *(*(array + i) + j);
            // tmp = *(array[i] + j);
            // tmp = array[i][j];
            if (tmp > max)
            {
                max = tmp;
            }
        }
    }
    return max;
}
int findSum(int n, int m)
{
    int i, j;
    int sum, tmp;
    i = j = sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            tmp = *(*(array + i) + j);
            // tmp = *(array[i] + j);
            // tmp = array[i][j];
            if (tmp % 2 == 0)
            {
                sum += tmp;
            }
        }
    }
    return sum;
}
void main()
{
    int m, n;
    int max, sum;
    printf("Nhap n, n = ");
    scanf("%d", &n);
    printf("Nhap m, m = ");
    scanf("%d", &m);
    initArray(n, m);
    insertValue(n, m);
    max = findMax(n, m);
    sum = findSum(n, m);
    printf("max is : %d \n", max);
    printf("sum of element divided by 2 is : %d \n", sum);
}
#include <stdio.h>
#include <stdlib.h>
int **array;
void initArray(int n, int m)
{
    int i = 0;
    array = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(m * sizeof(int));
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
            scanf("%d", array[i] + j);
        }
        printf(" i = %d, n = %d\n", i, n);
    }
}
int findMax(int n, int m)
{
    int i, j;
    int max;
    i = j = max = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {

            {
                if (array[i][j] > max)
                {
                    max = array[i][j];
                }
            }
        }
    return max;
}
int findSum(int n, int m)
{
    int i, j;
    int sum;
    i = j = sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            if (array[i][j] % 2 == 0)
            {
                sum += array[i][j];
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
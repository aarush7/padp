#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
void printMatrix(int *arr[], int a, int b)
{
int i, j;
for (int i = 0; i < a; i++)
{
for (int j = 0; j < b; j++)
printf("%d ", arr[i][j]);
printf("\n");
}
}
int main(int argc, char *argv[])
{
int a, b, m, n, i, j, k;
printf("Enter the dimension of the first matrix\n");
scanf("%d%d", &a, &b);
printf("Enter the dimension of the second matrix\n");
scanf("%d%d", &m, &n);
int *arr1[1000], *arr2[1000];
for (i = 0; i < a; i++)
arr1[i] = (int *)malloc(b * sizeof(int));
for (i = 0; i < m; i++)
arr2[i] = (int *)malloc(n * sizeof(int));
for (i = 0; i < a; i++)
for (j = 0; j < b; j++)
arr1[i][j] = rand() % 10;
for (i = 0; i < m; i++)
for (j = 0; j < n; j++)
arr2[i][j] = rand() % 10;

int *arr3[1000];
for (i = 0; i < a; i++)
arr3[i] = (int *)malloc(n * sizeof(int));
int l;
for (l = 1; l <= 8; l = l << 1)
{
double x = omp_get_wtime();
omp_set_num_threads(l);
#pragma omp parallel for private(j, k)
for (i = 0; i < a; i++)
for (j = 0; j < n; j++)
{
arr3[i][j] = 0;
for (k = 0; k < b; k++)
arr3[i][j] += arr1[i][k] * arr2[k][j];
}
double y = omp_get_wtime();
printf("Time taken for %d thread(s) for size %d: %lf\n", l, a, y -
x);
}
/*
printf("Matrix A:\n");
printMatrix(arr1,a,b);
printf("Matrix B:\n");
printMatrix(arr2,m,n);
printf("Matrix C:\n");
printMatrix(arr3,a,n);*/
return 0;
}

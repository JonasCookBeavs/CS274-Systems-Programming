#include <stdio.h>

int array_sum(int a[], int elements)
{
    int sum = 0;
    for(int i = 0; i < elements; i++)
    {
        sum += a[i];
    }
    return sum;
}

int array_sum2(int a[])
{
    int sum = 0;
    int i = 0;
    while(a[i] != 0)
    {
        sum += a[i];
        i++;
    }
    return sum;
}

void array_print(int a[], int elements)
{
    for(int i = 0; i < elements; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void array_reverse(int a[], int elements)
{
    for(int i = 0; i < elements / 2; i++)
    {
        a[i] ^= a[elements - i - 1];
        a[elements - i - 1] ^= a[i];
        a[i] ^= a[elements - i- 1];
    }
}

int main(void)
{
    int x[5] = {1,2,3,4,5};
    int y[6] = {5,6,7,8,9,0};
    int z[7] = {1,2,3,4,5,6,7};
    int w[8] = {2,4,6,8,10,12,14,16};

    printf("First sum: %d\n", array_sum(x, 5));
    printf("Second sum: %d\n", array_sum2(y));
    array_reverse(z, 7);
    array_print(z, 7);
    array_reverse(w, 8);
    array_print(w, 8);
}
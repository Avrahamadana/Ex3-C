#include "iSortFunction.h"

void shift_element(int *arr, int i)
{
    for (int p = i; p > 0; p--)
    {
        *(arr + p) = *(arr + p - 1);
    }
}

void insertion_sort(int *arr, int len)
{
    int p;

    for (int i = 1; i < len; i++)
    {
        p = i - 1;
        while (p >= 0 && *(arr + p) > *(arr + p + 1))
        {
            int temp = *(arr + p + 1);
            shift_element(arr + p, 1);
            *(arr + p) = temp;
            p--;
        }
    }
}

int main()
{
    printf("%s", "insert 50 Numbers: \n");
    int arr[ARR_SIZE];
    int number;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &number);
        *(arr + i) = number;
    }

    insertion_sort(arr, ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d", arr[i]);

        if (i != ARR_SIZE - 1)
        {
            printf("%c", ',');
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

int **createRand2DArray(int m, int *L)
{

    int **temp = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        temp[i] = (int *)malloc(L[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < L[i]; j++)
        {
            temp[i][j] = rand() % 100;
        }
    }

    

    return temp;
}

int main()
{

    int length[5] = {3, 2, 4, 5, 2};

    int **arr = createRand2DArray(5, length);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < length[i]; j++)
        {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}
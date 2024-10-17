#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int val;
	int ind;
} IndexedValue;

int compare(const void *a, const void *b) 
{
	return ((IndexedValue *) a)->val - ((IndexedValue *) b)->val;
}

int* arrayRankTransform(int* arr, int n, int* returnSize) 
{
	IndexedValue *indexed = malloc(sizeof(IndexedValue) * n);

	for (int i = 0; i < n; ++i) {
		indexed[i] = (IndexedValue) 
        {
			.val = arr[i],
			.ind = i
		};
	}

	qsort(indexed, n, sizeof(IndexedValue), compare);

	int *res = malloc(sizeof(int) * n);
    int sameRanks = 0;
	for (int i = 0; i < n; ++i) 
    {
		IndexedValue a = indexed[i];
		res[a.ind] = i + 1 - sameRanks;
        if (i < n - 1 && indexed[i].val == indexed[i + 1].val)
            ++sameRanks;
	}

	*returnSize = n;
	return res;
}

int main() {
    int arr[] = {40, 10, 20, 30};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize;

    int* result = arrayRankTransform(arr, arrSize, &returnSize);

    printf("Rank transformed array: ");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
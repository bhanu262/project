#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

/* Comparator for qsort */
int compare(const void *a, const void *b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    
    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Pair), compare);

    int left = 0, right = numsSize - 1;
    int* result = (int*)malloc(2 * sizeof(int));

    while (left < right) {
        int sum = arr[left].value + arr[right].value;

        if (sum == target) {
            result[0] = arr[left].index;
            result[1] = arr[right].index;
            *returnSize = 2;
            free(arr);
            return result;
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }

    *returnSize = 0;
    free(arr);
    return NULL;
}

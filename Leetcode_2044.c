#include <stdio.h>

int max_or = 0;  // To store the maximum bitwise OR
int result = 0;  // To count the number of subsets with max bitwise OR

// DFS function to explore all subsets
void dfs(int *nums, int size, int index, int current_or) 
{
    // If we've checked all elements, compare the current OR with the max OR
    if (index == size) {
        if (current_or == max_or)
        {
            result++;  // Increment the count if the current OR equals the max
        }
        return;
    }

    // Exclude the current element
    dfs(nums, size, index + 1, current_or);
    
    // Include the current element
    dfs(nums, size, index + 1, current_or | nums[index]);
}

int countMaxOrSubsets(int* nums, int numsSize) 
{
    // Find the maximum possible OR value by OR-ing all elements
    for (int i = 0; i < numsSize; i++) 
    {
        max_or |= nums[i];
    }
    
    // Start DFS from the first index
    dfs(nums, numsSize, 0, 0);
    
    return result;  // Return the number of subsets achieving the max OR
}

int main() 
{
    int nums[] = {3, 2, 1, 5};  // Example input
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Number of maximum OR subsets: %d\n", countMaxOrSubsets(nums, size));
    return 0;
}

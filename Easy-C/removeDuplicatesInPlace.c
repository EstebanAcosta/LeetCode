#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

int removeDuplicates(int* nums, int numsSize)
{
    int len = numsSize,min_idx,prev = nums[0];
    
    if(numsSize <= 1) return numsSize;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i > 0 && nums[i] == prev)
        {
            prev = nums[i];
            nums[i] = INT_MAX;
            len--;
        }
        else prev = nums[i];         
    }
    
    for(int i = 0; i < numsSize - 1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[j] < nums[min_idx])  min_idx = j;
        }
        
        int temp = nums[min_idx];
        nums[min_idx] = nums[i];
        nums[i] = temp;
    }
    
    return len;
}

int main(int argc, char const *argv[])
{
    int nums[] = {12,14,15,15,15,15,70};
    removeDuplicates(nums,7);
    return 0;
}
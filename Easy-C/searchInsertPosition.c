#include <stdio.h>
#include <stdlib.h>


// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

int searchInsert(int* nums, int numsSize, int target)
{
    int start = 0, end = numsSize -1, mid;
    
    while(start <= end)
    {
        mid = start + (end - start)/2; 
        if(target == nums[mid]) return mid;
        else if(nums[mid] < target ) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,2,3,4,6,7,8,9,10};
    printf("%d\n", searchInsert(nums,9,5));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
static inline void swap_val(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static int first_Missing_Positive_num(int* nums, int nums_size)
{
    if (nums_size < 1) {
        return 1;
    }

    int i = 0;
    while (i < nums_size) {
        if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums_size && nums[i] != nums[nums[i] - 1]) {
            swap_val(nums + i, nums + nums[i] - 1);
        } else {
            i++;
        }
    }

    for (i = 0; i < nums_size; i++) {
        if (nums[i] != i + 1) break;
    }
    return i + 1;
}

int main()
{
    int i, count = 4;
    int nums[4] = {3,4,-1,1};
      
    printf("%d\n", first_Missing_Positive_num(nums, count));
    return 0;
}

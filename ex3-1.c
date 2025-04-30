/* Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time*/


#include <stdio.h>

int binarysearch(int,int [], int);


int main() {
    int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target;
    int index;

    target = 23;
    index = binarysearch(target, sorted_array, n);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index); // Expected: Found 23 at index 5
    } else {
        printf("%d not found\n", target);
    }

    target = 5;
    index = binarysearch(target, sorted_array, n);
     if (index != -1) {
        printf("Found %d at index %d\n", target, index); // Expected: Found 5 at index 1
    } else {
        printf("%d not found\n", target);
    }

    target = 50;
    index = binarysearch(target, sorted_array, n);
     if (index != -1) {
        printf("Found %d at index %d\n", target, index); // Expected: 50 not found
    } else {
        printf("%d not found\n", target);
    }

    int single_element_array[] = {100};
    index = binarysearch(100, single_element_array, 1);
    if (index != -1) {
        printf("Found %d at index %d\n", 100, index); // Expected: Found 100 at index 0
    } else {
        printf("%d not found\n", 100);
    }

     index = binarysearch(99, single_element_array, 1);
    if (index != -1) {
        printf("Found %d at index %d\n", 99, index); // Expected: 99 not found
    } else {
        printf("%d not found\n", 99);
    }


    index = binarysearch(10, sorted_array, 0); // Test with n=0
     if (index != -1) {
        printf("Found %d at index %d\n", 10, index);
    } else {
        printf("%d not found in empty array\n", 10); // Expected: 10 not found in empty array
    }


    return 0;
}
int binarysearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n -1;

	while(low < high)
	{
		mid = (low + high) /2;
		if(x <= v[mid]) high = mid;
		else low = mid+1;
	}

	if(x== v[low]) return low;
	else return -1;
}

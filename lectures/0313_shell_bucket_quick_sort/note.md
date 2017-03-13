03/13/2017 - Monday

# Sorting Algorithms

## Shell Sort

* **Complexity**: O(log(n)n²)
* Apply Insertion Sort with a gap of n/(2^i) positions between one element and another
* Created by Donald Shell (1959)
* Most efficient quadratic complexity sorting algorithm

```Java
public static void shellSort(Integer[] nums) {
	int n = nums.length;
	int h = n / 2;
	int c, j;
	while(h > 0) {
		for(int i = h; i < n; i++) {
			c = nums[i];
			j = i;
			while (j >= h && nums[j - h] > c) {
				nums[j] = nums[j - h];
				j = j - h;
			}
			nums[j] = c;
		}
		h = h / 2;
	}
}
```

**Example**:

> **Array**: 8 7 6 5 4 3 2 1

> **Step 1**: [_h = 4_] 4 3 2 1 8 7 6 5

> **Step 2**: [_h = 2_] 2 1 4 3 6 5 8 7

> **Step 3**: [_h = 1_] 1 2 3 4 5 6 7 8

## Bucket Sort

* Based on divide and conquest
* Divide an array in a finite quantity of buckets
* Each bucket is sorted individually by different algorithms or using the bucket sort recursively
* Is better efficient in limited values of data (Example: age)

## Quick sort

* Based on divide and conquest by partition
* To partition an array, choose an element (pivot) and move all the lesser values to the left and all the greater values to the right
* Complexity can be O(n) and locale (without creating new variables)
* Order recursively the lesser and greater values
* Complex to implement and unstable
* It is one of the faster of the algorithms in practice
* With its reduced usage of space, complexity is O(log(n))
* It is one of the most popular algorithms, available in many standard libraries
* The biggest problem is to find a good pivot, bad choices can change the complexity to O(n²)
* To find a median is O(n), changing the complexity to O(nlog(n))

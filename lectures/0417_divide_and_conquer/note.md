04/17/2017 - Monday

# Divide and Conquer

*	Break up problem into several parts
* Solve each part recursively
* Combine solutions to sub-problems into overall solution

## Most Common Usage

* Break up problem of size `n` into two equal parts of size `n/2`
* Solve two parts recursively
* Combine two solutions into overall solution in linear time

## Consequence

* Brute force: `n²`
* Divide and Conquer: `n log(n)`

# Sorting

* Given `n` elements, rearrange in ascending order

## Merge Sort

* Divide array into two halves
* Recursively sort each half
* Merge two halves to make sorted whole

### Merging

* Combine tow pre-sorted lists into a sorted whole
* How to merge efficiently:
	* Linear number of comparisons
	* Use temporary array
* Challenge for the bored: In-place merge [Kronrud, 1969]

# Counting Inversions

* Music site tries to match your song preferences with others
	* You rank `n` songs
	* Music site consults database to find people with similar tastes

* Similarity metric: Number of inversions between two rankings
	* My rank: `1, 2, ..., n`
	* Your rank: `a1, a2, ..., an`
	* Songs `i` and `j` inverted if `i < j`, but `ai > aj`

* Me: 1, 2, 3, 4, 5
* You: 1, 3, 4, 2, 5
* Inversions: 3-2, 4-2

* Brute force: check all pairs `i` and `j` (`n²`)

* Applications
	* Voting theory
	* Collaborative filtering
	* Measuring the sortedness of an array
	* Sensitivity analysis of Google's ranking function
	* Rank aggregation for meta-searching on the Web
	* Nonparametric statistics (Kendall's Tau Distance)

* Divide and conquer:
	* `1,5,4,8,10,2,6,9,12,11,3,7`
		* Divide: Separate list into two pieces
	* `1,5,4,8,10,2` / `6,9,12,11,3,7`
		* Conquer: Recursively count inversions in each half
	* `5 = 5-4, 5-2, 4-2, 8-2, 10-2` / `8 = 6-3, 9-3, 9-7, 12-3, 12-7, 12-11, 11-3, 11-7`
		* Combine: Count inversions where `ai` and `aj` are in different halves, and return sum of three quantities
		* What happens if each half is sorted?
	* `1,2,4,5,8,10` / `3,6,7,9,11,12`
	* `9 = 4-3, 5-3, 8-3, 10-3, 8-6, 10-6, 8-7, 10-7, 10-9`

* Optimization:
	* `4,3,2,1`
	* `4,3` / `2,1`
	* `4(0)` / `3(0)` / `2(0)` / `1(0)`
	* `3,4(0+0+1=1)` / `1,2(0+0+1=1)`
	* `1,2,3,4(1+1+4=6)`

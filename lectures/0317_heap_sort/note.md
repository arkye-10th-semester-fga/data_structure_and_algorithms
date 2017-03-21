03/17/2017 - Friday (Missed Class)

# Heap Sort

* Heap Criteria:
	* Binary Tree (Each node has 2 child)
	* The root must be the biggest value, the order of the child values doesn't matter
	* Every hole of the tree must be on the last level, at the right node
* No run on the tree go in an ordered form, although the structured order
	* This turn impossible the optimized search on the tree
* Only removes the root, the other elements can't be removed
* Ideal to maintain a priority stack

* 25
	* 13
		* 5
		* 8
	* 17
		* 3

* `[0[25,|13,17|5,8,3]]`
	* The `0` portion can store the number of array elements
	* Representation of the the tree in a level ordered array

* In order to discover the father of a node:
	1. Get the child position, divide by 2, floor rounded

* In order to insert an element `log(n)`:
	1. Set the element at the last level, first hole
	1. Recursively compare the child element with the father element, until it be lesser than the root

* Maximum number of levels: `log(n)`

* In order to remove:
	1. Swap the root with the last element
	1. Remove
	1. Recursively compare the new root with its child, swap with the biggest of its child if it is lesser. (Heapfile)

* Building a Heap:
	* Create an auxiliary vector in order to perform the sorting
	* Order the array, resulting in a Heap
	* Half of the tree will be always in the last level
		* Divide the tree in the half in order to work with the elements non-leaf.
		* Considerate the leaves as ready heaps and adjust only the elements, because in that way, in the worst case, the process turns linear and the number of operations that he must to do will be a little more than the half of the number of elements

* Heap Sort: Shift down

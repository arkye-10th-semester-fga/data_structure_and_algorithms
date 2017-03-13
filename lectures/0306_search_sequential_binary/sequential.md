# Standard Algorithm

```C
// Search x in array A with size n
for(i=0; i<n; i++)
	if(A[i] == x) return i;
return -1;
```

# Sentinel Variant

```C
// Search x in array A with size n
A[n-1] = x;
for(i=0; A[i]!=x; i++);
if (i < n-1) return x;
else return -1;
```

# Frequent Registry Recover

## Move-Forward

Move to head if registry found

## Transposition

Swap position with the previous registry if found

### Transposition Variant

Swap position with the `current - rand(n)` registry if found

# Indexed

Must be sorted

## Table of Indexes (and secondary table of indexes)

1. Array of 10000 elements
1. Create a table of indexes with size `10000/100 = 100`
1. Copy 100 indexes with position `i*100` from the original array to the table of indexes
1. Create a secondary table of indexes with size `100/10 = 10`
1. Copy 10 index with position `i*10` from the firt table of indexes to the second table of indexes

## Issues

* Inserting
	* Rearrange elements and recreate table of indexes
	* Create a second array of _new_ elements
* Deleting
	* Rearrange elements and recreate table of indexes
	* Flag the element as deleted

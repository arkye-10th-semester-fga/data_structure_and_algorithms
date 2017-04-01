#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "input.h"
#include "list_creator.h"

#define BILLION 1000000000
#define PRIMARY_INDEX_RATIO 10
#define NOT_FOUND -1

using namespace std;

void create_primary_index_table(vector<long long> &primary_indexes,
	vector<long long> &sorted_elements);

int find_primary_index(vector<long long> &primary_indexes,
	long long search_value);

int sequential_search(vector<long long> &sorted_elements,
	long long search_value, int initial_index);

int main(int argc, char* argv[])
{
	// Check Arguments Quantity
	if(!has_four_arguments(argc))
	{
		inform_number_of_elements_pattern();
		inform_sorted_insertion_pattern();
		inform_search_value_pattern();
		inform_stress_loop_pattern();
		exit(EXIT_FAILURE);
	}

	// Create Sorted List
	int quantity_of_elements = atoi(argv[1]);
	vector<long long> sorted_elements;
	if(!create_sorted_list(sorted_elements, quantity_of_elements))
	{
		inform_number_of_elements_pattern();
		inform_sorted_insertion_pattern();
		exit(EXIT_FAILURE);
	}

	// Verify Search Value
	long long search_value = atoll(argv[2]);
	if(search_value < 1 || search_value > BILLION)
	{
		inform_search_value_pattern();
		exit(EXIT_FAILURE);
	}

	// Create Primary Index Table
	vector<long long> primary_indexes;
	create_primary_index_table(primary_indexes, sorted_elements);

	// Verify Stress Count
	long long stress_count = atoll(argv[3]);
	if(stress_count < 1 || stress_count > BILLION)
	{
		inform_stress_loop_pattern();
		exit(EXIT_FAILURE);
	}

	// Perform Stress Loop
	int search_index = 0;
	while(stress_count > 0)
	{
		// Find Primary Index
		search_index = find_primary_index(primary_indexes, search_value);

		// Find Element
		search_index = sequential_search(sorted_elements,
			search_value, search_index);

		stress_count--;
	}

	// Inform Results
	if(search_index != NOT_FOUND)
	{
		printf("ELEMENT FOUND - Position: %d; Value: %lld\n",
			search_index+1, search_value);
	}
	else
	{
		printf("ELEMENT NOT FOUND\n");
	}

	return 0;
}

/*
 * Create Primary Index Table With n/10 elements from the sorted elements
 * I = l + l+10 + ... l+(10*(n-1)) + k
 * l = 1, k = last element of the sorted elements
 */
void create_primary_index_table(vector<long long> &primary_indexes,
	vector<long long> &sorted_elements)
{
	// Start with floor(n/10) elements
	int primary_index_size = sorted_elements.size()/PRIMARY_INDEX_RATIO;

	// Insert the first element
	primary_indexes.push_back(sorted_elements[0]);

	// Insert elements with 10*(n-1) indexes
	for(int i = 1; i <= primary_index_size; ++i)
	{
		primary_indexes.push_back(sorted_elements[(i*PRIMARY_INDEX_RATIO)-1]);
	}

	// If not divisible by 10, insert the last element
	if(sorted_elements.size() % PRIMARY_INDEX_RATIO != 0)
	{
		primary_indexes.push_back(sorted_elements[sorted_elements.size()-1]);
	}
}

/*
 * Find the primary index based on search value
 */
int find_primary_index(vector<long long> &primary_indexes,
	long long search_value)
{
	int index = 0;
	const int SIZE_OF_PRIMARY_INDEXES = primary_indexes.size();
	bool search_value_is_lesser_or_equals_element = false;

	// Search the minimum element greater or equals than the search value
	while(!search_value_is_lesser_or_equals_element
		&& index < SIZE_OF_PRIMARY_INDEXES)
	{
		if(search_value <= primary_indexes[index])
		{
			search_value_is_lesser_or_equals_element = true;
		}
		else
		{
			++index;
		}
	}

	// Correct the index
	if(index > 1)
	{
		if(index < SIZE_OF_PRIMARY_INDEXES-1)
		{
			// Primary index is between 2 ~ n
			// The first -1 is to get the previous index
			// The second -1 is to correct the index (which starts at 0)
			index = (index-1)*PRIMARY_INDEX_RATIO-1;
		}
		else
		{
			// Primary index is the last index
			// The -2 is to get the previous index with index correction
			// The -1 is to correct the index (which starts at 0)
			index = (SIZE_OF_PRIMARY_INDEXES-2)*PRIMARY_INDEX_RATIO-1;
		}
	}
	else
	{
		// Primary index is 0 or 1, index must be the first
		index = 0;
	}

	return index;
}


/*
 * Perform the Sequential Search, Initiating from the index
 * defined by the Primary Index Table
 */
int sequential_search(vector<long long> &sorted_elements,
	long long search_value, int initial_index)
{
	int index;
	const int SIZE_OF_SORTED_ELEMENTS = sorted_elements.size();

	// Search the value with start index defined by the primary index table
	for(index = initial_index; index < SIZE_OF_SORTED_ELEMENTS; ++index)
	{
		if(sorted_elements[index] == search_value)
		{
			// The value was found
			return index;
		}

		if(sorted_elements[index] > search_value)
		{
			// The element is bigger than the value,
			// so the value could not be found
			return NOT_FOUND;
		}
	}

	// The element was not found
	return NOT_FOUND;
}

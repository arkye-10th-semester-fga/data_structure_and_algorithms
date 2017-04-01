#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "input.h"
#include "list_creator.h"

#define BILLION 1000000000
#define NOT_FOUND -1

using namespace std;

int circular_binary_search(vector<long long> &circular_list,
	long long search_value);

int main(int argc, char* argv[])
{
	// Check Arguments Quantity
	if(!has_four_arguments(argc))
	{
		inform_number_of_elements_pattern();
		inform_circular_insertion_pattern();
		inform_search_value_pattern();
		inform_stress_loop_pattern();
		exit(EXIT_FAILURE);
	}

	// Create Circular List
	int quantity_of_elements = atoi(argv[1]);
	vector<long long> circular_list;
	if(!create_circular_list(circular_list, quantity_of_elements))
	{
		inform_number_of_elements_pattern();
		inform_circular_insertion_pattern();
		exit(1);
	}

	// Verify Search Value
	long long search_value = atoll(argv[2]);
	if(search_value < 1 || search_value > BILLION)
	{
		inform_search_value_pattern();
		exit(EXIT_FAILURE);
	}

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
		// Find Element
		search_index = circular_binary_search(circular_list, search_value);

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
 * Perform the Circular Binary Search
 * Inspired from: https://youtu.be/uufaK2uLnSI
 */
int circular_binary_search(vector<long long> &circular_list,
	long long search_value)
{
	int index = 0;

	unsigned int low_index = 0;
	unsigned int high_index = circular_list.size()-1;
	bool has_not_found = true;

	// Search the value
	while(low_index <= high_index && has_not_found)
	{
		// The element evaluated will always be the
		// half element between the lowest index and the highest index
		const int HALF_INDEX = (low_index + high_index) / 2;
		if(search_value == circular_list[HALF_INDEX])
		{
			// The half element has the same value than the search value
			index = HALF_INDEX;
			has_not_found = false;
		}
		else if(circular_list[HALF_INDEX] <= circular_list[high_index])
		{
			// The right half of the list is sorted with the half element
			if(search_value > circular_list[HALF_INDEX]
				&& search_value <= circular_list[high_index])
			{
				// The search value can only be in the right sorted half of the list
				low_index = HALF_INDEX+1;
			}
			else
			{
				// The search value can only be in the left half of the list
				high_index = HALF_INDEX-1;
			}
		}
		else
		{
			// The left half of the list is sorted with the half element
			if(search_value >= circular_list[low_index]
				&& search_value < circular_list[HALF_INDEX])
			{
				// The search value can only be in the left sorted half of the list
				high_index = HALF_INDEX-1;
			}
			else
			{
				// The search value can only be in the right half of the list
				low_index = HALF_INDEX+1;
			}
		}
	}

	// The search could not find the desired value
	if(has_not_found)
	{
		index = NOT_FOUND;
	}

	return index;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "io.h"
#include "list_creator.h"

#define BILLION 1000000000
#define NOT_FOUND -1

using namespace std;

int interpolation_search(vector<long long> &sorted_elements,
	long long search_value);

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

	// Verify Stress Count
	long long stress_count = atoll(argv[3]);
	if(stress_count < 1 || stress_count > BILLION)
	{
		inform_stress_loop_pattern();
		exit(EXIT_FAILURE);
	}

	// Perform Stress Loop
	int search_index = 0;
	clock_t start_time = clock();
	while(stress_count > 0)
	{
		// Find Element
		search_index = interpolation_search(sorted_elements, search_value);

		stress_count--;
	}
	clock_t end_time = clock();

	// Inform Results
	print_result(search_index, search_value);
	print_time(start_time, end_time);

	return 0;
}

/*
 * Perform the Interpolation Search
 */
int interpolation_search(vector<long long> &sorted_elements, long long search_value)
{
	int index = 0;

	unsigned int low_index = 0;
	unsigned int high_index = sorted_elements.size()-1;
	bool has_not_found = true;

	// Search the value
	while(low_index <= high_index && has_not_found)
	{
		// Interpolation Equation
		const int MID_INDEX = low_index +
			((high_index - low_index) *
				((search_value - sorted_elements[low_index])
					/ (sorted_elements[high_index] - sorted_elements[low_index])));

		if(search_value == sorted_elements[MID_INDEX])
		{
			// The half element has the same value than the search value
			index = MID_INDEX;
			has_not_found = false;
		}
		else if(search_value > sorted_elements[MID_INDEX])
		{
			// The search value should be in the right half of the list
			low_index = MID_INDEX + 1;
		}
		else
		{
			// The search value should be in the left half of the list
			high_index = MID_INDEX - 1;
		}
	}

	// The search could not find the desired value
	if(has_not_found)
	{
		index = NOT_FOUND;
	}

	return index;
}

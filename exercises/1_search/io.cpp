#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "io.h"

#define NOT_FOUND -1

using namespace std;

/*
 * Inform how the program expect to receive the number of elements
 */
void inform_number_of_elements_pattern()
{
	printf("<number_of_elements> must be between 10 and 1 000 000\n");
	printf("If you want to set your own elements,\n");
	printf("inform <number_of_elements> as 0.\n");
}

/*
 * Inform how the program expect to receive the sorted insertion of elements
 */
void inform_sorted_insertion_pattern()
{
	printf("Remember: a new element must be greater than 0 and lesser\n");
	printf("than the previous element.\n");
}

/*
 * Inform how the program expect to receive the circular insertion of elements
 */
void inform_circular_insertion_pattern()
{
	printf("Remember: a new element must be greater than 0 and, once a\n");
	printf("new element is lesser than the previous element, all the next\n");
	printf("new elements must be greater than the previous element and\n");
	printf("lesser than the highest element inserted.\n");
}

/*
 * Inform how the program expect to receive the search value
 */
void inform_search_value_pattern()
{
	printf("<search_value> must be between 1 and 1 000 000 000\n");
}

/*
 * Inform how the program expect to receive the stress loop value
 */
void inform_stress_loop_pattern()
{
	printf("<stress_loop> must be between 1 and 1 000 000 000\n");
	printf("Application will perform only one output, at the end of the stress loop\n");
}

/*
 * Check if the program was called with two arguments
 * First argument: program call
 * Second argument: number of elements
 */
bool has_four_arguments(int argc)
{
	bool has_four_arguments = true;
	if(argc != 4)
	{
		printf("Input Expected: ./<program_name> <number_of_elements> <search_value> <stress_loop>\n");
		has_four_arguments = false;
	}
	return has_four_arguments;
}

/*
 * Inform the search result to the user
 */
void print_result(int search_index, long long search_value)
{
	if(search_index != NOT_FOUND)
	{
		printf("Element \"%lld\" found at position \"%d\"!\n", search_value, search_index+1);
	}
	else
	{
		printf("Element \"%lld\" NOT found!\n", search_value);
	}
}

/*
 * Inform the time elapsed from the start of the stress loop until its end
 */
void print_time(clock_t start_time, clock_t end_time)
{
	printf("Time on Stress Loop: %lf s\n", (double) (end_time - start_time)/CLOCKS_PER_SEC);
}

#include <stdlib.h>
#include <stdio.h>
#include "input.h"

using namespace std;

/*
 * Inform how the program expect to receive the number of elements
 */
void inform_number_of_elements_pattern()
{
	printf("<number_of_elements> must be between 10 and 1 000 000\n");
	printf("If you want to set your own elements,\n");
	printf("inform <number_of_elements> as 0. Remember:\n");
	printf("a new element must be greater than 0 and lesser \n");
	printf("than the previous element\n");
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
		inform_number_of_elements_pattern();
		inform_search_value_pattern();
		inform_stress_loop_pattern();
		has_four_arguments = false;
	}
	return has_four_arguments;
}

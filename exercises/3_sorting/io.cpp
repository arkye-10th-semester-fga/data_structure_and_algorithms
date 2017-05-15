#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "io.h"

#define NOT_FOUND -1

using namespace std;

/*
 * Inform how the program expect to be executed
 */
void inform_execution_pattern()
{
	printf("Input Expected: ./<program_name> <quantity_of_elements> <seed_value>\n");
}

/*
 * Inform how the program expect to receive the quantity of elements
 */
void inform_quantity_of_elements_pattern()
{
	printf("<quantity_of_elements> must be between 2 and 1 000 000\n");
}

/*
 * Inform how the program expect to receive the seed value
 */
void inform_seed_pattern()
{
	printf("<seed_value> must be between 1 and 1 000 000\n");
	printf("If you want to set your own elements,\n");
	printf("inform <seed_value> as 0.\n");
}

/*
 * Inform how the program expect to receive a new element
 */
void inform_insertion_pattern()
{
	printf("A new element must be between 2 and 999\n");
}

/*
 * Print a list with a name
 */
void print_list(const char *list_name, vector<int> &elements)
{
	printf("%s:\n\t", list_name);
	int page = 1;
	for(int element : elements)
	{
		printf("[%03d] ", element);
		if(page < 10)
		{
			page++;
		}
		else
		{
			page = 0;
			printf("\n\t");
		}
	}
	printf("\n");
}

/*
 * Print step
 */
void print_step(char description[100], const char* step_name, vector<int> &elements,
	vector<int>::iterator start, vector<int>::iterator finish)
{
	sprintf(description, "%s %ld->%ld", step_name, distance(elements.begin(), start),
		distance(elements.begin(), finish));
	printf("%s:\n\t", description);

	int page = 1;

	for(vector<int>::iterator index = elements.begin();
		index != start; ++index)
	{
		printf("[---] ");
		if(page < 10)
		{
			page++;
		}
		else
		{
			page = 0;
			printf("\n\t");
		}
	}

	for(vector<int>::iterator index = start;
		index != finish; ++index)
	{
		printf("[%03d] ", *index);
		if(page < 10)
		{
			page++;
		}
		else
		{
			page = 0;
			printf("\n\t");
		}
	}

	for(vector<int>::iterator index = finish;
		index != elements.end(); ++index)
	{
		printf("[---] ");
		if(page < 10)
		{
			page++;
		}
		else
		{
			page = 0;
			printf("\n\t");
		}
	}

	printf("\n");
}

void print_rule()
{
	printf("====================================\n");
}

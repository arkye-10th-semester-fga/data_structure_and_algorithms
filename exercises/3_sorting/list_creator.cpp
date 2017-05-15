#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "io.h"
#include "list_creator.h"

#define MILLION 1000000

#define MINIMUM_ELEMENTS 2
#define MAXIMUM_ELEMENTS MILLION

#define MINIMUM_SEED 1
#define MAXIMUM_SEED MILLION

#define MINIMUM_VALUE 1
#define MAXIMUM_VALUE 999

#define USER_CHOICE 0

using namespace std;

/*
 * Create List
 * If seed equals 0, user will insert the elements
 */
bool create_list(vector<int> &elements,
	int quantity_of_elements, int seed)
{
	bool is_creation_successful = true;

	if(seed == USER_CHOICE)
	{
		// User chose to insert elements
		get_list_from_user(elements, quantity_of_elements);
	}
	else if(quantity_of_elements >= MINIMUM_ELEMENTS
		&& quantity_of_elements <= MAXIMUM_ELEMENTS
		&& seed >= MINIMUM_SEED && seed <= MAXIMUM_SEED)
	{
		// User chose to program create list
		create_unsorted_list(elements, quantity_of_elements, seed);
	}
	else
	{
		// Wrong input
		is_creation_successful = false;
		inform_execution_pattern();
		inform_quantity_of_elements_pattern();
		inform_seed_pattern();
	}

	return is_creation_successful;
}

/*
 * Get List from User
 * A new element must be greater than 0 and lesser than a billion
 */
void get_list_from_user(vector<int> &elements,
	int quantity_of_elements)
{
	for(int i = 0; i < quantity_of_elements; ++i)
	{
		int new_element;
		while(scanf("%d", &new_element) != 1
		 || new_element < MINIMUM_VALUE || new_element > MAXIMUM_VALUE)
		{
			inform_insertion_pattern();
		}
		elements.push_back(new_element);
	}
}

/*
 * Create Unsorted List defined by a seed
 */
void create_unsorted_list(vector<int> &elements,
	int quantity_of_elements, int seed)
{
	srand(seed);
	for(int i = 0; i < quantity_of_elements; ++i)
	{
		int element = rand()%MAXIMUM_VALUE+1;
		elements.push_back(element);
	}
}
